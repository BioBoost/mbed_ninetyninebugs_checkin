#pragma once

#include "PN532_SPI.h"
#include "NfcAdapter.h"
#include "FPointer.h"

namespace NfcShield {

  typedef void (*GuidCallback)(std::string);

  class NfcIdentificationDevice {
    private:
      SPI spiBus;
      PN532_SPI nfcShield;
      NfcAdapter nfcAdapter;
      FPointer callback;   // from mbed

    public:
      NfcIdentificationDevice(PinName mosi=p5, PinName miso=p6, PinName sck=p7, PinName cs=p17);

    public:
      // Template needs to be in header file
      // see https://developer.mbed.org/cookbook/FPointer
      template<typename T> void register_callback(T* object, uint32_t (T::*method)(uint32_t)) {
        callback.attach(object, method);
      }

      void check_for_tag(void);

    private:
      uint32_t callback_that_does_nothing(uint32_t pointerToGuidString);
  };

};
