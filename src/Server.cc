#include <stdexcept>

#include "Server.hh"
#include "Log.hh"
#include "Config.hh"

namespace xing {

Server::Server(Options* options) :
    options_(options),
    service_(nullptr) {
  XING_TRACE <<"Server::Server()";

  std::string speed_file = options_->speed_file;
  
  if (!speed_file.empty()) {
    speed_file_.reset(new air::MDataFile(speed_file,
                                         options_->instrus_filter));
  }

  service_ = DFITCMDAPIXQN::DFITCMdApi::CreateDFITCMdApi();

  int ret = -1;
  ret = service_->Init(options_->multicast_ip.data(),
                       options_->multicast_port,
                       options_->local_ip.data(),
                       options_->cpu_core,
                       this);
  if (ret != 0) {
    std::string err_msg = "Init failed!!!\n";
    err_msg += "the ret is " + std::to_string(ret);

    throw std::runtime_error(err_msg);
  }

  service_->Run();
}

Server::~Server() {
  XING_TRACE <<"Server::~Server()";
}

void Server::OnMarketData(
    struct DFITCMarketDataFieldXQN* pMarketDataField) {
  XING_TRACE <<"Server::OnMarketData()";

  speed_file_->putData(toSpeedMData(pMarketDataField->Instrument,
                                    pMarketDataField->UpdateTime,
                                    pMarketDataField->UpdateMillisec
                                    ));
}


air::SpeedMData* Server::toSpeedMData(
    const std::string& instru,
    const std::string& update_time,
    int update_millisec) {
  std::unique_ptr<air::SpeedMData> speed_data(new air::SpeedMData());
  
  speed_data->instru = instru;
  speed_data->update_time = update_time;
  speed_data->update_millisec = update_millisec;

  return speed_data.release();
}

};
