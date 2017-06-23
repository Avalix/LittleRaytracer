#include "Base.h"

#include "Materials/Metal.h"
#include "Graphics/Color.h"
#include "Maths/Vector3.h"
#include "Maths/Random.h"
#include "Maths/HitResult.h"

using namespace LittleRaytracer;

Ray Metal::CalculateScatterRay(const HitResult& hitResult, UniformRandom rand)
{
	Vector3 reflectedDirection = Vector3::Reflect(hitResult.Ray.Direction, hitResult.HitNormal);
	reflectedDirection = Vector3::Normalize(reflectedDirection + Fuzziness * rand.GetRandomPointInUnitSphere());

	return Ray(hitResult.HitPoint, reflectedDirection);
}

Color Metal::GetColor()
{
	return Albedo;
}