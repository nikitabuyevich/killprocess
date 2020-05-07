#ifndef CMD_PARSE_H_
#define CMD_PARSE_H_
#include <string>

struct Arg
{
	std::string filename;
	std::string className;
};

// Perform basic operations related
// to command-line arguments.
namespace cmd
{
	// Parse a specific set of command-line arguments.
	Arg Parse(int argc, char** argv);
}

#endif //CMD_PARSE_H_
