#include <iostream>
#include <string>
#include <iomanip>

namespace INFO_CONST
{
	enum
	{
		MAX_LEN = 8
	};
}

class	Contact
{
private:
	std::string pnum;
	std::string fname;
	std::string lname;
	std::string aka;
	std::string ds;
public:
	void	infoAdd();
	std::string getPnum() const { return pnum; }
	std::string getFname() const { return fname; }
	std::string getLname() const { return lname; }
	std::string getAka() const { return aka; }
	std::string getDs() const { return ds; }
};


void	Contact::infoAdd()
{
	std::cout << "Phone NUMBER: ";
	std::getline(std::cin, pnum);
	std::cout << "First NAME: ";
	std::getline(std::cin, fname);
	std::cout << "Last NAME: ";
	std::getline(std::cin, lname);
	std::cout << "Nick NAME: ";
	std::getline(std::cin, aka);
	std::cout << "Dark Secret {Dont't worry. Its first Secret}: ";
	std::getline(std::cin, ds);
}
class	PhoneBook
{
private:
	Contact ct[INFO_CONST::MAX_LEN];
public:
	int idx = 0;
	std::string input;
	void addContact() {
        if (idx < INFO_CONST::MAX_LEN) {
            ct[idx % 8].infoAdd();
        }
        idx++;
    }
	void	printPB(int idx);
	void	rulePB(std::string text);
	void	searchPB();
};

void	PhoneBook::printPB(int i)
{
	std::cout << "Phone num : " << ct[i].getPnum() << std::endl;
	std::cout << "Last Name : " << ct[i].getLname() << std::endl;
	std::cout << "Aka : " << ct[i].getAka() << std::endl;
	std::cout << "First Name : " << ct[i].getFname() << std::endl;
	std::cout << "Darkest Secret : " << ct[i].getDs() << std::endl;
}

void	PhoneBook::rulePB(std::string text)
{
	if (text.length() <= 10)
		std::cout << std::right << text;
	else
		std::cout << std::setw(10) << text.substr(0,8) + ".";
}

void	PhoneBook::searchPB()
{
	if (this->idx == 0)
		std::cout << "PhoneBook is EMPTY!!" << std::endl;
	else 
	{
		int i = -1;
		int selectIdx;

		while (++i < idx)
		{
			std::cout << "|";
			std::cout << i + 1 << "|";
			rulePB(ct[i].getFname());
			std::cout << "|";
			rulePB(ct[i].getLname());
			std::cout << "|";
			rulePB(ct[i].getAka());
			std::cout << "|" << std::endl;
		}
		std::cout << "Select Index: "<< std::endl;
		std::cin >> selectIdx;
		printPB(selectIdx - 1);
	}
}



int main(void)
{
	PhoneBook pb;

	while (1)
	{
		std::cout << "Command : ADD, SEARCH, EXIT" << std::endl;
		std::cin>>pb.input;
		std::cin.ignore();
		if (pb.input == "ADD")
			pb.addContact();
		else if (pb.input == "EXIT")
			break ;
		else if (pb.input == "SEARCH")
			pb.searchPB();
		else
			std::cout<< "NOT VERIFY COMMAND" << std::endl;
	}
	return 0;
}
