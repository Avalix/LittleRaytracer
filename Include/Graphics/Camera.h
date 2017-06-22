#pragma once

#include "Maths/Ray.h"

namespace LittleRaytracer
{
	class Camera
	{
	public:
		Camera(Vector3 position, float nearPlaneWidth, float nearPlaneHeight, float NearPlaneDistance)
			: Position(position)
			, NearPlaneWidth(nearPlaneWidth)
			, NearPlaneHeight(nearPlaneHeight)
			, NearPlaneDistance(NearPlaneDistance)
		{
			
		}

		Ray GetRay(float screenU, float screenV) const
		{
			Vector3 rayDirection = Vector3(
				-NearPlaneWidth * 0.5f + screenU * NearPlaneWidth,
				-NearPlaneHeight * 0.5f + screenV * NearPlaneHeight,
				NearPlaneDistance);

			rayDirection = Vector3::Normalize(rayDirection);

			return Ray(Position, rayDirection);
		}

		Vector3 Position;
		float NearPlaneWidth;
		float NearPlaneHeight;
		float NearPlaneDistance;
	};
}