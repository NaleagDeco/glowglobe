#include <wiringPi.h>
#include <piGlow.h>

#include <signal.h>
#include <stdbool.h>
#include <stdlib.h>

// Setup Constants
const int BRIGHTNESS = 100;
const int SLEEP_TIME_MS = 250;
const int TOTAL_RINGS = 5;


void exitOnHandle(int signum) {
    // Turn off all PIGlow Leds.
    for (int i = 0; i < TOTAL_RINGS; ++i) {
	piGlowRing(i, 0);
    }
    exit(0);
}


int main(int argc, char** argv) {
    // Run 'gpio load i2c' externally.

    // Initialize PiGlow to have all LEDs off.
    piGlowSetup(1);

    //Set up a handler so we can quit this program.
    //struct sigaction handler;
    //handler.
    struct sigaction quit_action;
    quit_action.sa_handler = exitOnHandle;
    quit_action.sa_flags = 0;

    sigaction(SIGINT, &quit_action, NULL);
    sigaction(SIGTERM, &quit_action, NULL);

    // We should basically run forever until interrupted.
    int active_ring = TOTAL_RINGS - 1;

    while(true) {
	piGlowRing(active_ring, 0);
	active_ring = (active_ring + 1) % TOTAL_RINGS;
	piGlowRing(active_ring, BRIGHTNESS);

	delay(SLEEP_TIME_MS);
    }

    return 0;
}
