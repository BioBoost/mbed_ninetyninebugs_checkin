#include "lora_guid_processor.h"
#include "log.h"
#include "settings.h"
#include <string>

namespace NinetyNineBugsCheckin {

  LoraGuidProcessor::LoraGuidProcessor(void) {
    SimplyLog::Log::i("Initializing lorawan\r\n");
    node = new SimpleLoRaWAN::ABP::Node(devAddr, nwksKey, appKey);
    //node = new OTAA::Node(appEui, devEui, appKey);
    node->disableLinkCheck();
  }

  void LoraGuidProcessor::lora_process(void) {
    node->process();
  }

  uint32_t LoraGuidProcessor::process_guid(uint32_t pointerToGuidString) {
    std::string * guid = (std::string *)pointerToGuidString;
    SimplyLog::Log::d("Sending guid = %s via lora\r\n", guid->c_str());
    node->send((char*)(guid->c_str()), strlen(guid->c_str()));
    return 0;
  }

};
