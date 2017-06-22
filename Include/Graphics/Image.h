#pragma once

#include <cstdint>
#include <memory>

namespace LittleRaytracer
{
	using ImageBufferPtr = std::unique_ptr<char[]>;

	class Color;

	//Represents an RGBA image that can be written to disk
	class Image
	{
	public:
		enum class ImageFormat
		{
			PNG,
			BMP,
			TGA,
		};

		static const uint32_t NUM_CHANNELS = 4;

		Image(uint32_t width, uint32_t height, ImageFormat imageFormat = ImageFormat::PNG);
		Image(const Image& other);
		Image(Image&& other);

		Image& operator=( const Image& other );
		Image& operator=( Image&& other );

		~Image();

		void WriteImageToDisk(const char* filename) const;

		void SetPixel(uint32_t x, uint32_t y, Color color);
		Color GetPixel(uint32_t x, uint32_t y) const;

		ImageFormat GetImageFormat() const { return mImageFormat; }

		uint32_t GetImageWidth() const { return mImageWidth; }
		uint32_t GetImageHeight() const { return mImageHeight; }

	private:
		ImageBufferPtr mImageData;
		ImageFormat mImageFormat;

		uint32_t mImageWidth;
		uint32_t mImageHeight;
	};
}
