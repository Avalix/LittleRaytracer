#include "Base.h"

#include "Materials/LambertianDiffuse.h"
#include "Graphics/Color.h"
#include "Maths/Vector3.h"
#include "Maths/Random.h"
#include "Maths/HitResult.h"

using namespace LittleRaytracer;

Ray LambertianDiffuse::CalculateScatterRay(const HitResult& hitResult, UniformRandom rand)
{
	Vector3 bounceRayTarget = hitResult.HitPoint + hitResult.HitNormal + rand.GetRandomPointInUnitSphere();
	Vector3 bouceDir = Vector3::Normalize(bounceRayTarget - hitResult.HitPoint);

	return Ray(hitResult.HitPoint, bouceDir);
}

Color LambertianDiffuse::GetColor()
{
	return Albedo;
}