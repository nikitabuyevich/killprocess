#include <wnd/process.h>
#include <windows.h>

void killProcess(HWND hWnd)
{
	DWORD processID;
	if (GetWindowThreadProcessId(hWnd, &processID))
	{
		HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, processID);
		TerminateProcess(hProcess, 0);
		CloseHandle(hProcess);
	}
}

BOOL CALLBACK killProcessByClassName(HWND hWnd, LPARAM lCKill)
{
	const auto cKill = *reinterpret_cast<std::string_view*>(lCKill);
	char cName[cKill.length()];
	GetClassName(hWnd, cName, static_cast<int>(cKill.length()) + 1);
	if (cName == cKill)
	{
		killProcess(hWnd);
	}
	return true;
}

void wnd::KillProcessByClassName(std::string_view s)
{
	EnumWindows(killProcessByClassName, reinterpret_cast<LPARAM>(&s));
}

