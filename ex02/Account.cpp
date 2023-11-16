#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


void	Account::_displayTimestamp(void)
{
	std::time_t now = std::time(nullptr);
    std::tm *ptm = std::localtime(&now);

    char buffer[18];

    std::strftime(buffer, 18, "[%Y%m%d_%H%M%S]", ptm);
    std::cout << buffer;
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "\taccounts:" << getNbAccounts() << \
	";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawls:" \
	<< getNbWithdrawals() << std::endl;
	_nbAccounts = 0;
}

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_totalAmount += _amount;
	_totalNbDeposits = 0;
	_totalNbWithdrawals = 0;
	Account::_displayTimestamp();
	std::cout << "\tindex:" << _accountIndex << \
	";amount:" << _amount << ";created" << std::endl;
	_nbAccounts++;
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << "\tindex:" << _accountIndex << \
	";amount:" <<  _amount << ";deposit:" <<  _nbDeposits << ";withdrawls:" << \
	_nbWithdrawals <<std::endl;
	_nbAccounts++;
}

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}


int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void Account::makeDeposit( int deposit )
{
	_totalAmount += deposit;
	_nbDeposits = 1;
	_amount += deposit;
	Account::_displayTimestamp();
	std::cout << "\tindex:" << _accountIndex << \
	";p_amount:" <<  _amount - deposit << ";deposit:" <<  deposit << ";amount:" << \
	_amount << ";nb_deposits:" << _nbDeposits << std::endl;
	_totalNbDeposits++;
}

bool Account::makeWithdrawal( int withdrawal )
{
	if (_amount - withdrawal <= 0)
	{
		_displayTimestamp();
		std::cout << "\tindex:" << _accountIndex << \
		";p_amount:" <<  _amount << ";withdrawal:refused" << std::endl;
		return false;
	}
	else
	{
		_nbWithdrawals = 1;
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_displayTimestamp();
		std::cout << "\tindex:" << _accountIndex << \
		";p_amount:" <<  _amount + withdrawal << ";withdrawal:" <<  withdrawal << ";amount:" << \
		_amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		_totalNbWithdrawals++;
		return true;
	}
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "\tindex:" << _accountIndex << \
	";amount:" <<  _amount << ";closed" << std::endl;
}