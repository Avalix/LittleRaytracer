#pragma once
#include <cassert>
#include "Color.h"
#include "Maths/Maths.h"

namespace LittleRaytracer
{
	inline float Color::operator[](int i) const
	{
		if(i < 0 || i > 4)
		{
			assert(false);
		}

		if(i == 0)
		{
			return R;
		}

		if(i == 1)
		{
			return G;
		}

		if(i == 2)
		{
			return B;
		}

		return A;
	}

	inline float& Color::operator[](int i)
	{
		if(i < 0 || i > 4)
		{
			assert(false);
		}

		if(i == 0)
		{
			return R;
		}

		if(i == 1)
		{
			return G;
		}

		if(i == 2)
		{
			return B;
		}

		return A;
	}

	inline Color Color::Lerp(const Color& a, const Color& b, float t)
	{
		return Color(
			FMath::Lerp(a.R, b.R, t),
			FMath::Lerp(a.G, b.G, t),
			FMath::Lerp(a.B, b.B, t),
			FMath::Lerp(a.A, b.A, t));
	}

	inline Color& operator+=(Color& a, const Color& b)
	{
		a.R += b.R; 
		a.G += b.G; 
		a.B += b.B;
		a.A += b.A;

		return a;
	}

	inline Color& operator-=(Color& a, const Color& b)
	{
		a.R -= b.R; 
		a.G -= b.G; 
		a.B -= b.B;
		a.A -= b.A;

		return a;
	}

	inline Color& operator*=(Color& a, const Color& b)
	{
		a.R *= b.R; 
		a.G *= b.G; 
		a.B *= b.B;
		a.A *= b.A;

		return a;
	}

	inline Color& operator*=(Color& a, float k)
	{
		a.R *= k; 
		a.G *= k; 
		a.B *= k;
		a.A *= k;

		return a;
	}

	inline Color& operator/=(Color& a, float k)
	{
		float oneOverK = 1.0f / k;

		a.R *= oneOverK; 
		a.G *= oneOverK; 
		a.B *= oneOverK;
		a.A *= oneOverK;

		return a;
	}

	inline Color operator+(Color a, const Color& b)
	{
		a += b;
		return a;
	}

	inline Color operator-(Color a, const Color& b)
	{
		a -= b;
		return a;
	}

	inline Color operator*(Color a, float k)
	{
		a *= k;
		return a;
	}

	inline Color operator*(float k, Color a)
	{
		a *= k;
		return a;
	}

	inline Color operator*(Color a, const Color& b)
	{
		a *= b;
		return a;
	}

	inline Color operator/(Color a, float k)
	{
		a /= k;
		return a;
	}

	inline Color operator/(float k, Color a)
	{
		a /= k;
		return a;
	}

	inline bool operator==(const Color& a, const Color& b)
	{
		return FMath::Equals(a.R, b.R) &&
			FMath::Equals(a.G, b.G) &&
			FMath::Equals(a.B, b.B) &&
			FMath::Equals(a.A, b.A);

	}

	inline bool operator!=(const Color& a, const Color& b)
	{
		return !(a == b);
	}
}
