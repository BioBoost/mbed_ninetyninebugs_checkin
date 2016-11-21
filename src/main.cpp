#include "mbed.h"

DigitalOut myled(LED1);
Serial pc(USBTX, USBRX); // tx, rx

int main() {
    pc.baud(9600);
    printf("Booting .... \r\n");

    while(1) {
        myled = 1;
        wait(0.2);
        myled = 0;
        wait(0.2);
    }
}
