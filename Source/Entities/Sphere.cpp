#include "Base.h"

#include "Entities/Sphere.h"

using namespace LittleRaytracer;

bool Sphere::TryHitWithRay(const Ray& ray, float tIntervalMin, float tIntervalMax, 
	HitResult& hitResultOut) const
{
	assert(FMath::Equals(Vector3::Length(ray.Direction), 1.0f));

	Vector3 RayOrigToCenter = ray.Origin - Center;

	//CB: Since direction is normalised, this should always be 1
	float a = 1.0f; //Vector3::Dot(ray.Direction, ray.Direction);
	float b = 2.0f * Vector3::Dot(ray.Direction, RayOrigToCenter);
	float c = Vector3::Dot(RayOrigToCenter, RayOrigToCenter) - Radius * Radius;

	float t1;
	float t2;

	if(FMath::SolveQuadratic(a, b, c, t1, t2) == false)
	{
		return false;
	}

	if(t1 > t2)
	{
		std::swap(t1, t2);
	}

	if(t1 < tIntervalMin || t1 > tIntervalMax)
	{
		//outside interval, try next t
		t1 = t2;
		if(t1 < tIntervalMin || t1 > tIntervalMax)
		{
			//Both outside valid interval
			return false;
		}
	}

	hitResultOut.RayT = t1;
	hitResultOut.HitPoint = ray.PointAlongRayAtT(t1);
	
	//We already know that radius is the length of this vector, so manually normalise to save some cycles
	hitResultOut.HitNormal = (hitResultOut.HitPoint - Center) / Radius;

	return true;
}