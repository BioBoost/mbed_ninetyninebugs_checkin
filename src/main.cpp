#include "mbed.h"
#include "log.h"
#include "task_scheduler.h"
#include "alive.h"
#include "nfc_reader.h"

using namespace NinetyNineBugsCheckin;

Serial pc(USBTX, USBRX); // tx, rx

int main() {
    pc.baud(9600);
    SimplyLog::Log::i("Booting NinetyNine Bugs Checkin\r\n");

    Alive alive;
    NfcReader nfcReader;

    SimpleTaskScheduler::TaskScheduler scheduler;
    scheduler.create_periodic_task(&alive, &Alive::alive_task, 1);
    scheduler.create_periodic_task(&nfcReader, &NfcReader::check_for_nfc_tag, 0.5);

    while(1) {
      scheduler.update();
    }
}
