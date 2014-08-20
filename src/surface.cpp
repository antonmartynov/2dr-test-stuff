#include "surface.h"

Surface::Surface()
{

}

Surface::~Surface()
{

}

void Surface::initialize(int initWidth, int initHeight)
{
	width = initWidth;
	height = initHeight;
	content = new int * [initHeight];
	for(int i = 0; i < initHeight; ++i)
	{
		content[i] = new int [initWidth];
    }
}

void Surface::resize(int newWidth, int newHeight)
{
	deinitialize();
	initialize(newWidth, newHeight);
}

void Surface::deinitialize()
{
	for(int i = 0; i < height; ++i)
	{
		delete [] content[i];
	}
	delete [] content;
}

int Surface::getWidth()
{
	return width;
}

int Surface::getHeight()
{
    return height;
}
