#pragma once

#include "nfc_identification_device.h"

namespace NinetyNineBugsCheckin {

  class NfcReader {

    private:
      NfcShield::NfcIdentificationDevice * nfcIdentifier;

    public:
      NfcReader(void);

    public:
      void check_for_nfc_tag(void);
      uint32_t process_guid(uint32_t pointerToGuidString);
  };

};
