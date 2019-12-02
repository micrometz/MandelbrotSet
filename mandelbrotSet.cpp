#include <iostream>
#include <cmath>
#include <unistd.h>
#include <complex>
 extern "C"
{
#include "gfx.h"
}

template<typename _Tp> class complex<double>;

int mandelbrotSet(complex<double> c , int max_iterations)
{
int i = 0;
std::complex<double> z =0;
while(i <= max_iterations && norm(z) < 4)
{
z*=z;
z+=c;
i++;
}
return i;
}

double mapToReal(int x, int gfx_xsize, double minR, double maxR)
{
	    double range = maxR - minR;
	        return x * (range /gfx_xsize) + minR;
}

double mapToImaginary(int y, int gfx_xsize, double minI, double maxI)
{
	    double range = maxI - minI;
	        return y * (range / gfx_xsize) + minI;

}


int main()
{

double minI,maxI,minR,maxR; 
int maxN =1000;

int x = gfx_xsize() / 2;
int y = gfx_ysize() / 2;
int dx = 1;
int dy = 1;

gfx_open(500, 500, "mandelbrotSets");
while(true)
{
	
if (gfx_event_waiting())
{
	int button = gfx_wait();
	// print information about the event
	std::cout << "got event: " << button;
	// print character key
	if (button > 31 && button < 128) std::cout << " " << char(button);
	// mouse events
	else if (button == -128) std::cout << " resize (" << gfx_xsize() << "," << gfx_ysize() << ")";
	else if (button < 10) std::cout << " at pos (" << gfx_xpos() << "," << gfx_ypos() << ")";
	std::cout << std::endl;
	// when do we quit?
	if (button == 'x' || button == 'q')
		break;
	// up arrow
	if (button == 65431 || button == 65362) dy--;
	// down arrow
	if (button == 65433 || button == 65364) dy++;
	// left arroow
	if (button == 65430 || button == 65361) dx--;
	// right arroow	
	if (button == 65432 || button == 65363) dx++;

}
else
{
	// move the centroids
	x = x + dx;
	y = y + dy;
	// did we go past edge of window?
	
	if (x > gfx_xsize()) x = 0;
	if (y > gfx_ysize()) y = 0;
	if (x < 0) x = gfx_xsize();
	if (y < 0) y = gfx_ysize();
	// sleep 10,000 usec or 10 msec.

	usleep(10000);
	// update the drawing
	
	for(int y =0;y<gfx_ysize();y++)
	{
		for(int x =0; x<gfx_xsize(); x++)
		{
			double cr =  mapToReal(x, gfx_xsize,minR, maxR);
			double ci =  mapToImaginary(y, gfx_ysize,minI, maxI);
			int n = mandelbrotSet(<cr,ci>,maxN);
			gfx_color(n % 255, n % 255, n % 255);
		}
	}
}
return 0;
}
}
