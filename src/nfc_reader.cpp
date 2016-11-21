#include "nfc_reader.h"
#include "log.h"

namespace NinetyNineBugsCheckin {

  NfcReader::NfcReader(void) {
      nfcIdentifier = new NfcShield::NfcIdentificationDevice(p5, p6, p7, p17);
          // MOSI, MISO, SCK, !CS

      nfcIdentifier->register_callback(this, &NfcReader::process_guid);
  }

  void NfcReader::check_for_nfc_tag(void) {
    nfcIdentifier->check_for_tag();
  }

  uint32_t NfcReader::process_guid(uint32_t pointerToGuidString) {
    std::string * guid = (std::string *)pointerToGuidString;
    SimplyLog::Log::d("Got card on NFC device with guid = %s\r\n", guid->c_str());
    return 0;
  }

};
