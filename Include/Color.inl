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
}
