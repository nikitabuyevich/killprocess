#include <cmd/parse.h>
#include <wnd/process.h>

int main(int argc, char** argv)
{
	const auto arg = cmd::Parse(argc, argv);
	if (!arg.filename.empty())
	{
		wnd::KillProcessByName(arg.filename);
	}
	if (!arg.className.empty())
	{
		wnd::KillProcessByClassName(arg.className);
	}
	return 0;
}
