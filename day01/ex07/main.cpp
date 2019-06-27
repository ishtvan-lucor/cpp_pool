#include "head.h"

int		main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "usage: " << argv[0];
		std::cout << " <filename> <string1> <string2>" << std::endl;
	}
	else
		mySed(argv[1], std::string(argv[2]), std::string(argv[3]));
	return (0);
}