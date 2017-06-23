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
			: R(r)
			, G(g)
			, B(b)
			, A(a)
		{

		}


		inline float operator[](int i) const;
		inline float& operator[](int i);

		inline static Color Lerp(const Color& a, const Color& b, float t);

		inline static Color ApplyGamma(const Color& a, float gamma);

		float R;
		float G;
		float B;
		float A;

	};
}

#include "Color.inl"