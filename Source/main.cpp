//#define CHECK_FOR_MEMORY_LEAKS
#include "Base.h"

#include "Image.h"
#include "Color.h"

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

int main()
{
	std::cout << "Little Raytracer - Chris Butler(@avalix)\n\n";
	{
		Image testImage(400, 200);

		for(uint32_t x = 0; x < testImage.GetImageWidth(); ++x)
		{
			for(uint32_t y = 0; y < testImage.GetImageHeight(); ++y)
			{
				Color pixel( 
					(float(x) / float(testImage.GetImageWidth())), 
					1.0f - (float(y) / float(testImage.GetImageHeight())), 
					0.25f);

				testImage.SetPixel(x, y, pixel);
			}
		}
	}

	
	CheckForMemoryLeaks();

	std::cout << "DONE!\n";
	std::cout << "Press any key to continue...";
	getchar();
}