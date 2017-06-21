#pragma once

#include <math.h>
#include <cfloat>

namespace LittleRaytracer
{
	//Float math helper functions
	namespace FMath
	{
		namespace Constants
		{
			static const float E				=  2.71828182845904523536f;

			static const float PI				=  3.14159265358979323846f;
			static const float PI_OVER_TWO		=  1.57079632679489661923f;
			static const float PI_OVER_FOUR		=  0.78539816339744830962f;
			static const float TWO_PI			=  6.28318530717958647692f;
			static const float FOUR_PI			= 12.56637061435917295384f;
			static const float ONE_OVER_PI		=  0.31830988618379067154f;

			static const float SQRT_2			=  1.41421356237309504880f;
			static const float ONE_OVER_SQRT_2	=  0.70710678118654752440f;

			static const float LOG2_E			=  1.44269504088896340736f;
			static const float LOG10_E			=  0.43429448190325182765f;

			static const float LN_2				=  0.69314718055994530942f;
			static const float LN_10			=  2.30258509299404568402f;
		}

		//Checks if two floats are equal within epsilon
		inline bool Equals(float a, float b, float epsilon = 0.000001f)
		{
			return b <= (a + epsilon)&& b >= (a - epsilon);
		}

		inline float Max(float a, float b)
		{
			return  a < b ? b : a;
		}

		inline float Max(float a, float b, float c)
		{
			float abMax = Max(a,b);
			return  abMax < c ? c : abMax;
		}

		inline float Max(float a, float b, float c, float d)
		{
			float abcMax = Max(a, b, c);
			return  abcMax < d ? d : abcMax;
		}

		inline float Min(float a, float b)
		{
			return  a > b ? b : a;
		}

		inline float Min(float a, float b, float c)
		{
			float abMin = Min(a,b);
			return  abMin > c ? c : abMin;
		}

		inline float Min(float a, float b, float c, float d)
		{
			float abcMin = Min(a, b, c);
			return  abcMin > d ? d : abcMin;
		}

		inline float Clamp(float a, float min, float max)
		{
			return Min(Max(min, a), max);
		}

		inline float Clamp01(float a)
		{
			return Clamp(a, 0.0f, 1.0f);
		}

		inline float Floor(float a)
		{
			return floor(a);
		}

		inline float Ceil(float a)
		{
			return ceil(a);
		}

		inline float Round(float a)
		{
			return round(a);
		}

		inline float Fract(float a)
		{
			return a - Floor(a);
		}

		inline float DegToRad(float deg)
		{
			return deg * Constants::PI / 180.0f;
		}

		inline float RadToDeg(float rad)
		{
			return rad * 180.0f / Constants::PI;
		}

		inline float Lerp(float a, float b, float t)
		{
			return (1.0f - t) * a + t * b;
		}

		inline float Pow(float base, float exponent)
		{
			return pow(base, exponent);
		}

		inline float Sqrt(float a)
		{
			return sqrt(a);
		}

		inline float Sin(float a)
		{
			return sin(a);
		}

		inline float Cos(float a)
		{
			return cos(a);
		}

		inline float Tan(float a)
		{
			return tan(a);
		}

		inline float Exp(float a)
		{
			return exp(a);
		}

		inline float Log(float a)
		{
			return log(a);
		}

		inline float Log10(float a)
		{
			return log10(a);
		}

		inline float Abs(float a)
		{
			return fabs(a);
		}
	}
}

