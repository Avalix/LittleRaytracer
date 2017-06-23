#pragma once
#include <memory>

namespace LittleRaytracer
{
	class UniformRandom;
	class Color;
	class Ray;
	struct HitResult;

	class Material
	{
	public:
		Material() = default;

		Material(const Material& other) = default;
		Material& operator=(const Material& other) = default;
		Material(Material &&) = default;
		Material& operator=(Material &&) = default;

		virtual ~Material() = default;

		virtual Ray CalculateScatterRay(const HitResult& hitResult, UniformRandom rand) = 0;

		virtual Color GetColor() = 0;
	};

	using MaterialPtr = std::shared_ptr<Material>;
}
