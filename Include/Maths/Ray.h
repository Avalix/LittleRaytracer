#pragma once
#include "Vector3.h"

namespace LittleRaytracer
{
	class Ray
	{
	public:
		Ray() { }

		Ray(const Vector3& origin, const Vector3& direction)
			: Origin(origin)
			, Direction(direction)
		{
			assert(FMath::Equals(Vector3::Length(direction), 1.0f));
		}

		inline Vector3 PointAlongRayAtT(float t) const
		{
			return Origin + t * Direction;
		}


		Vector3 Origin;
		Vector3 Direction;
	};
}