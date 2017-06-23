#include "Base.h"

#include "Entities/Scene.h"
#include "Maths/HitResult.h"
#include "Graphics/Color.h"

using namespace LittleRaytracer;

void Scene::AddWorldObject(const SceneObjectPtr& worldObject)
{
	mWorldObjects.push_back(worldObject);
}
void Scene::RemoveWorldObject(const SceneObjectPtr& worldObject)
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

bool Scene::CastRayIntoScene(const Ray& ray, float tIntervalMin, float tIntervalMax, 
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

Color Scene::GetSkyColor(const Ray& ray)
{
	return Color(0.6f, 0.6f, 1.0f);
	float normVert = 0.5f * (ray.Direction.Y + 1.0f);
	return Color::Lerp(Color(1.0f, 1.0f, 1.0f), Color(0.5f, 0.7f, 1.0f), normVert);
}