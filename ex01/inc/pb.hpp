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
