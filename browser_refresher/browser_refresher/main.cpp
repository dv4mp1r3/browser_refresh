#include <windows.h>
#include <Shlwapi.h>

#pragma comment (lib, "Shlwapi.lib")

const wchar_t szTitlePart[] = L"Firefox";

BOOL CALLBACK EnumWindowsProc(HWND hWindow, LPARAM lParam)
{
	
	wchar_t szClassname[80];
	wchar_t szTitle[80];
	GetClassName(hWindow, szClassname, sizeof(szClassname));
	GetWindowText(hWindow, szTitle, sizeof(szTitle));

	if (StrStr(szTitle, szTitlePart))
	{
		PostMessage(hWindow, WM_KEYDOWN, VK_F5, 0);
		PostMessage(hWindow, WM_KEYUP, VK_F5, 0);
	}

	return TRUE;
}

int WINAPI wWinMain(__in HINSTANCE hInstance, __in_opt HINSTANCE hPrevInstance, __in LPWSTR lpCmdLine, __in int nShowCmd)
{	
	return EnumWindows(EnumWindowsProc, NULL);
}

