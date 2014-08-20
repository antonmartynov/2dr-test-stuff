#ifndef rasterizerH
#define rasterizerH

#include "resolution.h"
#include "surface.h"

class Rasterizer
{
	public:
	Rasterizer();
	~Rasterizer();

	void initialize(Resolution initRenderResolution, Surface * initOutputBuffer);
	void deinitialize();

	void setRenderResolution(Resolution newRenderResolution, bool active);
	Resolution getRenderResolution();
	void updateRenderResolution();

	Surface * outputBuffer;

	void generateDemoFrame();
	void renderFrame();

	private:

	Resolution renderResolution;
	void resize(Resolution newResolution, bool active);

};

#endif
