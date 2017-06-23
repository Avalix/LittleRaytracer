#pragma once
#include "Material.h"
#include "Graphics/Color.h"

namespace LittleRaytracer
{
	

	class LambertianDiffuse : public Material
	{
	public:
		LambertianDiffuse(const Color& albedo)
			: Albedo(albedo)
		{
			
		}

		Ray CalculateScatterRay(const HitResult& hitResult, UniformRandom rand) override;

		Color GetColor() override;

		Color Albedo;
	};
}
