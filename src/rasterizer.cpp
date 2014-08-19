//---------------------------------------------------------------------------


#pragma hdrstop

#include "rasterizer.h"

Rasterizer::Rasterizer()
{

}

Rasterizer::~Rasterizer()
{

}

void Rasterizer::initialize(Resolution initRenderResolution, Surface * initOutputArray)
{
	renderResolution = initRenderResolution;
	outputArray = initOutputArray;
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
	renderResolution.setWidth(outputArray->getWidth());
	renderResolution.setHeight(outputArray->getHeight());
}

void Rasterizer::resize(Resolution newResolution, bool active)
{
	renderResolution = newResolution;
	if(active)
	{
		outputArray->resize(renderResolution.getWidth(), renderResolution.getHeight());
    }
}

void Rasterizer::generateDemoFrame()
{
	int ** oAContent = outputArray->content;
	for(int y = 0; y < renderResolution.getHeight(); ++y)
	{
		for(int x = 0; x < renderResolution.getWidth(); ++x)
		{
			oAContent[y][x] = ((y) / 64 + (x) / 64) % 2 == 0 ? 0x00008000 : 0x00000080;
        }
    }
}

void Rasterizer::renderFrame()
{
	// temp
	generateDemoFrame();
}

//---------------------------------------------------------------------------

#pragma package(smart_init)
