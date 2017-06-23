#pragma once
#include <random>

namespace LittleRaytracer
{
	//Simple wrapper class around the c++11 random classes. Generated a random number in the interval
	// [min, max). By default the Intercal is [0.0f, 1.0f)
	class UniformRandom
	{
	public :
		UniformRandom() 
		: UniformRandom(0.0f, 1.0f)
		{
			
		}

		UniformRandom(float min, float max) 
		: UniformRandom(min, max, std::random_device()())
		{

		}

		UniformRandom(float min, float max, uint32_t seed)
		{
			SetSeed(seed);
			SetUniformDistribution(min, max);
		}

		void SetSeed(uint32_t seed)
		{
			mMTRandGen = std::mt19937(seed);
		}

		void SetUniformDistribution(float min, float max)
		{
			mUniformDist = std::uniform_real_distribution<float>(min, max);
		}

		float GetValue()
		{
			return mUniformDist(mMTRandGen);
		}

		Vector3 GetRandomPointInUnitSphere()
		{
			auto angleA = GetValue() * FMath::Constants::PI;
			auto angleB = GetValue() * FMath::Constants::TWO_PI;
			auto radius = FMath::Sqrt(GetValue());

			auto sinA = FMath::Sin(angleA);
			auto cosA = FMath::Cos(angleA);
			auto sinB = FMath::Sin(angleB);
			auto cosB = FMath::Cos(angleB);

			return Vector3(
				radius * sinA * cosB,
				radius * sinA * sinB,
				radius * cosA);
		}
		

	private:
		float mSeed;
		std::mt19937 mMTRandGen;
		std::uniform_real_distribution<float> mUniformDist;
	};
}
