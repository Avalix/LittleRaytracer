#pragma once

namespace LittleRaytracer
{
	class Vector3
	{
	public:
		Vector3()
			: X(0)
			, Y(0)
			, Z(0)
		{

		}

		Vector3(float x, float y, float z)
			: X(x)
			, Y(y)
			, Z(z)
		{

		}

		inline float operator[](int i) const;
		inline float& operator[](int i);
		inline static float Dot(const Vector3& a, const Vector3& b);
		inline static Vector3 Cross(const Vector3& a, const Vector3& b);
		inline static float Length(const Vector3& a);
		inline static float LengthSquared(const Vector3& a);
		inline static Vector3 Normalize(const Vector3& a);
		inline static Vector3 Reflect(const Vector3& a, const Vector3& Normal);

		float X;
		float Y;
		float Z;
	};
}

#include "Vector3.inl"
