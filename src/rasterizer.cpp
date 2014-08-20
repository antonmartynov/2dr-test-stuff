#include "rasterizer.h"

Rasterizer::Rasterizer()
{

}

Rasterizer::~Rasterizer()
{

}

void Rasterizer::initialize(Resolution initRenderResolution, Surface * initOutputBuffer)
{
	renderResolution = initRenderResolution;
	outputBuffer = initOutputBuffer;
}

void Rasterizer::deinitialize()
{

}

void Rasterizer::setRenderResolution(Resolution newRenderResolution, bool active)
{
	resize(newRenderResolution, active);
}

Resolution Rasterizer::getRenderResolution()
{
	return renderResolution;
}

void Rasterizer::updateRenderResolution()
{
	renderResolution.setWidth(outputBuffer->getWidth());
	renderResolution.setHeight(outputBuffer->getHeight());
}

void Rasterizer::resize(Resolution newResolution, bool active)
{
	renderResolution = newResolution;
	if(active)
	{
		outputBuffer->resize(renderResolution.getWidth(), renderResolution.getHeight());
	}
}

void Rasterizer::generateDemoFrame()
{
	int ** oBContent = outputBuffer->content;
	for(int y = 0; y < renderResolution.getHeight(); ++y)
	{
		for(int x = 0; x < renderResolution.getWidth(); ++x)
		{
			oBContent[y][x] = ((y) / 64 + (x) / 64) % 2 == 0 ? 0x00008000 : 0x00000080;
        }
    }
}

void Rasterizer::renderFrame()
{
	// temp
	generateDemoFrame();
}
