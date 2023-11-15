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
	void	infoCheck(std::string info);
	std::string getPnum() const { return pnum; }
	std::string getFname() const { return fname; }
	std::string getLname() const { return lname; }
	std::string getAka() const { return aka; }
	std::string getDs() const { return ds; }
};

void	Contact::infoCheck(std::string info)
{
	if (std::cin.eof())
		std::exit(1);
	if (info.empty())
	{
		while (1)
		{
			if (!info.empty())
				break ;
			std::cout << "YOU HAVE TO FILL IT// IF YOU WANT TO GO NEXT STEP\n";
			std::getline(std::cin, info);
		}
	}
}

void	Contact::infoAdd()
{
	std::cout << "[Phone NUMBER]:   ";
	std::getline(std::cin, pnum);
	infoCheck(pnum);
	std::cout << "[First NAME]  :   ";
	std::getline(std::cin, fname);
	infoCheck(fname);
	std::cout << "[Last NAME]   :   ";
	std::getline(std::cin, lname);
	infoCheck(lname);
	std::cout << "[Nick NAME]   :   ";
	std::getline(std::cin, aka);
	infoCheck(aka);
	std::cout << "[Dark Secret {Dont't worry. Its first Secret}]: ";
	std::getline(std::cin, ds);
	infoCheck(ds);
}

class	PhoneBook
{
private:
	Contact ct[INFO_CONST::MAX_LEN];
public:
	int idx;
	int total_idx;
	PhoneBook()
	{
		idx = 0;
		total_idx = 0;
	};
	std::string input;
	void	addContact();
	void	printPB(int idx);
	void	rulePB(std::string text);
	void	searchPB();
};

void	PhoneBook::addContact()
{
	total_idx++;
	if (total_idx >= INFO_CONST::MAX_LEN)
		total_idx = INFO_CONST::MAX_LEN;
	if (idx >= INFO_CONST::MAX_LEN)
		idx = idx % INFO_CONST::MAX_LEN ; 
	ct[idx].infoAdd();	
	idx++;
}

void	PhoneBook::printPB(int i)
{
	std::cout << "[Phone num]      : " << ct[i].getPnum() << std::endl;
	std::cout << "[Last Name]      : " << ct[i].getLname() << std::endl;
	std::cout << "[A.k.a]          : " << ct[i].getAka() << std::endl;
	std::cout << "[First Name]     : " << ct[i].getFname() << std::endl;
	std::cout << "[Darkest Secret] : " << ct[i].getDs() << std::endl;
}

void	PhoneBook::rulePB(std::string text)
{
	if (text.length() <= 10)
		std::cout << std::setw(10) << text;
	else
		std::cout << std::setw(10) << text.substr(0, 9) + ".";
}

void	PhoneBook::searchPB()
{
	if (this->idx == 0)
		std::cout << "❗️PhoneBook IS EMPTY💌 YOU CAN FILL IT UP\n" << std::endl;
	else 
	{
		int i = -1;
		int selectIdx;

		while (++i < total_idx)
		{
			std::cout << "|";
			std::cout << std::setw(10) << i + 1 << "|";
			rulePB(ct[i].getFname());
			std::cout << "|";
			rulePB(ct[i].getLname());
			std::cout << "|";
			rulePB(ct[i].getAka());
			std::cout << "|" << std::endl;
		}
		std::cout << "SELECT -I-N-D-E-X-🧢: "<< std::endl;
		std::cin >> selectIdx;
		if (std::cin.fail() || selectIdx > total_idx || selectIdx == 0 || isalnum(selectIdx))
		{
			while (1)
			{
				if (selectIdx <= total_idx && selectIdx != 0)
					break ;
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				std::cout << "SELECT JUST NUMERIC OR -R-I-G-H-T-🧵-I-N-D-E-X" << std::endl;
				std::cin >> selectIdx;
			}
		}
		if (std::cin.eof())
			std::exit(1);
		std::cin.ignore(1000, '\n');
		std::cin.clear();
		printPB(selectIdx - 1);
	}
}

int main(void)
{
	PhoneBook pb;
	
	std::cout << "\t💘 ☪️[MISSION] COMPLETE MY PHONE BOOK📱🍑\n" << std::endl;
	while (1)
	{
		std::cout << "COMMAND [ADD] [SEARCH] [EXIT] \n YOU MUST CHOOSE THIS ORDER __ IF NOT,, YOU DESERVE IT🐣" << std::endl;
		if (std::cin.eof())
			std::exit(1);
		std::cin>>pb.input;
		std::cin.ignore();
		if (pb.input == "ADD" || pb.input == "add")
			pb.addContact();
		else if (pb.input == "SEARCH" || pb.input == "search")
			pb.searchPB();
		else if (pb.input == "EXIT" || pb.input == "exit")
			break ;
		else
		{
			std::cout<< "------😈-------NOT VERIFY COMMAND------😈--------" << std::endl;
			std::cout<< "😈😈😈😈😈😈😈😈😈😈😈😈😈😈😈😈😈👿😈😈😈😈😈😈😈😈😈😈😈\n\n" << std::endl;
		}
	}
	return 0;
}
