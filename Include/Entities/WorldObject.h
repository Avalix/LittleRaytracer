#pragma once

#include "Maths/Ray.h"

namespace LittleRaytracer
{
	struct HitResult
	{
		float RayT;
		Vector3 HitPoint;
		Vector3 HitNormal;
	};

	//abstract base class representing any object in the world that can interact with rays
	class WorldObject
	{
		public:
			WorldObject() = default;

			WorldObject(const WorldObject& other) = default;
			WorldObject& operator=(const WorldObject& other) = default;
			WorldObject(WorldObject &&) = default;
			WorldObject& operator=(WorldObject &&) = default;

			virtual ~WorldObject() = default;

			//Returns true if the ray hits the object within the valid inverval for t along the ray. If true the 
			//hitResultsOut will be populated with the hit results, otherwise it will be invalid
			virtual bool TryHitWithRay(const Ray& ray, float tIntervalMin, float tIntervalMax,
				HitResult& hitResultOut) const = 0;
	};
}