//#define CHECK_FOR_MEMORY_LEAKS
#include "Base.h"

#include "Graphics/Image.h"
#include "Graphics/Color.h"
#include "Maths/Ray.h"
#include "Entities/Scene.h"
#include "Entities/Sphere.h"
#include "Graphics/Camera.h"
#include "Maths/Random.h"

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


Color GetColorforRay(const Ray& ray, const Scene scene)
{
	HitResult hitResult;

	if(scene.TryHitWithRay(ray, 0.0f, FLT_MAX, hitResult))
	{
		return Color(
			0.5f * (hitResult.HitNormal.X + 1.0f), 
			0.5f * (hitResult.HitNormal.Y + 1.0f), 
			0.5f * (hitResult.HitNormal.Z + 1.0f));
	}

	float normVert = 0.5f * (ray.Direction.Y + 1.0f);
	return Color::Lerp(Color(1.0f, 1.0f, 1.0f), Color(0.5f, 0.7f, 1.0f), normVert);
}

int main()
{
	std::cout << "Little Raytracer - Chris Butler(@avalix)\n\n";
	{
		Camera Camera(Vector3(0.0f, 0.0f, 0.0f), 4.0f, 2.0f, 1.0f);

		Image testImage(600, 300);

		Scene testScene;

		testScene.AddWorldObject(WorldObjectPtr(new Sphere(Vector3(0.0f, 0.0f,1.0f), 0.5f)));
		testScene.AddWorldObject(WorldObjectPtr(new Sphere(Vector3(0.0f, -100.5f, 1.0f), 100.0f)));

		UniformRandom rand(0.0f, 1.0f);
			
		const uint32_t NUM_SAMPLES_PER_PIXEL = 32;

		std::cout << "Generating Image 'Test.png' (" <<
			testImage.GetImageWidth() << "x" << testImage.GetImageHeight() <<
			")[" << NUM_SAMPLES_PER_PIXEL << " Samples Per Pixel]\n";

		for(uint32_t x = 0; x < testImage.GetImageWidth(); ++x)
		{
			for(uint32_t y = 0; y < testImage.GetImageHeight(); ++y)
			{
				std::cout << "Calculating Pixel " << x << "x" << y << "           \r";
				Color color(0.0f, 0.0f, 0.0f);
				for(uint32_t sampleID = 0; sampleID < NUM_SAMPLES_PER_PIXEL; ++sampleID)
				{
					float u = (float(x) + rand.GetValue()) / testImage.GetImageWidth();
					float v = 1.0f - ((float(y) + rand.GetValue()) / testImage.GetImageHeight());

					Ray ray = Camera.GetRay(u , v);
					color += GetColorforRay(ray, testScene);
				}

				color /= float(NUM_SAMPLES_PER_PIXEL);
				color.A = 1.0f;

				testImage.SetPixel(x, y, color);
			}
		}

		testImage.WriteImageToDisk("Test.png");
	}

	
	CheckForMemoryLeaks();

	std::cout << "DONE!\n";
}