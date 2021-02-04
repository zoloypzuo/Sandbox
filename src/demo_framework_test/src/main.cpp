/**
 * Copyright (c) 2013 David Young dayoung@goliathdesigns.com
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 *  1. The origin of this software must not be misrepresented; you must not
 *  claim that you wrote the original software. If you use this software
 *  in a product, an acknowledgment in the product documentation would be
 *  appreciated but is not required.
 *
 *  2. Altered source versions must be plainly marked as such, and must not be
 *  misrepresented as being the original software.
 *
 *  3. This notice may not be removed or altered from any source
 *  distribution.
 */

#include <cstdio>
#if defined(DEBUG) || defined(_DEBUG)
#define _CRTDBG_MAP_ALLOC

#include <cstdlib>  // NOTE include order is important
#include <crtdbg.h>
#endif

#include <vld.h>

#include "demo_framework_test/include/DemoTest.h"
#include "ogre3d/include/OgreException.h"

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"
#endif

int main(int argc, char* argv[])
{
    // Enable run-time memory check for debug builds.
#if defined(DEBUG) | defined(_DEBUG)
    printf("enable memory check");
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    // log to file
    HANDLE hLogFile = CreateFile("Memory Leaks.txt", GENERIC_WRITE, FILE_SHARE_WRITE,
                                 NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_WARN, hLogFile);
    _CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_ERROR, hLogFile);
    _CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_ASSERT, hLogFile);

	_CrtMemState s1, s2, s3;
	_CrtMemCheckpoint(&s1);
#endif
	{
		(void)argc;
		(void)argv;

		// Create application object
		DemoTest app;

		try
		{
			app.Run();
		}
		catch (Ogre::Exception& error)
		{
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
			MessageBox(
				NULL,
				error.getFullDescription().c_str(),
				"An exception has occured!",
				MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
			std::cerr << "An exception has occured: " <<
				error.getFullDescription().c_str() << std::endl;
#endif
		}
	}
#if defined(DEBUG) | defined(_DEBUG)
	_CrtMemCheckpoint(&s2);

	if (_CrtMemDifference(&s3, &s1, &s2))
		_CrtMemDumpStatistics(&s3);
#endif

    return 0;
}