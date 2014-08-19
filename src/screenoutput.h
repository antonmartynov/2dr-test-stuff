//---------------------------------------------------------------------------

#ifndef screenoutputH
#define screenoutputH

#include "resolution.h"
#include <vcl.h>
#include "surface.h"

class ScreenOutput
{
	public:

	ScreenOutput();
	~ScreenOutput();

	int setScreenResolution(Resolution newScreenResolution);
	Resolution getScreenResolution();
	int setAntiAliasingFactor(int newAntiAliasingFactor);
	int getAntiAliasingFactor();

	int setOutputCanvas(TCanvas * newOutputCanvas);
	TCanvas * getOutputCanvas();

	void arrayToBitmap();
	void bitmapToCanvas();

	int initialize(Resolution initResolution, int initAntiAliasingFactor, TCanvas * initOutputCanvas);

	Surface * currentScreenRenderBuffer;
	Surface * currentRasterizerRenderBuffer;

	private:

	Resolution screenResolution;
	int antiAliasingFactor;
	Resolution renderResolution;
	int resize(Resolution newResolution, int newAntiAliasingFactor);

	TCanvas * outputCanvas;

	Surface renderBuffer1;
	Surface renderBuffer2;
	Surface screenBuffer;
	Graphics::TBitmap * screenBMP;
	void performAntiAliasing();
};
//---------------------------------------------------------------------------
#endif
