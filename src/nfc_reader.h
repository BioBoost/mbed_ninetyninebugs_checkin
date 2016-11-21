#pragma once

#include "nfc_identification_device.h"

namespace NinetyNineBugsCheckin {

  class NfcReader {

    private:
      NfcShield::NfcIdentificationDevice * nfcIdentifier;

    public:
      NfcReader(void);

    public:
      // Template needs to be in header file
      // see https://developer.mbed.org/cookbook/FPointer
      template<typename T> void register_guid_process_callback(T* object, uint32_t (T::*method)(uint32_t)) {
        nfcIdentifier->register_callback(object, method);
      }

    public:
      void check_for_nfc_tag(void);
      uint32_t process_guid(uint32_t pointerToGuidString);
  };

};
