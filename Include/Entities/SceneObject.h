#pragma once

#include "Maths/Ray.h"
#include <memory>
#include "Materials/Material.h"

namespace LittleRaytracer
{
	struct HitResult;

	//abstract base class representing any object in the world that can interact with rays
	class SceneObject
	{
		public:
			SceneObject(const MaterialPtr& material)
				: Material(material)
			{
				
			}

			SceneObject(const SceneObject& other) = default;
			SceneObject& operator=(const SceneObject& other) = default;
			SceneObject(SceneObject &&) = default;
			SceneObject& operator=(SceneObject &&) = default;

			virtual ~SceneObject() = default;

			//Returns true if the ray hits the object within the valid inverval for t along the ray. If true the 
			//hitResultsOut will be populated with the hit results, otherwise it will be invalid
			virtual bool TryHitWithRay(const Ray& ray, float tIntervalMin, float tIntervalMax,
				HitResult& hitResultOut) const = 0;

		MaterialPtr Material;
	};

	using SceneObjectPtr = std::shared_ptr<SceneObject>;
}
