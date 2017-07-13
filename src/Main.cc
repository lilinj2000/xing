#include <memory>

#include "Config.hh"
#include "Server.hh"
// #include "soil/Pause.hh"

int main(int argc, char* argv[]) {

  std::unique_ptr<xing::Config> config;
  config.reset(new xing::Config(argc, argv));

  std::unique_ptr<xing::Server> server;
  server.reset(new xing::Server(config->options()));

  // std::unique_ptr<soil::Pause> pause(soil::Pause::create());;
  
  return 0;
}
