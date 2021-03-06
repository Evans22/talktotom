// TalkTom.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


CGlobal g_global;

CCamShiftHelper g_camshiftHelper;

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	init();


	HANDLE hThreadSound;
	hThreadSound = (HANDLE)_beginthreadex(NULL, NULL, soundThread, NULL, NULL, NULL);
	CloseHandle(hThreadSound);

	g_camshiftHelper._OpenAdjustWindow();

	arVideoCapStart();
	argMainLoop(mouseEvent, keyEvent, mainLoop );

	g_camshiftHelper._CloseAdjustWindow();

	return (0);
}

