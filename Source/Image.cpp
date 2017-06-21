#include "Base.h"

#include "../Include/Image.h"
#include "Color.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "3rdParty/stb/stb_image_write.h"

using namespace LittleRaytracer;


Image::Image(uint32_t width, uint32_t height, ImageFormat imageFormat)
	: mImageData(new char[width * height * NUM_CHANNELS])
	, mImageFormat(imageFormat)
	, mImageWidth(width)
	, mImageHeight(height)
{
	
}

Image::Image(const Image& other)
	: mImageFormat(other.mImageFormat)
	, mImageWidth(other.mImageWidth)
	, mImageHeight(other.mImageHeight)
{
	//Perform Deep copy of data
	int imageDataSize = other.mImageWidth * other.mImageHeight * NUM_CHANNELS;
	mImageData = ImageBufferPtr(new char[imageDataSize]);
	memcpy_s(mImageData.get(), imageDataSize, other.mImageData.get(), imageDataSize);
}

Image::Image(Image&& other)
	: mImageData(std::move(other.mImageData))
	, mImageFormat(other.mImageFormat)
	, mImageWidth(other.mImageWidth)
	, mImageHeight(other.mImageHeight)
{

}

Image& Image::operator=( const Image& other )
{
	mImageFormat = other.mImageFormat;
	mImageWidth = other.mImageWidth;
	mImageHeight = other.mImageHeight;

	//perform Deep Copy
	int imageDataSize = other.mImageWidth * other.mImageHeight * NUM_CHANNELS;
	mImageData.reset(new char[imageDataSize]);
	memcpy_s(mImageData.get(), imageDataSize, other.mImageData.get(), imageDataSize);

	return *this;
}

Image& Image::operator=(Image&& other )
{
	mImageFormat = other.mImageFormat;
	mImageWidth = other.mImageWidth;
	mImageHeight = other.mImageHeight;
	mImageData = std::move(other.mImageData);

	return *this;
}

Image::~Image()
{
	
}

void Image::WriteImageToDisk(const char* filePath) const
{
	stbi_write_png(filePath, mImageWidth, mImageHeight, 4, mImageData.get(), mImageWidth * NUM_CHANNELS);
}

void Image::SetPixel(uint32_t x, uint32_t y, Color color)
{
	int pixelIndex = x * NUM_CHANNELS + y * mImageWidth * NUM_CHANNELS;

	mImageData[pixelIndex]     = char(255.0f * color.R);
	mImageData[pixelIndex + 1] = char(255.0f * color.G);
	mImageData[pixelIndex + 2] = char(255.0f * color.B);
	mImageData[pixelIndex + 3] = char(255.0f * color.A);
}

Color Image::GetPixel(uint32_t x, uint32_t y) const
{
	const float oneOver255 = 1.0f / 255.0f;

	int pixelIndex = x * NUM_CHANNELS + y * mImageWidth * NUM_CHANNELS;

	return Color(
		mImageData[pixelIndex] * oneOver255, 
		mImageData[pixelIndex + 1] * oneOver255, 
		mImageData[pixelIndex + 2] * oneOver255,
		mImageData[pixelIndex + 3] * oneOver255);
}
