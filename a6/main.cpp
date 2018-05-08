#include <iostream>
#include "Image.h"

using namespace std;

int main()
{
	Image g = *Image::Create(3,3);
	
	int imageX = 1000, imageY = 1000;

	cout << "Height: " << g.getHeight() << " Width: " << g.getWidth() << endl << endl;

	g.setPixel(0, 0, 255, 0, 0);
	g.setPixel(1, 0, 0, 255, 0);
	g.setPixel(2, 0, 0, 0, 255);
	
	g.setPixel(0, 1, 100, 0, 100);
	g.setPixel(1, 1, 255, 0, 255);
	g.setPixel(2, 1, 255, 0, 255);
	
	g.setPixel(0, 2, 255, 0, 255);
	g.setPixel(1, 2, 255, 0, 255);
	g.setPixel(2, 2, 255, 0, 255);

	Image b = g;


	b.setPixel(0, 0, 255, 255, 255);
	b.saveImage("b");
	g.saveImage("g");

	return 0;
}
