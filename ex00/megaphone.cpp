#include <iostream>
#include <cstring>


int main(int ac, char **av)
{
	if (ac == 1)
		std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else if (ac > 1)
	{
		for (int i=1; i<ac; i++)
		{
			for (int j=0; av[i][j]!='\0'; j++)
				av[i][j] = toupper(av[i][j]);
			std::cout<<av[i];
		}
	}
	std::cout << std::endl;
	return 0;
}
