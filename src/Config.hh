#ifndef XING_CONFIG_HH
#define XING_CONFIG_HH

#include <string>
#include <memory>
#include "soil/Config.hh"

namespace xing {

namespace po = boost::program_options;

class Options : public soil::Options {
 public:
  Options();
  
  virtual ~Options();

  virtual po::options_description* configOptions();

  std::string instrus_filter;

  std::string speed_file;
  
  std::string log_cfg;

  std::string multicast_ip;
  long multicast_port;
  std::string local_ip;
  int cpu_core;

 private:
  boost::program_options::options_description config_options_;
};

class Config {
 public:
  Config(int argc = 0, char* argv[] = nullptr);

  ~Config();

  Options* options() {
    return options_.get();
  }


 private:
  std::unique_ptr<Options> options_;
};

}  

#endif 
