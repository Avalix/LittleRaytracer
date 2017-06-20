#pragma once

namespace LittleRaytracer
{
	//Represents an simple RGBA Color, where each channel is stored in a float format
	class Color
	{
	public:
		Color() : Color(1.0f, 1.0f, 1.0f)
		{

		}

		Color(float r, float g, float b, float a = 1.0f)
		{
			mChannels[0] = r;
			mChannels[1] = g;
			mChannels[2] = b;
			mChannels[3] = a;
		}

		inline float GetR() const { return mChannels[0]; }
		inline float GetG() const { return mChannels[1]; }
		inline float GetB() const { return mChannels[2]; }
		inline float GetA() const { return mChannels[3]; }

		inline void SetR(float r) { mChannels[0] = r; }
		inline void SetG(float g) { mChannels[1] = g; }
		inline void SetB(float b) { mChannels[2] = b; }
		inline void SetA(float a) { mChannels[3] = a; }

		inline float operator[](int i) const { return mChannels[i]; }
		inline float& operator[](int i) { return mChannels[i]; }

	private:
		float mChannels[4]; //RGBA;

	};
}