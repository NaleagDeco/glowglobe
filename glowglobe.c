#include <wiringPi.h>
#include <piGlow.h>

int main(int argc, char** argv) {
    // Run 'gpio load i2c' externally.

    // Initialize PiGlow to have all LEDs off.
    piGlowSetup(1);

    // We should basically run forever until interrupted.
    while(0) {
    }

    return 0;
}
