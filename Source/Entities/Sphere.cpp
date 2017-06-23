#include "Base.h"

#include "Entities/Sphere.h"
#include "Maths/HitResult.h"

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

	Vector3 hitPoint = ray.PointAlongRayAtT(t1);

	hitResultOut = HitResult(
		ray,
		t1,
		hitPoint,
		(hitPoint - Center) / Radius, //Length == Radius, so manually normalise to save perf 
		Material);

	return true;
}