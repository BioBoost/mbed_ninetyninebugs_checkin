#include "nfc_identification_device.h"
#include "globally_unique_identifier.h"
#include "log.h"

namespace NfcShield {

  NfcIdentificationDevice::NfcIdentificationDevice(
    PinName mosi, PinName miso, PinName sck, PinName cs)
      : nfcAdapter(nfcShield), nfcShield(spiBus, cs), spiBus(mosi, miso, sck) {

    SimplyLog::Log::d("Initializing NFC shield\r\n");
    register_callback(this, &NfcIdentificationDevice::callback_that_does_nothing);
    nfcAdapter.begin();
  }

  void NfcIdentificationDevice::check_for_tag(void) {
    if (nfcAdapter.tagPresent()) {
      NfcTag tag = nfcAdapter.read();
      if (tag.hasNdefMessage()) {
        NdefMessage message = tag.getNdefMessage();
        NdefRecord record = message[0];

        if (GloballyUniqueIdentifier::containsValidGuid(&record)) {
          GloballyUniqueIdentifier * guid = GloballyUniqueIdentifier::instance_from_record(&record);
          std::string guidString = guid->get_guid();
          callback.call((uint32_t)&guidString);
          delete guid;
        }
      }
    }
  }

  uint32_t NfcIdentificationDevice::callback_that_does_nothing(uint32_t pointerToGuidString) {
    return 0;
  }

};
