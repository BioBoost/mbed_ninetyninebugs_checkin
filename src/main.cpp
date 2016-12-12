#include "mbed.h"
#include "log.h"
#include "task_scheduler.h"
#include "alive.h"
#include "nfc_reader.h"
#include "lora_guid_processor.h"

using namespace NinetyNineBugsCheckin;

Serial pc(USBTX, USBRX); // tx, rx

int main() {
    pc.baud(115200);
    SimplyLog::Log::i("Booting NinetyNine Bugs Checkin\r\n");

    Alive alive;
    NfcReader nfcReader;
    LoraGuidProcessor loraProcessor;

    // Bind lora guid processor to nfc reader
    nfcReader.register_guid_process_callback(&loraProcessor, &LoraGuidProcessor::process_guid);

    SimpleTaskScheduler::TaskScheduler scheduler;
    scheduler.create_periodic_task(&alive, &Alive::alive_task, 1);
    scheduler.create_periodic_task(&nfcReader, &NfcReader::check_for_nfc_tag, 1);
    scheduler.create_continuous_task(&loraProcessor, &LoraGuidProcessor::lora_process);

    while(1) {
      scheduler.update();
    }
}
