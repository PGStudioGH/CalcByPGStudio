#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>

int CheckFullScreen()
{
	DWORD FS;
	GetConsoleDisplayMode(&FS);
	return FS;
}

void createWindow()
{
	RECT desktop;
	const HWND hDesktop = GetDesktopWindow();
	GetWindowRect(hDesktop, &desktop);
	int horizontal = desktop.right;

	HWND consoleWindow = GetConsoleWindow();
	SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);

	HMENU hMenu = GetSystemMenu(consoleWindow, 0);
	DeleteMenu(hMenu, GetMenuItemCount(hMenu) - 1, MF_BYPOSITION);
	DeleteMenu(hMenu, GetMenuItemCount(hMenu) - 1, MF_BYPOSITION);
	DeleteMenu(hMenu, GetMenuItemCount(hMenu) - 1, MF_BYPOSITION);

	CONSOLE_FONT_INFOEX fontInfo;
	GetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &fontInfo);
	fontInfo.cbSize = sizeof(fontInfo);
	fontInfo.FontWeight = FW_NORMAL;

	if (horizontal < 1024)
	{
		fontInfo.dwFontSize.X = 8;
		fontInfo.dwFontSize.Y = 12;
	}
	else {
		fontInfo.dwFontSize.X = 18;
		fontInfo.dwFontSize.Y = 24;
	}

	wcscpy(fontInfo.FaceName, L"Terminal");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &fontInfo);
}