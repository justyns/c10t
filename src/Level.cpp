#include <assert.h>

#include "global.h"

#include "Level.h"
#include "blocks.h"

void begin_compound(void *context, nbt::String name) {
  if (name.compare("Level") == 0) {
    ((Level*)context)->islevel = true;
  }
}

void register_int(void *context, nbt::String name, nbt::Int i) {
  if (name.compare("xPos") == 0) {
    ((Level *)context)->xPos = i;
    return;
  }
  
  if (name.compare("zPos") == 0) {
    ((Level *)context)->zPos = i;
    return;
  }
}

void register_byte_array(void *context, nbt::String name, nbt::ByteArray *byte_array) {
  if (name.compare("Blocks") == 0) {
    ((Level *)context)->blocks = byte_array;
    return;
  }

  if (name.compare("SkyLight") == 0) {
    ((Level *)context)->skylight = byte_array;
    return;
  }

  if (name.compare("HeightMap") == 0) {
    ((Level *)context)->heightmap = byte_array;
    return;
  }

  if (name.compare("BlockLight") == 0) {
    ((Level *)context)->blocklight = byte_array;
    return;
  }
}

Level::~Level(){
  if (islevel) {
    delete blocks;
    delete skylight;
    delete heightmap;
    delete blocklight;
  }
}

Level::Level(const char *path) {
  xPos = 0;
  zPos = 0;
  islevel = false;
  
  nbt::Parser parser(this);
  parser.register_byte_array = register_byte_array;
  parser.register_int = register_int;
  parser.begin_compound = begin_compound;
  parser.parse_file(path);
  
  if (islevel) {
  }
}

/**
 * Blocks[ y + ( z * ChunkSizeY(=128) + ( x * ChunkSizeY(=128) * ChunkSizeZ(=16) ) ) ]; 
 */
nbt::Byte bget(nbt::ByteArray *blocks, int x, int y, int z) {
  assert(x >= 0 && x < mc::MapX);
  assert(y >= 0 && y < mc::MapY);
  assert(z >= 0 && z < mc::MapZ);
  int p = z + (y * mc::MapZ + (x * mc::MapZ * mc::MapY));
  assert (p >= 0 && p < blocks->length);
  return blocks->values[p];
}

nbt::Byte bsget(nbt::ByteArray *skylight, int x, int y, int z) {
  assert(x >= 0 && x < mc::MapX);
  assert(y >= 0 && y < mc::MapY);
  assert(z >= 0 && z < mc::MapZ);
  int p = z + (y * mc::MapZ + (x * mc::MapZ * mc::MapY));
  int ap = p / 2;

  assert (ap >= 0 && ap < skylight->length);
  
  // force unsigned
  uint8_t bp = skylight->values[ap] & 0xff;
  
  if (p % 2 == 0) {
    return bp >> 4;
  }
  else {
    return bp & 0xf;
  }
}

void transform_xy(settings_t *s, int &x, int &y) {
  if (s->flip) {
    int t = x;
    x = y; 
    y = mc::MapY - t - 1;
  }
  
  if (s->invert) {
    y = mc::MapY - y - 1;
    x = mc::MapX - x - 1;
  }
}

Image *Level::get_image(settings_t *s) {
  Image *img = new Image(mc::MapX, mc::MapY);
  
  if (!islevel) {
    return img;
  }
  
  for (int y = 0; y < mc::MapY; y++) {
    for (int x = 0; x < mc::MapX; x++) {
      int _x = x, _y = y;
      transform_xy(s, _x, _y);

      Color base(255, 255, 255, 0);
      
      int bt = mc::Air;
      int z;
      
      // do incremental color fill until color is opaque
      for (z = s->top; z > s->bottom; z--) {
        bt = bget(blocks, _x, _y, z);
        
        if (s->excludes[bt]) {
          continue;
        }
        
        Color *bc = mc::MaterialColor[bt];
        base.underlay(bc);
        
        if (base.a == 0xff) {
          break;
        }
      }
      
      // check specific last block options
      switch (bt) {
        case mc::Dirt:
        case mc::Grass:
        case mc::Stone:
        case mc::Cobblestone:
          // do an color overlay for mapped height
          Color height(0, 0, 0, 0);
          height.a = (127 - z);
          base.overlay(height);
          break;
      }
      
      img->set_pixel(x, y, base);
    }
  }
  
  return img;
}

Image *Level::get_oblique_image(settings_t *s) {
  Image *img = new Image(mc::MapX, mc::MapY + mc::MapZ);
  
  if (!islevel) {
    return img;
  }

  // block type
  int bt;
  
  // block skylight
  int sl;
  
  // skylight modifier
  // alpha channel is calculated depending on skylight value
  Color slmod(255, 255, 255, 0);
  
  // height modifier
  // alpha channel is calculated depending on height
  Color heightmod(0, 0, 0, 0);
  
  for (int y = 0; y < mc::MapY; y++) {
    for (int x = 0; x < mc::MapX; x++) {
      for (int z = s->bottom; z < s->top; z++) {
        int _x = x, _y = y;
        transform_xy(s, _x, _y);
        bt = bget(blocks, _x, _y, z);
        
        if (s->excludes[bt]) {
          continue;
        }
        
        sl = bsget(skylight, _x, _y, z);
        
        heightmod.a = (127 - z);
        slmod.a = (sl * 0x2);
        
        Color top(mc::MaterialColor[bt]);
        top.overlay(heightmod);
        top.overlay(slmod);
        img->set_pixel(x, y + (mc::MapZ - z) - 1, top);
        
        Color side(mc::MaterialSideColor[bt]);
        side.overlay(slmod);
        img->set_pixel(x, y + (mc::MapZ - z), side);
      }
    }
  }
  
  return img;
}

Image *Level::get_obliqueangle_image(settings_t *s) {
  Image *img = new Image(mc::MapX * 2 + 1, mc::MapX + mc::MapZ + mc::MapY);
  
  if (!islevel) {
    return img;
  }

  // block type
  int bt;
  
  // block skylight
  int sl;
  
  // skylight modifier
  // alpha channel is calculated depending on skylight value
  Color slmod(255, 255, 255, 0);
  
  // height modifier
  // alpha channel is calculated depending on height
  Color heightmod(0, 0, 0, 0);
  
  for (int y = 0; y < mc::MapY; y++) {
    for (int z = s->bottom; z < s->top; z++) {
      for (int x = 0; x < mc::MapX; x++) {
        int _x = x, _y = y;
        transform_xy(s, _x, _y);
        
        bt = bget(blocks, _x, _y, z);
        
        if (s->excludes[bt]) {
          continue;
        }
    
        sl = bsget(skylight, _x, _y, z);
        
        heightmod.a = (127 - z);
        slmod.a = (sl * 0x2);
        
        Color top(mc::MaterialColor[bt]);
        top.overlay(heightmod);
        top.overlay(slmod);
        
        int _px = mc::MapX + x - y;
        int _py = mc::MapZ + x - z + y;
        
        img->set_pixel(_px, _py - 1, top);
        img->set_pixel(_px + 1, _py - 1, top);
        
        Color side(mc::MaterialSideColor[bt]);
        side.overlay(heightmod);
        side.overlay(slmod);
        img->set_pixel(_px, _py, side);
        img->set_pixel(_px + 1, _py, side);
      }
    }
  }
  
  return img;
}
