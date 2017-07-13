#include "Config.hh"
#include "Log.hh"

#include <fstream>
#include <iostream>
#include <boost/program_options.hpp>

namespace xing {

Options::Options():
    config_options_("XingConfigOptions") {

  namespace po = boost::program_options;

  config_options_.add_options()
      ("xing.instrus_filter", po::value<std::string>(&instrus_filter), 
       "instrument")
      ("xing.speed_file", po::value<std::string>(&speed_file), 
       "speed file")

      ("xing.log_cfg", po::value<std::string>(&log_cfg), 
       "log config file")
      
      ("xing.multicast_ip", po::value<std::string>(&multicast_ip), 
       "multicast ip addr")
      ("xing.multicast_port", po::value<long>(&multicast_port), 
       "multicast port")
      ("xing.local_ip", po::value<std::string>(&local_ip), 
       "local ip addr")
      ("xing.cpu_core", po::value<int>(&cpu_core), 
       "cpu core")
      ;

  return;
  
}

Options::~Options() {
}

po::options_description* Options::configOptions() {
  return &config_options_;
}

Config::Config(int argc, char* argv[]) {
  options_.reset(new Options());

  std::unique_ptr<soil::Config> config(soil::Config::create());
  config->registerOptions(options_.get());

  config->configFile() = "xing.cfg";
  config->loadConfig(argc, argv);
  
  // init the log
  XING_LOG_INIT(options_->log_cfg);
  
  return;
}

Config::~Config() {
}

};  
