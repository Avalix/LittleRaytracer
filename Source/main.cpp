//#define CHECK_FOR_MEMORY_LEAKS
#include "Base.h"

#include "Graphics/Image.h"
#include "Graphics/Color.h"
#include "Maths/Ray.h"
#include "Entities/Scene.h"
#include "Entities/Sphere.h"
#include "Graphics/Camera.h"
#include "Maths/Random.h"
#include "Maths/HitResult.h"
#include "Materials/LambertianDiffuse.h"
#include "Materials/Metal.h"

using namespace LittleRaytracer;

#if defined(CHECK_FOR_MEMORY_LEAKS)
void CheckForMemoryLeaks()
{
	std::cout << "\n\n ====== Dumping Memory Leaks (If Any Exist) ======\n\n";
	_CrtSetReportMode( _CRT_WARN, _CRTDBG_MODE_FILE );
	_CrtSetReportFile( _CRT_WARN, _CRTDBG_FILE_STDOUT );
	_CrtSetReportMode( _CRT_ERROR, _CRTDBG_MODE_FILE );
	_CrtSetReportFile( _CRT_ERROR, _CRTDBG_FILE_STDOUT );
	_CrtSetReportMode( _CRT_ASSERT, _CRTDBG_MODE_FILE );
	_CrtSetReportFile( _CRT_ASSERT, _CRTDBG_FILE_STDOUT );
	_CrtDumpMemoryLeaks(); 
	std::cout << "\n\n =========== Memory Leak Dump Finished ==========\n\n";
}
#else
void CheckForMemoryLeaks()
{
	//do nothing
}
#endif

template<class Base, class Derived, class ... Args>
std::shared_ptr<Base> MakeSharedOfBase(Args && ... args)
{
	return std::static_pointer_cast<Base>(std::make_shared<Derived>(args...));
}


Color DoTrace(const Ray& ray, const Scene& scene, UniformRandom& rand, int depth)
{
	if(depth <= 0)
	{
		//terminate Ray
		return Color(0.0f, 0.0f, 0.0f);
	}

	HitResult hitResult;

	if(scene.CastRayIntoScene(ray, 0.001f, FLT_MAX, hitResult))
	{
		Ray nextRay = hitResult.Material->CalculateScatterRay(hitResult, rand);
		return hitResult.Material->GetColor() * DoTrace(nextRay, scene, rand, depth-1);
	}

	//hit nothing, so sample sky
	return Scene::GetSkyColor(ray);
}

const uint32_t NUM_SAMPLES_PER_PIXEL = 16;
const uint32_t MAX_RAY_DEPTH = 8;

int main()
{
	std::cout << "Little Raytracer - Chris Butler(@avalix)\n\n";
	{
		Camera Camera(Vector3(0.0f, 0.0f, 0.0f), 4.0f, 2.0f, 1.0f);

		Image testImage(400, 200);

		Scene testScene;

		testScene.AddWorldObject(MakeSharedOfBase<SceneObject, Sphere>(
			Vector3(0.0f, 0.0f, 1.0f), 
			0.5f, 
			MakeSharedOfBase<Material, LambertianDiffuse>(
				Color(0.8f, 0.3f, 0.3f)
				)
			));

		testScene.AddWorldObject(MakeSharedOfBase<SceneObject, Sphere>(
			Vector3(0.0f, -100.5f, 1.0f), 
			100.0f, 
			MakeSharedOfBase<Material, LambertianDiffuse>(
				Color(0.8f, 0.8f, 0.0f)
				)
			));	

		testScene.AddWorldObject(MakeSharedOfBase<SceneObject, Sphere>(
			Vector3(1.0f, 0.0f, 1.0f), 
			0.5f, 
			MakeSharedOfBase<Material, Metal>(
				Color(0.8f, 0.6f, 0.2f),
				0.0f
				)
			));

		testScene.AddWorldObject(MakeSharedOfBase<SceneObject, Sphere>(
			Vector3(-1.0f, 0.0f, 1.0f), 
			0.5f, 
			MakeSharedOfBase<Material, Metal>(
				Color(0.8f, 0.8f, 0.8f),
				0.25f
				)
			));

		UniformRandom rand(0.0f, 1.0f);
			
		

		std::cout << "Generating Image 'Test.png' (" <<
			testImage.GetImageWidth() << "x" << testImage.GetImageHeight() <<
			")[" << NUM_SAMPLES_PER_PIXEL << " Samples Per Pixel]\n";

		for(uint32_t x = 0; x < testImage.GetImageWidth(); ++x)
		{
			for(uint32_t y = 0; y < testImage.GetImageHeight(); ++y)
			{
				//std::cout << "Calculating Pixel " << x << "x" << y << "           \r";
				Color color(0.0f, 0.0f, 0.0f);
				for(uint32_t sampleID = 0; sampleID < NUM_SAMPLES_PER_PIXEL; ++sampleID)
				{
					float u = (float(x) + rand.GetValue()) / testImage.GetImageWidth();
					float v = 1.0f - ((float(y) + rand.GetValue()) / testImage.GetImageHeight());

					Ray ray = Camera.GetRay(u , v);
					color += DoTrace(ray, testScene, rand, MAX_RAY_DEPTH);
				}

				color /= float(NUM_SAMPLES_PER_PIXEL);
				color.A = 1.0f;

				const float GAMMA_CORRECTION_VALUE = 1.0f / 2.2f;

				color = Color::ApplyGamma(color, GAMMA_CORRECTION_VALUE);

				testImage.SetPixel(x, y, color);
			}
		}

		testImage.WriteImageToDisk("Test.png");
	}

	
	CheckForMemoryLeaks();

	std::cout << "DONE!\n";
}