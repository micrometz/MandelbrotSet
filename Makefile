FLAGS=-g -Wall
CXXFLAGS=-g -Wall

LDLIBS=-lX11 -lm

LINK.o = $(CXX) $(LDFLAGS) $(TARGET_ARCH)

drawing: mandelbrotSet.o gfx.o
	clean:
		rm -f mandelbrotSet *.o
