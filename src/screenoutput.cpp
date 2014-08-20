#include "screenoutput.h"

ScreenOutput::ScreenOutput()
{

}

ScreenOutput::~ScreenOutput()
{

}

void ScreenOutput::arrayToBitmap()
{
	performAntiAliasing();
	screenBMP->Canvas->Lock();
	for(int y = 0; y < screenResolution.getHeight(); ++y)
	{
		int * currentLine = static_cast <int *> (screenBMP->ScanLine[y]);
		memcpy(currentLine, screenBuffer.content[y], screenResolution.getWidth() * 4);
	}
	screenBMP->Canvas->Unlock();
}

void ScreenOutput::bitmapToCanvas()
{
	screenBMP->Canvas->Lock();
	BitBlt(outputCanvas->Handle, 0, 0, screenResolution.getWidth(), screenResolution.getHeight(),
		   screenBMP->Canvas->Handle, 0, 0, SRCCOPY);
	screenBMP->Canvas->Unlock();
}

void ScreenOutput::performAntiAliasing()
{
	int ** fBContent = currentForegroundRenderBuffer->content;
	int ** sBContent = screenBuffer.content;
	// temp
	for(int y = 0; y < screenResolution.getHeight(); ++y)
	{
		memcpy(sBContent[y], fBContent[y], screenResolution.getWidth() * 4);
    }
}

int ScreenOutput::initialize(Resolution initResolution, int initAntiAliasingFactor, TCanvas * initOutputCanvas)
{
	// temp!
	screenResolution = initResolution;
	antiAliasingFactor = initAntiAliasingFactor;
	renderResolution.setWidth(initResolution.getWidth() * initAntiAliasingFactor);
	renderResolution.setHeight(initResolution.getHeight() * initAntiAliasingFactor);
	renderBuffer.initialize(renderResolution.getWidth(), renderResolution.getHeight());
	currentForegroundRenderBuffer = &renderBuffer;
	screenBuffer.initialize(screenResolution.getWidth(), screenResolution.getHeight());
	screenBMP = new Graphics::TBitmap;
	screenBMP->PixelFormat = pf32bit;
	screenBMP->SetSize(screenResolution.getWidth(), screenResolution.getHeight());
	outputCanvas = initOutputCanvas;
	return 1;
}

int ScreenOutput::setScreenResolution(Resolution newScreenResolution)
{
	if(newScreenResolution.getWidth() > 0 && newScreenResolution.getHeight() > 0)
	{
		return resize(newScreenResolution, getAntiAliasingFactor());
	}
	return 0;
}

Resolution ScreenOutput::getScreenResolution()
{
	return screenResolution;
}

int ScreenOutput::setAntiAliasingFactor(int newAntiAliasingFactor)
{
	if(newAntiAliasingFactor > 0)
	{
		return resize(getScreenResolution(), newAntiAliasingFactor);
	}
	return 0;
}

int ScreenOutput::getAntiAliasingFactor()
{
	return antiAliasingFactor;
}

int ScreenOutput::resize(Resolution newResolution, int newAntiAliasingFactor)
{
	screenResolution = newResolution;
	antiAliasingFactor = newAntiAliasingFactor;
	renderResolution.setWidth(newResolution.getWidth() * newAntiAliasingFactor);
	renderResolution.setHeight(newResolution.getHeight() * newAntiAliasingFactor);
	renderBuffer.resize(renderResolution.getWidth(), renderResolution.getHeight());
	screenBuffer.resize(screenResolution.getWidth(), screenResolution.getHeight());
	screenBMP->SetSize(screenResolution.getWidth(), screenResolution.getHeight());
	return 1;
}

int ScreenOutput::setOutputCanvas(TCanvas * newOutputCanvas)
{
	outputCanvas = newOutputCanvas;
	return 1;
}

TCanvas * ScreenOutput::getOutputCanvas()
{
    return outputCanvas;
}
