//---------------------------------------------------------------------------

#ifndef surfaceH
#define surfaceH

class Surface
{
	public:

	Surface();
	~Surface();

	int ** content;
	void initialize(int initWidth, int initHeight);
	void resize(int newWidth, int newHeight);
	void deinitialize();
	int getWidth();
	int getHeight();

	private:

	int width;
	int height;
};

//---------------------------------------------------------------------------
#endif
