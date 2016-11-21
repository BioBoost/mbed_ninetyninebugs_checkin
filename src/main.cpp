#include "mbed.h"
#include "log.h"
#include "task_scheduler.h"
#include "alive.h"

using namespace NinetyNineBugsCheckin;

Serial pc(USBTX, USBRX); // tx, rx

int main() {
    pc.baud(9600);
    SimplyLog::Log::i("Booting NinetyNine Bugs Checkin\r\n");

    Alive alive;

    SimpleTaskScheduler::TaskScheduler scheduler;
    scheduler.create_periodic_task(&alive, &Alive::alive_task, 1);

    while(1) {
      scheduler.update();
    }
}
