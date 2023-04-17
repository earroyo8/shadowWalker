CFLAGS = -I ./include
##LIB    = ./lib/fmod/libfmodex64.so
LFLAGS = -lrt -lX11 -lGLU -lGL -lm #-lXrandr

all: shadow

shadow: shadow.cpp log.cpp nflessati.cpp earroyo.cpp drivera.cpp
	g++ $(CFLAGS) shadow.cpp log.cpp nflessati.cpp earroyo.cpp drivera.cpp libggfonts.a \
	/usr/lib/x86_64-linux-gnu/libopenal.so \
	/usr/lib/x86_64-linux-gnu/libalut.so \
	-Wall -Wextra $(LFLAGS) -o shadow

clean:
	rm -f shadow
	rm -f *.o
