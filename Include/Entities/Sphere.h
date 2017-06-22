#pragma once
#include "WorldObject.h"

namespace LittleRaytracer
{
	class Sphere : public WorldObject
	{
	public:
		Sphere()
			: Center(0.0f, 0.0f, 0.0f)
			, Radius(1.0f)
		{

		}

		Sphere(const Vector3& center, float radius)
			: Center(center)
			, Radius(radius)
		{
			
		}

		bool TryHitWithRay(const Ray& ray, float tIntervalMin, float tIntervalMax, 
			HitResult& hitResultOut) const  override;

		Vector3 Center;
		float Radius;
	};
}
