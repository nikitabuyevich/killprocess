#include <cmd/parse.h>
#include <wnd/process.h>

int main(int argc, char** argv)
{
	const auto arg = cmd::Parse(argc, argv);
	wnd::KillProcessByName(arg.filename);
	wnd::KillProcessByClassName(arg.className);
	return 0;
}
