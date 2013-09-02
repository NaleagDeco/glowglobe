DEBUG	= -O3
CC	= gcc

INCLUDE = -I/usr/local/include
CFLAGS	= $(DEBUG) -Wall $(INCLUDE) -Winline -pipe

LDFLAGS = -L/usr/local/lib
LDLIBS	= -lwiringPi -lwiringPiDev

all: glowglobe

glowglobe: glowglobe.o
	@echo [linking GlowGlobe]
	@$(CC) -o $@ $^ $(LDFLAGS) $(LDLIBS)

glowglobe.o: glowglobe.c
	@echo [compiling $<]
	@$(CC) -c $(CFLAGS) $< $@

clean:
	@echo [cleaning GlowGlobe]
	@rm glowglobe.o glowglobe
