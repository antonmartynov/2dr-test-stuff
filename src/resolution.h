//---------------------------------------------------------------------------

#ifndef resolutionH
#define resolutionH

class Resolution
{
	public:

	Resolution();
	~Resolution();

	int setWidth(int newWidth);
	int setHeight(int newHeight);
	int getWidth();
	int getHeight();

	private:

	int width;
	int height;
};

//---------------------------------------------------------------------------
#endif
