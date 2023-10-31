#include <iostream>
#include <cstring>
using namespace std;

int main(int ac, char **av)
{
	if (ac == 1)
		cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else if (ac > 1)
	{
		for (int i=1; i<ac; i++)
			cout<<av[i];
	}
	cout << endl;
	return 0;
}
