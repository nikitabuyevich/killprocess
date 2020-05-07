#include <iostream>
#include <tuple>
#include <exception>
#include <boost/program_options.hpp>

namespace bpo = boost::program_options;

namespace cmd
{
	std::string Parse(int argc, char** argv)
	{
		bpo::options_description
			desc
			("killclass: Kill all processes that match a specified class name."
			 "\nUsage");
		try
		{
			desc.add_options()
				("help,h", "Display usage.")
				("class,c",
					bpo::value<std::string>()->value_name("string"),
					"Process class name to kill. e.g., \"ConsoleWindowClass\"");

			bpo::variables_map vm;
			bpo::store(bpo::parse_command_line(argc, argv, desc), vm);

			if (argc == 1 ||
				vm.count("help") ||
				!(vm.count("class")))
			{
				std::cout << desc;
				std::exit(1);
			}

			return {
				vm["class"].as<std::string>()
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

