#pragma once

#include "Maths/Ray.h"
#include "Materials/Material.h"

namespace LittleRaytracer
{
	struct HitResult
	{
		HitResult() = default;

		HitResult(const Ray& ray, float rayT, const Vector3& hitPoint, const Vector3& hitNormal, 
			const MaterialPtr& material)
			: Ray(ray)
			, RayT(rayT)
			, HitPoint(hitPoint)
			, HitNormal(hitNormal)
			, Material(material)
		{
			
		}

		Ray Ray;
		float RayT;
		Vector3 HitPoint;
		Vector3 HitNormal;
		MaterialPtr Material;
	};
}
