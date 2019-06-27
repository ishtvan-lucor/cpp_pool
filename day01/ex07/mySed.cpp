#include "head.h"

void	mySed(char *filename, std::string str1, std::string str2)
{
	std::string 	newfile;
	std::ifstream	src;
	std::ofstream	dst;
	std::string		buffer;
	char buf;

	src.open(filename);
	if (src.is_open())
	{
		while(src.read(&buf, 1))
			buffer += buf;
		while ((int)buffer.find(str1) != -1)
			buffer.replace(buffer.find(str1), str1.size(), str2);
		src.close();
		newfile = filename;
		newfile += ".replace";
		dst.open(newfile.data());
		dst << buffer;
	}
	else
		std::cout << "Error: cannot open file \"" << filename << "\"."
		<< std::endl;
}

