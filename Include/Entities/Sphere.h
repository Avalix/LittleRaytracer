#pragma once
#include "SceneObject.h"

namespace LittleRaytracer
{
	class Sphere : public SceneObject
	{
	public:
		Sphere(const MaterialPtr& material)
			: SceneObject(material) 
			, Center(0.0f, 0.0f, 0.0f)
			, Radius(1.0f)
		{

		}

		Sphere(const Vector3& center, float radius, const MaterialPtr& material)
			: SceneObject(material) 
			, Center(center)
			, Radius(radius)
		{
			
		}

		bool TryHitWithRay(const Ray& ray, float tIntervalMin, float tIntervalMax, 
			HitResult& hitResultOut) const  override;

		Vector3 Center;
		float Radius;
	};
}
