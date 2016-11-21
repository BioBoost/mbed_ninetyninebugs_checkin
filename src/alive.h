#pragma once

namespace NinetyNineBugsCheckin {

  class Alive {
    DigitalOut aliveLed;

    public:
      Alive(void) :aliveLed(LED1) {}

      void alive_task(void) {
        aliveLed = !aliveLed;
      }
  };

};
