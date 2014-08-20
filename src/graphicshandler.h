#ifndef graphicshandlerH
#define graphicshandlerH

#include "screenoutput.h"
#include "rasterizer.h"

class GraphicsHandler
{
	public:

	GraphicsHandler();
	~GraphicsHandler();

	void initialize(Resolution initResolution, int initAntiAliasingFactor, TCanvas * initOutputCanvas);
	void deinitialize();

	int setResolution(Resolution newResolution);
	Resolution getResolution();
	int setAntiAliasingFactor(int newAntiAliasingFactor);
	int getAntiAliasingFactor();

	TCanvas * outputCanvas;
	TForm * formToUpdate;
	void updateForm();

	void produceOneFrame();

	void __fastcall messageHandler(tagMSG & Msg, bool & Handled);

	ScreenOutput sOutput;
	Rasterizer rRizer;

	private:

	Resolution screenResolution;
	int antiAliasingFactor;
	void resize(Resolution newResolution, int newAntiAliasingFactor);

	unsigned int BITMAP_READY;

	bool formUpdated;
};

#endif
