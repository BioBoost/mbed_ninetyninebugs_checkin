#pragma once

#include "Simple-LoRaWAN.h"
#include "guid_processor.h"

namespace NinetyNineBugsCheckin {

  class LoraGuidProcessor : public GuidProcessor {

    private:
      SimpleLoRaWAN::Node* node;

    public:
      LoraGuidProcessor(void);

    public:
      void lora_process(void);

    public:
      uint32_t process_guid(uint32_t pointerToGuidString);

  };

};
