#include <wiringPi.h>
#include <piGlow.h>

//#include <signal.h>
#include <stdbool.h>
#include <stdlib.h>



void exitOnHandle(int signum) {
    exit(0);
}


int main(int argc, char** argv) {
    // Run 'gpio load i2c' externally.

    // Initialize PiGlow to have all LEDs off.
    piGlowSetup(1);

    //Set up a handler so we can quit this program.
    //struct sigaction handler;
    //handler.

    // We should basically run forever until interrupted.
    const int BRIGHTNESS = 100;
    const int SLEEP_TIME_MS = 250;
    const int TOTAL_RINGS = 5;

    int active_ring = TOTAL_RINGS - 1;

    while(true) {
	piGlowRing(active_ring, 0);
	active_ring = ++active_ring % TOTAL_RINGS;
	piGlowRing(active_ring, BRIGHTNESS);

	delay(SLEEP_TIME_MS);
    }

    return 0;
}
