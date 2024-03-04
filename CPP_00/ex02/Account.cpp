#include <iostream>
#include <iomanip>
#include <ctime>
#include "Account.hpp"

//---------//
/* PRIVATE */
//---------//

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account()
	: _accountIndex(_nbAccounts), _amount(0), _nbDeposits(0), _nbWithdrawals(0)
{
	Account::_nbAccounts++;
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << '\n';
}

void	Account::_displayTimestamp()
{
	time_t	timer;
	struct tm *	full_time;

	std::time(&timer);
	full_time = localtime(&timer);
	std::cout << '[' << full_time->tm_year + 1900;
	std::cout << std::setfill('0') << std::setw(2) << full_time->tm_mon + 1;
	std::cout << std::setfill('0') << std::setw(2) << full_time->tm_mday << '_';
	std::cout << std::setfill('0') << std::setw(2) << full_time->tm_hour;
	std::cout << std::setfill('0') << std::setw(2) << full_time->tm_min;
	std::cout << std::setfill('0') << std::setw(2) << full_time->tm_sec;
	std::cout << ']' << std::setw(0);
}

//--------//
/* PUBLIC */
//--------//

Account::Account(int initial_deposit)
	: _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << '\n';
}

Account::~Account()
{
	Account::_nbAccounts--;
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << '\n';
}

/* GET FUNCTIONS */
int	Account::getNbAccounts() {
	return Account::_nbAccounts;}

int	Account::getTotalAmount() {
	return Account::_totalAmount;}

int	Account::getNbDeposits() {
	return Account::_totalNbDeposits;}

int	Account::getNbWithdrawals() {
	return Account::_totalNbWithdrawals;}

/* DISPLAY FUNCTIONS */
void	Account::displayAccountsInfos()
{
	Account::_displayTimestamp();
	std::cout << " accounts:" << Account::_nbAccounts << ';';
	std::cout << "total:" << Account::_totalAmount << ';';
	std::cout << "deposits:" << Account::_totalNbDeposits << ';';
	std::cout << "withdrawals:" << Account::_totalNbWithdrawals << '\n';
}

void	Account::displayStatus() const
{
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ';';
	std::cout << "amount:" << this->_amount << ';';
	std::cout << "deposits:" << this->_nbDeposits << ';';
	std::cout << "withdrawals:" << this->_nbWithdrawals << '\n';
}

/* BANK STUFF */
void	Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ';';
	std::cout << "p_amount:" << this->_amount << ';';
	std::cout << "deposit:" << deposit << ';';
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	std::cout << "amount:" << this->_amount << ';';
	std::cout << "nb_deposits:" << this->_nbDeposits << '\n';
}

bool	Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ';';
	std::cout << "p_amount:" << this->_amount << ';';
	if (this->_amount < withdrawal)
	{
		std::cout << "withdrawal:refused" << '\n';
		return false;
	}
	std::cout << "withdrawal:" << withdrawal << ';';
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	std::cout << "amount:" << this->_amount << ';';
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals << '\n';
	return true;
}

int	Account::checkAmount() const {
	return this->_amount;}
