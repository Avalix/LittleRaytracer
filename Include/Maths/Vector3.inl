#pragma once
#include <cassert>
#include "Vector3.h"
#include "Maths.h"

namespace LittleRaytracer
{
	inline float Vector3::operator[](int i) const
	{
		if(i < 0 || i > 3)
		{
			assert(false);
		}

		if(i == 0)
		{
			return X;
		}

		if(i == 1)
		{
			return Y;
		}

		return Z;
	}

	inline float& Vector3::operator[](int i)
	{
		if(i < 0 || i > 3)
		{
			assert(false);
		}

		if(i == 0)
		{
			return X;
		}

		if(i == 1)
		{
			return Y;
		}

		return Z;
	}


	inline Vector3& operator+=(Vector3& a, const Vector3& b)
	{
		a.X += b.X; 
		a.Y += b.Y; 
		a.Z += b.Z;
		
		return a;
	}

	inline Vector3& operator-=(Vector3& a, const Vector3& b)
	{
		a.X -= b.X; 
		a.Y -= b.Y; 
		a.Z -= b.Z;

		return a;
	}

	inline Vector3& operator*=(Vector3& a, float k)
	{
		a.X *= k; 
		a.Y *= k; 
		a.Z *= k;

		return a;
	}

	inline Vector3& operator/=(Vector3& a, float k)
	{
		float oneOverK = 1.0f / k;

		a.X *= oneOverK; 
		a.Y *= oneOverK; 
		a.Z *= oneOverK;

		return a;
	}

	inline Vector3 operator-(const Vector3& a)
	{
		return Vector3(-a.X, -a.Y, -a.Z);
	}

	inline Vector3 operator+(Vector3 a, const Vector3& b)
	{
		a += b;
		return a;
	}

	inline Vector3 operator-(Vector3 a, const Vector3& b)
	{
		a -= b;
		return a;
	}

	inline Vector3 operator*(Vector3 a, float k)
	{
		a *= k;
		return a;
	}

	inline Vector3 operator*(float k, Vector3 a)
	{
		a *= k;
		return a;
	}

	inline Vector3 operator/(Vector3 a, float k)
	{
		a /= k;
		return a;
	}

	inline Vector3 operator/(float k, Vector3 a)
	{
		a /= k;
		return a;
	}

	inline bool operator==(const Vector3& a, const Vector3& b)
	{
		return FMath::Equals(a.X, b.X) &&
			FMath::Equals(a.Y, b.Y) &&
			FMath::Equals(a.Z, b.Z);
	
	}

	inline bool operator!=(const Vector3& a, const Vector3& b)
	{
		return !(a == b);
	}

	inline float Vector3::Dot(const Vector3& a, const Vector3& b)
	{
		return a.X * b.X + a.Y * b.Y + a.Z * b.Z;
	}

	inline Vector3 Vector3::Cross(const Vector3& a, const Vector3& b)
	{
		return Vector3(
			a.Y * b.Z - a.Z * b.Y,
			a.Z * b.X - a.X * b.Z,
			a.X * b.Y - a.Y * b.X
			);
	}

	inline float Vector3::Length(const Vector3& a)
	{
		return FMath::Sqrt(Dot(a, a));
	}

	inline float Vector3::LengthSquared(const Vector3& a)
	{
		return Dot(a, a);
	}

	inline Vector3 Vector3::Normalize(const Vector3& a)
	{
		float length = Length(a);
		float OneOverLength = 1.0f / length;

		return Vector3(a.X * OneOverLength, a.Y * OneOverLength, a.Z * OneOverLength);
	}
}
