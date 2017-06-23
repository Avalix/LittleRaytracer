#pragma once
#include "Material.h"
#include "Graphics/Color.h"

namespace LittleRaytracer
{
	class Metal : public Material
	{
	public:
		Metal(const Color& albedo, float fuzziness)
			: Albedo(albedo)
			, Fuzziness(fuzziness)
		{

		}

		Ray CalculateScatterRay(const HitResult& hitResult, UniformRandom rand) override;

		Color GetColor() override;

		Color Albedo;
		float Fuzziness;
	};
}
