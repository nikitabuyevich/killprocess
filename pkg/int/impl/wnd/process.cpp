#include <wnd/process.h>
#include <windows.h>
#include <Tlhelp32.h>
#include <vector>

void wnd::KillProcessByName(std::string_view filename)
{
	const auto hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, NULL);
	PROCESSENTRY32 pEntry;
	pEntry.dwSize = sizeof(pEntry);
	auto hRes = Process32First(hSnapShot, &pEntry);
	while (hRes)
	{
		if (pEntry.szExeFile == filename)
		{
			const auto hProcess = OpenProcess(PROCESS_TERMINATE, false,
				static_cast<DWORD>(pEntry.th32ProcessID));
			if (hProcess != nullptr)
			{
				TerminateProcess(hProcess, 9);
				CloseHandle(hProcess);
			}
		}
		hRes = Process32Next(hSnapShot, &pEntry);
	}
	CloseHandle(hSnapShot);
}

void killProcess(HWND hWnd)
{
	DWORD processID;
	if (GetWindowThreadProcessId(hWnd, &processID))
	{
		const auto hProcess = OpenProcess(PROCESS_TERMINATE, false, processID);
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
