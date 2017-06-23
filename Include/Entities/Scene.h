#pragma once
#include <vector>
#include "SceneObject.h"

namespace LittleRaytracer
{
	class SceneObject;

	class Scene
	{		
	public:
		void AddWorldObject(const SceneObjectPtr& worldObject);
		void RemoveWorldObject(const SceneObjectPtr& worldObject);

		bool CastRayIntoScene(const Ray& ray, float tIntervalMin, float tIntervalMax, 
			HitResult& hitResultOut) const;

		static Color GetSkyColor(const Ray& ray);
	private:
		std::vector<SceneObjectPtr> mWorldObjects;
	};
}
