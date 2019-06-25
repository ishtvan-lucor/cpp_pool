#include <iostream>
#include <cctype>

int	main(int ac, char **av)
{
	int	counter = 0;

	if (ac < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while (++counter < ac)
	{
		for (int i = 0; av[counter][i] != '\0'; i++)
		{
			if (std::islower((int) av[counter][i]))
				av[counter][i] = (char)std::toupper(av[counter][i]);
		}
		std::cout << av[counter];
	}
	std::cout << std::endl;
	return (0);
}