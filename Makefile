DEBUG	= -O3
CC	= gcc

INCLUDE = -I/usr/local/include
CFLAGS	= $(DEBUG) -Wall $(INCLUDE) -Wall -Werror -pipe -std=gnu99

LDFLAGS = -L/usr/local/lib
LDLIBS	= -lwiringPi -lwiringPiDev

OBJ = glowglobe.o

glowglobe: $(OBJ)
	@echo [linking GlowGlobe]
	@$(CC) -o $@ $(OBJ) $(LDFLAGS) $(LDLIBS)

%.o: %.c
	@echo [compiling $<]
	@$(CC) -c $(CFLAGS) $<

clean:
	@echo [cleaning GlowGlobe]
	@rm glowglobe.o glowglobe
