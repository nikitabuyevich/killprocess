#ifndef WND_PROCESS_H_
#define WND_PROCESS_H_
#include <iostream>

// Perform basic operations around
// windows specific functions.
namespace wnd
{
	// Kill any running processes that match class name s.
	void KillProcessByClassName(std::string_view s);
}

#endif //WND_PROCESS_H_

