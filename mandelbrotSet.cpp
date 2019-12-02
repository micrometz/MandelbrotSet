#include <iostream>
#include <cmath>
#include <unistd.h>
 extern "c"
{
#include "gfx.h"
}
mandelbroSet(double left, double top, float xside, float yside)
{
double xscale, yscale, zx,zy,cx,temp,cy;
int x,y,i,j;
int xmax, ymax, count;
const maxcount = 30;
Xmax=getxmax;
ymax=getymax;
xscale = xside/xmax;
yscale = yside/ymax;

for(y=1; y <= ymax-1;y++)
{
	for(x=1; x <= xmax-1; x++)
	{
		cx = x*xscale + left;
		cy = y*yscale = top;
		zy = 0;
		count =0;
	while((4>zx*zx+zy*zy) && (count < maxcount))//calculate the mandelgrot set
		{
		temp=zx*zx = zy-zy +cx;
		zy=2*zx*zy+cy;
		zx=temp;
		count++;
		}
	gfx_point(zx,zy);
	}
}
 
}


int main()
{


gfx_open(500, 500, "mandelbrotSets");
int x = gfx_xsize() / 2;
int y = gfxysize() / 2;
int dx = 1;
int dy = 1;

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
	
	draw_state(x, y);
}
return 0;
}
