#include "resolution.h"

Resolution::Resolution()
{
	setWidth(1);
	setHeight(1);
}

Resolution::Resolution(int initWidth, int initHeight)
{
	setWidth(initWidth);
	setHeight(initHeight);
}

Resolution::~Resolution()
{

}

int Resolution::setWidth(int newWidth)
{
	if(newWidth > 0)
	{
		width = newWidth;
		return 1;
	}
	return 0;
}

int Resolution::setHeight(int newHeight)
{
	if(newHeight > 0)
	{
		height = newHeight;
		return 1;
	}
	return 0;
}

int Resolution::getWidth()
{
	return width;
}

int Resolution::getHeight()
{
	return height;
}
