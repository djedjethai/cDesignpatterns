#include"Renderer.h"



int main(){

	RasterRenderer rr;

	Circle c(rr, 1, 2, 45);

	c.draw();
	c.resize(10);
	c.draw();

	return 0;
}
