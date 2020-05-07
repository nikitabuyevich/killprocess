#ifndef CMD_PARSE_H_
#define CMD_PARSE_H_
#include <tuple>
#include <string>

// Perform basic operations related
// to command-line arguments.
namespace cmd
{
	// Parse a specific set of command-line arguments.
	std::string Parse(int argc, char** argv);
}

#endif //CMD_PARSE_H_
