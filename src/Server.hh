#ifndef XING_SERVER_HH
#define XING_SERVER_HH

#include "DFITCMdApiXQN.h"
#include "air/MDataFile.hh"

namespace xing {

class Options;

class Server : public DFITCMDAPIXQN::DFITCMdSpi {
 public:
  Server(Options* options);

  virtual ~Server();

  virtual void OnMarketData(struct DFITCMarketDataFieldXQN* pMarketDataField);
  
 protected:
  air::SpeedMData* toSpeedMData(const std::string& instru,
                                const std::string& update_time,
                                int update_millisec);
 private:
  Options* options_;
  
  DFITCMDAPIXQN::DFITCMdApi* service_;

  std::unique_ptr<air::MDataFile> speed_file_;
};

};

#endif
