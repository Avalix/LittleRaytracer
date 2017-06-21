//#define CHECK_FOR_MEMORY_LEAKS
#include "Base.h"

#include "Image.h"
#include "Color.h"
#include "Maths/Ray.h"

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

bool HitSphere(const Vector3& sphereCenter, float radius, const Ray& ray)
{
	Vector3 RayOrigToCenter = ray.Origin - sphereCenter;
	float a = Vector3::Dot(ray.Direction, ray.Direction);
	float b = 2.0f * Vector3::Dot(ray.Direction, RayOrigToCenter);
	float c = Vector3::Dot(RayOrigToCenter, RayOrigToCenter) - radius * radius;

	float discrim = b*b - 4 * a * c;

	return discrim > 0.0f;
}

Color GetColorforRay(const Ray& ray)
{
	if(HitSphere(Vector3(0.0f, 0.0f, 1.0f), 0.5f, ray))
	{
		return Color(0.5f, 0.5f, 0.5f);
	}
	float normVert = 0.5f * (ray.Direction.Y + 1.0f);
	return Color::Lerp(Color(1.0f, 1.0f, 1.0f), Color(0.5f, 0.7f, 1.0f), normVert);
}

int main()
{
	std::cout << "Little Raytracer - Chris Butler(@avalix)\n\n";
	{
		Image testImage(600, 300);

		//World starts from top left, going right/down
		Vector3 UpperLeftCorner(-2.0f, 1.0f, 1.0f);
		Vector3 WorldWidth(4.0f, 0.0f, 0.0f);
		Vector3 WorldHeight(0.0f, -2.0f, 0.0f);
		Vector3 CameraOrigin(0.0f, 0.0f, 0.0f);

		for(uint32_t x = 0; x < testImage.GetImageWidth(); ++x)
		{
			for(uint32_t y = 0; y < testImage.GetImageHeight(); ++y)
			{
				float u = float(x) / testImage.GetImageWidth();
				float v = float(y) / testImage.GetImageHeight();

				if(x == 250 && y == 150)
				{
					int a = 0;
				}

				Vector3 rayDirection = UpperLeftCorner + (u * WorldWidth) + (v * WorldHeight);
				rayDirection = Vector3::Normalize(rayDirection);

				Ray ray(CameraOrigin, rayDirection);
				Color color = GetColorforRay(ray);

				testImage.SetPixel(x, y, color);
			}
		}

		testImage.WriteImageToDisk("Test.png");
	}

	
	CheckForMemoryLeaks();

	std::cout << "DONE!\n";
}