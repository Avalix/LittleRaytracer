#pragma once
#include <vector>
#include "WorldObject.h"
#include <memory>

namespace LittleRaytracer
{
	using WorldObjectPtr = std::shared_ptr<WorldObject>;

	class WorldObject;

	class Scene : public WorldObject
	{		
	public:
		void AddWorldObject(const WorldObjectPtr& worldObject);
		void RemoveWorldObject(const WorldObjectPtr& worldObject);

		bool TryHitWithRay(const Ray& ray, float tIntervalMin, float tIntervalMax, 
			HitResult& hitResultOut) const override;
	private:
		std::vector<WorldObjectPtr> mWorldObjects;
	};
}
