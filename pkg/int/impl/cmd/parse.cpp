#include <cmd/parse.h>
#include <iostream>
#include <exception>
#include <boost/program_options.hpp>

namespace bpo = boost::program_options;

namespace cmd
{
	Arg Parse(int argc, char** argv)
	{
		bpo::options_description
			desc
			("killprocess: Kill all processes by filename and class name."
			 "\nUsage");
		try
		{
			desc.add_options()
				("help,h", "Display usage.")
				("filename,f",
					bpo::value<std::string>()->value_name("string"),
					"Filename to kill. e.g., \"notepad.exe\"")
				("className,c",
					bpo::value<std::string>()->value_name("string"),
					"Process class name to kill. e.g., \"ConsoleWindowClass\"");

			bpo::variables_map vm;
			bpo::store(bpo::parse_command_line(argc, argv, desc), vm);

			if (argc == 1 ||
				vm.count("help") ||
				!(vm.count("className") && vm.count("filename")))
			{
				std::cout << desc;
				std::exit(1);
			}

			return {
				.filename = vm["filename"].as<std::string>(),
				.className = vm["className"].as<std::string>(),
			};
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << "\n";
			std::cout << desc;
			std::exit(1);
		}
	}
}

