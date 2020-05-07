#include <cmd/parse.h>
#include <wnd/process.h>

int main(int argc, char** argv)
{
	auto className = cmd::Parse(argc, argv);
	wnd::KillProcessByClassName(className);
	return 0;
}
