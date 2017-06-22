#include "Base.h"

#include "Entities/Scene.h"

using namespace LittleRaytracer;

void Scene::AddWorldObject(const WorldObjectPtr& worldObject)
{
	mWorldObjects.push_back(worldObject);
}
void Scene::RemoveWorldObject(const WorldObjectPtr& worldObject)
{
	auto it= find(mWorldObjects.begin(),mWorldObjects.end(), worldObject);
	auto index = it - mWorldObjects.begin();

	if(mWorldObjects.size() >= 2)
	{
		swap(mWorldObjects[index], mWorldObjects.back());
		mWorldObjects.pop_back();
	}
	else
	{
		mWorldObjects.clear();
	}
}

bool Scene::TryHitWithRay(const Ray& ray, float tIntervalMin, float tIntervalMax, 
	HitResult& hitResultOut) const
{
	HitResult groupTempResult;

	bool hitAnything = false;
	float closestSofar = tIntervalMax;

	int numObjects =  mWorldObjects.size();

	for(int i = 0; i <numObjects; ++i)
	{
		auto worldObject = mWorldObjects[i];

		if(worldObject->TryHitWithRay(ray, tIntervalMin, closestSofar, groupTempResult))
		{
			hitAnything = true;
			closestSofar = groupTempResult.RayT;
			hitResultOut = groupTempResult;
		}
	}

	return hitAnything;
}