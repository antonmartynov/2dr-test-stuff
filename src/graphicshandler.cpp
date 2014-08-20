#include "graphicshandler.h"

GraphicsHandler::GraphicsHandler()
{

}

GraphicsHandler::~GraphicsHandler()
{

}

void GraphicsHandler::initialize(Resolution initResolution, int initAntiAliasingFactor, TCanvas * initOutputCanvas)
{
	screenResolution = initResolution;
	antiAliasingFactor = initAntiAliasingFactor;
	outputCanvas = initOutputCanvas;
	sOutput.initialize(initResolution, initAntiAliasingFactor, initOutputCanvas);
	Resolution zeroResolution;
	zeroResolution.setWidth(1);
	zeroResolution.setHeight(1);
	rRizer.initialize(zeroResolution, sOutput.currentForegroundRenderBuffer);
	rRizer.updateRenderResolution();
	BITMAP_READY = RegisterWindowMessage("BITMAP_READY");
}

void GraphicsHandler::deinitialize()
{
	//soutput.deinitialize
	rRizer.deinitialize();
}

int GraphicsHandler::setResolution(Resolution newResolution)
{
	resize(newResolution, antiAliasingFactor);
}

Resolution GraphicsHandler::getResolution()
{
	return screenResolution;
}

int GraphicsHandler::setAntiAliasingFactor(int newAntiAliasingFactor)
{
	resize(screenResolution, newAntiAliasingFactor);
}

int GraphicsHandler::getAntiAliasingFactor()
{
	return antiAliasingFactor;
}

void GraphicsHandler::resize(Resolution newResolution, int newAntiAliasingFactor)
{
	screenResolution = newResolution;
	antiAliasingFactor = newAntiAliasingFactor;
	sOutput.setScreenResolution(newResolution);
	sOutput.setAntiAliasingFactor(newAntiAliasingFactor);
	rRizer.updateRenderResolution();
}

void GraphicsHandler::updateForm()
{
	sOutput.bitmapToCanvas();
	//formToUpdate->Caption = "";
	formUpdated = 1;
}

void GraphicsHandler::produceOneFrame()
{
	rRizer.renderFrame();
	//soutput.switchrenderbuffers
	rRizer.outputBuffer = sOutput.currentForegroundRenderBuffer;
	//rasterizer.maincam.renderbuffer = soutput.currentexternalbuffer
	sOutput.arrayToBitmap();
	PostMessage(Application->Handle, BITMAP_READY, 0, 0);
}

void __fastcall GraphicsHandler::messageHandler(tagMSG & Msg, bool & Handled)
{
	if(Msg.message == BITMAP_READY)
	{
        formToUpdate->Invalidate();
    }
}
