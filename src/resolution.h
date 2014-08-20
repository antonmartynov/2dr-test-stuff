#ifndef resolutionH
#define resolutionH

class Resolution
{
	public:

	Resolution();
	Resolution(int initWidth, int initHeight);
	~Resolution();

	int setWidth(int newWidth);
	int setHeight(int newHeight);
	int getWidth();
	int getHeight();

	private:

	int width;
	int height;
};

#endif
