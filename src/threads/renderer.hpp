#ifndef __THREADS__RENDERER_HPP__
#define __THREADS__RENDERER_HPP__

#include "mc/utils.hpp"

#include <boost/shared_ptr.hpp>
#include <boost/filesystem.hpp>

#include <vector>

#include "cache.hpp"
#include "image/image_operations.hpp"
#include "engine/engine_base.hpp"

#include "threads/threadworker.hpp"

namespace fs = boost::filesystem;

struct render_result {
  int xPos, zPos;
  fs::path path;
  boost::shared_ptr<image_operations> operations;
  bool fatal;
  std::string fatal_why;
  std::vector<mc::marker> signs;
  bool cache_hit;
  
  render_result() : fatal(false), fatal_why("(no error)") {}
};

struct render_job {
  int xPos, zPos;
  int xReal, zReal;
  fs::path path;
  boost::shared_ptr<engine_base> engine;
};

class renderer : public threadworker<render_job, render_result> {
public:
  settings_t& s;
  
  renderer(settings_t& s, int n, int total) : threadworker<render_job, render_result>(n, total), s(s) {
  }
  
  render_result work(render_job job) {
    render_result p;
    
    p.path = job.path;
    p.xPos = job.xPos;
    p.zPos = job.zPos;
    p.cache_hit = false;
    
    cache_file cache(mc::utils::level_dir(s.cache_dir, job.xReal, job.zReal), p.path, s.cache_compress);
    
    p.operations.reset(new image_operations);
    
    if (s.cache_use) {
      if (cache.exists()) {
        if (cache.read(p.operations)) {
          p.cache_hit = true;
          return p;
        }
        
        cache.clear();
      }
    }

    mc::level level(job.path);
    
    try {
      level.read();
    } catch(mc::invalid_file& e) {
      p.fatal = true;
      p.fatal_why = e.what();
      return p;
    }
    
    p.signs = level.get_signs();
    
    job.engine->render(level, p.operations);
    
    if (s.cache_use) {
      // create the necessary directories required when caching
      cache.create_directories();
      
      // ignore failure while writing the operations to cache
      if (!cache.write(p.operations)) {
        // on failure, remove the cache file - this will prompt c10t to regenerate it next time
        cache.clear();
      }
    }
    
    return p;
  }
};

#endif /* __THREADS__RENDERER_HPP__ */
