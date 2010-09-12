#include "blocks.h"

int mc::MaterialCount = 0x56;
int mc::MapX = 0x10;
int mc::MapY = 0x10;
int mc::MapZ = 0x80;

const char **mc::MaterialName;
Color **mc::MaterialColor;
Color **mc::MaterialSideColor;

void mc::initialize_constants() {
  mc::MaterialName = new const char*[mc::MaterialCount];
  mc::MaterialColor = new Color*[mc::MaterialCount];
  mc::MaterialSideColor = new Color*[mc::MaterialCount];

  mc::MaterialName[mc::Air] = "Air";
  mc::MaterialName[mc::Stone] = "Stone";
  mc::MaterialName[mc::Grass] = "Grass";
  mc::MaterialName[mc::Dirt] = "Dirt";
  mc::MaterialName[mc::Cobblestone] = "Cobblestone";
  mc::MaterialName[mc::Wood] = "Wood";
  mc::MaterialName[mc::Sapling] = "Sapling";
  mc::MaterialName[mc::Bedrock] = "Bedrock";
  mc::MaterialName[mc::Water] = "Water";
  mc::MaterialName[mc::StationaryWater] = "StationaryWater";
  mc::MaterialName[mc::Lava] = "Lava";
  mc::MaterialName[mc::StationaryLava] = "StationaryLava";
  mc::MaterialName[mc::Sand] = "Sand";
  mc::MaterialName[mc::Gravel] = "Gravel";
  mc::MaterialName[mc::GoldOre] = "GoldOre";
  mc::MaterialName[mc::IronOre] = "IronOre";
  mc::MaterialName[mc::CoalOre] = "CoalOre";
  mc::MaterialName[mc::Log] = "Log";
  mc::MaterialName[mc::Leaves] = "Leaves";
  mc::MaterialName[mc::Sponge] = "Sponge";
  mc::MaterialName[mc::Glass] = "Glass";
  mc::MaterialName[mc::RedCloth] = "RedCloth";
  mc::MaterialName[mc::OrangeCloth] = "OrangeCloth";
  mc::MaterialName[mc::YellowCloth] = "YellowCloth";
  mc::MaterialName[mc::LimeCloth] = "LimeCloth";
  mc::MaterialName[mc::GreenCloth] = "GreenCloth";
  mc::MaterialName[mc::AquaGreenCloth] = "AquaGreenCloth";
  mc::MaterialName[mc::CyanCloth] = "CyanCloth";
  mc::MaterialName[mc::BlueCloth] = "BlueCloth";
  mc::MaterialName[mc::PurpleCloth] = "PurpleCloth";
  mc::MaterialName[mc::IndigoCloth] = "IndigoCloth";
  mc::MaterialName[mc::VioletCloth] = "VioletCloth";
  mc::MaterialName[mc::MagentaCloth] = "MagentaCloth";
  mc::MaterialName[mc::PinkCloth] = "PinkCloth";
  mc::MaterialName[mc::BlackCloth] = "BlackCloth";
  mc::MaterialName[mc::GrayCloth] = "GrayCloth";
  mc::MaterialName[mc::WhiteCloth] = "WhiteCloth";
  mc::MaterialName[mc::YellowFlower] = "YellowFlower";
  mc::MaterialName[mc::RedRose] = "RedRose";
  mc::MaterialName[mc::BrownMushroom] = "BrownMushroom";
  mc::MaterialName[mc::RedMushroom] = "RedMushroom";
  mc::MaterialName[mc::GoldBlock] = "GoldBlock";
  mc::MaterialName[mc::IronBlock] = "IronBlock";
  mc::MaterialName[mc::DoubleStep] = "DoubleStep";
  mc::MaterialName[mc::Step] = "Step";
  mc::MaterialName[mc::Brick] = "Brick";
  mc::MaterialName[mc::TNT] = "TNT";
  mc::MaterialName[mc::Bookcase] = "Bookcase";
  mc::MaterialName[mc::MossyCobblestone] = "MossyCobblestone";
  mc::MaterialName[mc::Obsidian] = "Obsidian";
  mc::MaterialName[mc::Torch] = "Torch";
  mc::MaterialName[mc::Fire] = "Fire";
  mc::MaterialName[mc::MobSpawner] = "MobSpawner";
  mc::MaterialName[mc::WoodenStairs] = "WoodenStairs";
  mc::MaterialName[mc::Chest] = "Chest";
  mc::MaterialName[mc::RedstoneWire] = "RedstoneWire";
  mc::MaterialName[mc::DiamondOre] = "DiamondOre";
  mc::MaterialName[mc::DiamondBlock] = "DiamondBlock";
  mc::MaterialName[mc::Workbench] = "Workbench";
  mc::MaterialName[mc::Crops] = "Crops";
  mc::MaterialName[mc::Soil] = "Soil";
  mc::MaterialName[mc::Furnace] = "Furnace";
  mc::MaterialName[mc::BurningFurnace] = "BurningFurnace";
  mc::MaterialName[mc::SignPost] = "SignPost";
  mc::MaterialName[mc::WoodenDoor] = "WoodenDoor";
  mc::MaterialName[mc::Ladder] = "Ladder";
  mc::MaterialName[mc::MinecartTracks] = "MinecartTracks";
  mc::MaterialName[mc::CobblestoneStairs] = "CobblestoneStairs";
  mc::MaterialName[mc::WallSign] = "WallSign";
  mc::MaterialName[mc::Lever] = "Lever";
  mc::MaterialName[mc::StonePressurePlate] = "StonePressurePlate";
  mc::MaterialName[mc::IronDoor] = "IronDoor";
  mc::MaterialName[mc::WoodenPressurePlate] = "WoodenPressurePlate";
  mc::MaterialName[mc::RedstoneOre] = "RedstoneOre";
  mc::MaterialName[mc::GlowingRedstoneOre] = "GlowingRedstoneOre";
  mc::MaterialName[mc::RedstoneTorchOff] = "RedstoneTorchOff";
  mc::MaterialName[mc::RedstoneTorchOn] = "RedstoneTorchOn";
  mc::MaterialName[mc::StoneButton] = "StoneButton";
  mc::MaterialName[mc::Snow] = "Snow";
  mc::MaterialName[mc::Ice] = "Ice";
  mc::MaterialName[mc::SnowBlock] = "SnowBlock";
  mc::MaterialName[mc::Cactus] = "Cactus";
  mc::MaterialName[mc::Clay] = "Clay";
  mc::MaterialName[mc::Reed] = "Reed";
  mc::MaterialName[mc::Jukebox] = "Jukebox";
  mc::MaterialName[mc::Fence] = "Fence";

  mc::MaterialColor[mc::Air] = new Color(255,255,255,0);
  mc::MaterialColor[mc::Stone] = new Color(120,120,120,255);
  mc::MaterialColor[mc::Grass] = new Color(117,176,73,255);
  mc::MaterialColor[mc::Dirt] = new Color(134,96,67,255);
  mc::MaterialColor[mc::Cobblestone] = new Color(115,115,115,255);
  mc::MaterialColor[mc::Wood] = new Color(157,128,79,255);
  mc::MaterialColor[mc::Sapling] = new Color(120,120,120,0);
  mc::MaterialColor[mc::Bedrock] = new Color(84,84,84,255);
  mc::MaterialColor[mc::Water] = new Color(38,92,255,80);
  mc::MaterialColor[mc::StationaryWater] = new Color(38,92,255,80);
  mc::MaterialColor[mc::Lava] = new Color(255,90,0,255);
  mc::MaterialColor[mc::StationaryLava] = new Color(255,90,0,255);
  mc::MaterialColor[mc::Sand] = new Color(218,210,158,255);
  mc::MaterialColor[mc::Gravel] = new Color(136,126,126,255);
  mc::MaterialColor[mc::GoldOre] = new Color(143,140,125,255);
  mc::MaterialColor[mc::IronOre] = new Color(136,130,127,255);
  mc::MaterialColor[mc::CoalOre] = new Color(115,115,115,255);
  mc::MaterialColor[mc::Log] = new Color(102,81,51,255);
  mc::MaterialColor[mc::Leaves] = new Color(60,192,41,100);
  mc::MaterialColor[mc::Sponge] = new Color();
  mc::MaterialColor[mc::Glass] = new Color(255,255,255,64);
  mc::MaterialColor[mc::RedCloth] = new Color();
  mc::MaterialColor[mc::OrangeCloth] = new Color();
  mc::MaterialColor[mc::YellowCloth] = new Color();
  mc::MaterialColor[mc::LimeCloth] = new Color();
  mc::MaterialColor[mc::GreenCloth] = new Color();
  mc::MaterialColor[mc::AquaGreenCloth] = new Color();
  mc::MaterialColor[mc::CyanCloth] = new Color();
  mc::MaterialColor[mc::BlueCloth] = new Color();
  mc::MaterialColor[mc::PurpleCloth] = new Color();
  mc::MaterialColor[mc::IndigoCloth] = new Color();
  mc::MaterialColor[mc::VioletCloth] = new Color();
  mc::MaterialColor[mc::MagentaCloth] = new Color();
  mc::MaterialColor[mc::PinkCloth] = new Color();
  mc::MaterialColor[mc::BlackCloth] = new Color();
  mc::MaterialColor[mc::GrayCloth] = new Color();
  mc::MaterialColor[mc::WhiteCloth] = new Color();
  mc::MaterialColor[mc::YellowFlower] = new Color(255,255,0,255);
  mc::MaterialColor[mc::RedRose] = new Color(255,0,0,255);
  mc::MaterialColor[mc::BrownMushroom] = new Color();
  mc::MaterialColor[mc::RedMushroom] = new Color();
  mc::MaterialColor[mc::GoldBlock] = new Color();
  mc::MaterialColor[mc::IronBlock] = new Color();
  mc::MaterialColor[mc::DoubleStep] = new Color(200,200,200,255);
  mc::MaterialColor[mc::Step] = new Color(200,200,200,255);
  mc::MaterialColor[mc::Brick] = new Color();
  mc::MaterialColor[mc::TNT] = new Color();
  mc::MaterialColor[mc::Bookcase] = new Color();
  mc::MaterialColor[mc::MossyCobblestone] = new Color();
  mc::MaterialColor[mc::Obsidian] = new Color();
  mc::MaterialColor[mc::Torch] = new Color(245,220,50,200);
  mc::MaterialColor[mc::Fire] = new Color();
  mc::MaterialColor[mc::MobSpawner] = new Color();
  mc::MaterialColor[mc::WoodenStairs] = new Color();
  mc::MaterialColor[mc::Chest] = new Color();
  mc::MaterialColor[mc::RedstoneWire] = new Color();
  mc::MaterialColor[mc::DiamondOre] = new Color(129,140,143,255);
  mc::MaterialColor[mc::DiamondBlock] = new Color(45,166,152,255);
  mc::MaterialColor[mc::Workbench] = new Color();
  mc::MaterialColor[mc::Crops] = new Color();
  mc::MaterialColor[mc::Soil] = new Color();
  mc::MaterialColor[mc::Furnace] = new Color();
  mc::MaterialColor[mc::BurningFurnace] = new Color();
  mc::MaterialColor[mc::SignPost] = new Color();
  mc::MaterialColor[mc::WoodenDoor] = new Color();
  mc::MaterialColor[mc::Ladder] = new Color();
  mc::MaterialColor[mc::MinecartTracks] = new Color(120, 120, 120, 128);
  mc::MaterialColor[mc::CobblestoneStairs] = new Color(120, 120, 120, 128);
  mc::MaterialColor[mc::WallSign] = new Color();
  mc::MaterialColor[mc::Lever] = new Color();
  mc::MaterialColor[mc::StonePressurePlate] = new Color();
  mc::MaterialColor[mc::IronDoor] = new Color();
  mc::MaterialColor[mc::WoodenPressurePlate] = new Color();
  mc::MaterialColor[mc::RedstoneOre] = new Color();
  mc::MaterialColor[mc::GlowingRedstoneOre] = new Color();
  mc::MaterialColor[mc::RedstoneTorchOff] = new Color(181,140,64,32);
  mc::MaterialColor[mc::RedstoneTorchOn] = new Color(255,0,0,200);
  mc::MaterialColor[mc::StoneButton] = new Color();
  mc::MaterialColor[mc::Snow] = new Color(255, 255, 255, 255);
  mc::MaterialColor[mc::Ice] = new Color(120, 120, 255, 120);
  mc::MaterialColor[mc::SnowBlock] = new Color(255, 255, 255, 255);
  mc::MaterialColor[mc::Cactus] = new Color(64, 255, 64, 255);
  mc::MaterialColor[mc::Clay] = new Color();
  mc::MaterialColor[mc::Reed] = new Color(193,234,150,255);
  mc::MaterialColor[mc::Jukebox] = new Color();
  mc::MaterialColor[mc::Fence] = new Color(0x58, 0x36, 0x16, 200);
  
  mc::MaterialSideColor[mc::Air] = new Color(mc::MaterialColor[mc::Air]);
  mc::MaterialSideColor[mc::Stone] = new Color(mc::MaterialColor[mc::Stone]);
  mc::MaterialSideColor[mc::Grass] = new Color(mc::MaterialColor[mc::Dirt]);
  mc::MaterialSideColor[mc::Dirt] = new Color(mc::MaterialColor[mc::Dirt]);
  mc::MaterialSideColor[mc::Cobblestone] = new Color(mc::MaterialColor[mc::Cobblestone]);
  mc::MaterialSideColor[mc::Wood] = new Color(mc::MaterialColor[mc::Wood]);
  mc::MaterialSideColor[mc::Sapling] = new Color(mc::MaterialColor[mc::Sapling]);
  mc::MaterialSideColor[mc::Bedrock] = new Color(mc::MaterialColor[mc::Bedrock]);
  mc::MaterialSideColor[mc::Water] = new Color(mc::MaterialColor[mc::Water]);
  mc::MaterialSideColor[mc::StationaryWater] = new Color(mc::MaterialColor[mc::StationaryWater]);
  mc::MaterialSideColor[mc::Lava] = new Color(mc::MaterialColor[mc::Lava]);
  mc::MaterialSideColor[mc::StationaryLava] = new Color(mc::MaterialColor[mc::StationaryLava]);
  mc::MaterialSideColor[mc::Sand] = new Color(mc::MaterialColor[mc::Sand]);
  mc::MaterialSideColor[mc::Gravel] = new Color(mc::MaterialColor[mc::Gravel]);
  mc::MaterialSideColor[mc::GoldOre] = new Color(mc::MaterialColor[mc::GoldOre]);
  mc::MaterialSideColor[mc::IronOre] = new Color(mc::MaterialColor[mc::IronOre]);
  mc::MaterialSideColor[mc::CoalOre] = new Color(mc::MaterialColor[mc::CoalOre]);
  mc::MaterialSideColor[mc::Log] = new Color(mc::MaterialColor[mc::Log]);
  mc::MaterialSideColor[mc::Leaves] = new Color(mc::MaterialColor[mc::Leaves]);
  mc::MaterialSideColor[mc::Sponge] = new Color(mc::MaterialColor[mc::Sponge]);
  mc::MaterialSideColor[mc::Glass] = new Color(mc::MaterialColor[mc::Glass]);
  mc::MaterialSideColor[mc::RedCloth] = new Color(mc::MaterialColor[mc::RedCloth]);
  mc::MaterialSideColor[mc::OrangeCloth] = new Color(mc::MaterialColor[mc::OrangeCloth]);
  mc::MaterialSideColor[mc::YellowCloth] = new Color(mc::MaterialColor[mc::YellowCloth]);
  mc::MaterialSideColor[mc::LimeCloth] = new Color(mc::MaterialColor[mc::LimeCloth]);
  mc::MaterialSideColor[mc::GreenCloth] = new Color(mc::MaterialColor[mc::GreenCloth]);
  mc::MaterialSideColor[mc::AquaGreenCloth] = new Color(mc::MaterialColor[mc::AquaGreenCloth]);
  mc::MaterialSideColor[mc::CyanCloth] = new Color(mc::MaterialColor[mc::CyanCloth]);
  mc::MaterialSideColor[mc::BlueCloth] = new Color(mc::MaterialColor[mc::BlueCloth]);
  mc::MaterialSideColor[mc::PurpleCloth] = new Color(mc::MaterialColor[mc::PurpleCloth]);
  mc::MaterialSideColor[mc::IndigoCloth] = new Color(mc::MaterialColor[mc::IndigoCloth]);
  mc::MaterialSideColor[mc::VioletCloth] = new Color(mc::MaterialColor[mc::VioletCloth]);
  mc::MaterialSideColor[mc::MagentaCloth] = new Color(mc::MaterialColor[mc::MagentaCloth]);
  mc::MaterialSideColor[mc::PinkCloth] = new Color(mc::MaterialColor[mc::PinkCloth]);
  mc::MaterialSideColor[mc::BlackCloth] = new Color(mc::MaterialColor[mc::BlackCloth]);
  mc::MaterialSideColor[mc::GrayCloth] = new Color(mc::MaterialColor[mc::GrayCloth]);
  mc::MaterialSideColor[mc::WhiteCloth] = new Color(mc::MaterialColor[mc::WhiteCloth]);
  mc::MaterialSideColor[mc::YellowFlower] = new Color(mc::MaterialColor[mc::YellowFlower]);
  mc::MaterialSideColor[mc::RedRose] = new Color(mc::MaterialColor[mc::RedRose]);
  mc::MaterialSideColor[mc::BrownMushroom] = new Color(mc::MaterialColor[mc::BrownMushroom]);
  mc::MaterialSideColor[mc::RedMushroom] = new Color(mc::MaterialColor[mc::RedMushroom]);
  mc::MaterialSideColor[mc::GoldBlock] = new Color(mc::MaterialColor[mc::GoldBlock]);
  mc::MaterialSideColor[mc::IronBlock] = new Color(mc::MaterialColor[mc::IronBlock]);
  mc::MaterialSideColor[mc::DoubleStep] = new Color(mc::MaterialColor[mc::DoubleStep]);
  mc::MaterialSideColor[mc::Step] = new Color(mc::MaterialColor[mc::Step]);
  mc::MaterialSideColor[mc::Brick] = new Color(mc::MaterialColor[mc::Brick]);
  mc::MaterialSideColor[mc::TNT] = new Color(mc::MaterialColor[mc::TNT]);
  mc::MaterialSideColor[mc::Bookcase] = new Color(mc::MaterialColor[mc::Bookcase]);
  mc::MaterialSideColor[mc::MossyCobblestone] = new Color(mc::MaterialColor[mc::MossyCobblestone]);
  mc::MaterialSideColor[mc::Obsidian] = new Color(mc::MaterialColor[mc::Obsidian]);
  mc::MaterialSideColor[mc::Torch] = new Color(mc::MaterialColor[mc::Torch]);
  mc::MaterialSideColor[mc::Fire] = new Color(mc::MaterialColor[mc::Fire]);
  mc::MaterialSideColor[mc::MobSpawner] = new Color(mc::MaterialColor[mc::MobSpawner]);
  mc::MaterialSideColor[mc::WoodenStairs] = new Color(mc::MaterialColor[mc::WoodenStairs]);
  mc::MaterialSideColor[mc::Chest] = new Color(mc::MaterialColor[mc::Chest]);
  mc::MaterialSideColor[mc::RedstoneWire] = new Color(mc::MaterialColor[mc::RedstoneWire]);
  mc::MaterialSideColor[mc::DiamondOre] = new Color(mc::MaterialColor[mc::DiamondOre]);
  mc::MaterialSideColor[mc::DiamondBlock] = new Color(mc::MaterialColor[mc::DiamondBlock]);
  mc::MaterialSideColor[mc::Workbench] = new Color(mc::MaterialColor[mc::Workbench]);
  mc::MaterialSideColor[mc::Crops] = new Color(mc::MaterialColor[mc::Crops]);
  mc::MaterialSideColor[mc::Soil] = new Color(mc::MaterialColor[mc::Soil]);
  mc::MaterialSideColor[mc::Furnace] = new Color(mc::MaterialColor[mc::Furnace]);
  mc::MaterialSideColor[mc::BurningFurnace] = new Color(mc::MaterialColor[mc::BurningFurnace]);
  mc::MaterialSideColor[mc::SignPost] = new Color(mc::MaterialColor[mc::SignPost]);
  mc::MaterialSideColor[mc::WoodenDoor] = new Color(mc::MaterialColor[mc::WoodenDoor]);
  mc::MaterialSideColor[mc::Ladder] = new Color(mc::MaterialColor[mc::Ladder]);
  mc::MaterialSideColor[mc::MinecartTracks] = new Color(mc::MaterialColor[mc::MinecartTracks]);
  mc::MaterialSideColor[mc::CobblestoneStairs] = new Color(mc::MaterialColor[mc::CobblestoneStairs]);
  mc::MaterialSideColor[mc::WallSign] = new Color(mc::MaterialColor[mc::WallSign]);
  mc::MaterialSideColor[mc::Lever] = new Color(mc::MaterialColor[mc::Lever]);
  mc::MaterialSideColor[mc::StonePressurePlate] = new Color(mc::MaterialColor[mc::StonePressurePlate]);
  mc::MaterialSideColor[mc::IronDoor] = new Color(mc::MaterialColor[mc::IronDoor]);
  mc::MaterialSideColor[mc::WoodenPressurePlate] = new Color(mc::MaterialColor[mc::WoodenPressurePlate]);
  mc::MaterialSideColor[mc::RedstoneOre] = new Color(mc::MaterialColor[mc::RedstoneOre]);
  mc::MaterialSideColor[mc::GlowingRedstoneOre] = new Color(mc::MaterialColor[mc::GlowingRedstoneOre]);
  mc::MaterialSideColor[mc::RedstoneTorchOff] = new Color(mc::MaterialColor[mc::RedstoneTorchOff]);
  mc::MaterialSideColor[mc::RedstoneTorchOn] = new Color(mc::MaterialColor[mc::RedstoneTorchOn]);
  mc::MaterialSideColor[mc::StoneButton] = new Color(mc::MaterialColor[mc::StoneButton]);
  mc::MaterialSideColor[mc::Snow] = new Color(mc::MaterialColor[mc::Snow]);
  mc::MaterialSideColor[mc::Ice] = new Color(mc::MaterialColor[mc::Ice]);
  mc::MaterialSideColor[mc::SnowBlock] = new Color(mc::MaterialColor[mc::SnowBlock]);
  mc::MaterialSideColor[mc::Cactus] = new Color(mc::MaterialColor[mc::Cactus]);
  mc::MaterialSideColor[mc::Clay] = new Color(mc::MaterialColor[mc::Clay]);
  mc::MaterialSideColor[mc::Reed] = new Color(mc::MaterialColor[mc::Reed]);
  mc::MaterialSideColor[mc::Jukebox] = new Color(mc::MaterialColor[mc::Jukebox]);
  mc::MaterialSideColor[mc::Fence] = new Color(mc::MaterialColor[mc::Fence]);

  Color dark(0, 0, 0, 80);
  
  for (int i = 0; i < mc::MaterialCount; i++) {
    mc::MaterialSideColor[i]->overlay(&dark);
  }
  
  mc::MaterialSideColor[mc::Air] = mc::MaterialColor[mc::Air];
  mc::MaterialSideColor[mc::Water] = mc::MaterialColor[mc::Water];
  mc::MaterialSideColor[mc::StationaryWater] = mc::MaterialColor[mc::StationaryWater];
};
