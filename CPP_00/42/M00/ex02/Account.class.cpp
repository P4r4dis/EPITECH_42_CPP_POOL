#include "tests/Account.class.hpp"
#include <iostream>
#include <ctime>

#define ENSURE_DOUBLE_DIGIT(number) ((number < 10) ? "0" : "") << number

int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(void)  :   _accountIndex(getNbAccounts()), _amount(0),
                            _nbDeposits(0), _nbWithdrawals(0)
{
    _nbAccounts++;
    _totalAmount += _amount;
    Account::_displayTimestamp();
    std::cout   << "index:" << _accountIndex << ";"
                << "amount:" << _amount << ";"
                << "created" << std::endl;
}

Account::Account(int initial_deposit)   :   _accountIndex(getNbAccounts()), _amount(initial_deposit),
                                            _nbDeposits(0),
                                            _nbWithdrawals(0)
{
    _nbAccounts++;
    _totalAmount += _amount;
    Account::_displayTimestamp();
    std::cout   << "index:" << _accountIndex << ";"
                << "amount:" << _amount << ";"
                << "created" << std::endl;
}

Account::~Account(void)
{
	Account::_nbAccounts--;
	Account::_totalAmount -= _amount;
	Account::_totalNbDeposits -= _nbDeposits;
	Account::_totalNbWithdrawals -= _nbWithdrawals;

	Account::_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "closed" << std::endl;
}

int  Account::getNbAccounts(void)
{
    return Account::_nbAccounts;
}

int  Account::getTotalAmount(void)
{
    return Account::_totalAmount;
}

int  Account::getNbDeposits(void)
{
    return Account::_totalNbDeposits;
}

int  Account::getNbWithdrawals(void)
{
    return Account::_totalNbWithdrawals;
}

int Account::checkAmount(void) const
{
    return _amount;
}

bool Account::makeWithdrawal(int withdrawal)
{
    
    if (_amount > withdrawal)
    {
        int p_amount = _amount;
        _amount -= withdrawal;
        Account::_totalAmount -= withdrawal;
        _totalNbWithdrawals++;
        _nbWithdrawals++;
        Account::_displayTimestamp();
        std::cout << "index:" << _accountIndex << ";"
                << "p_amount:" << p_amount << ";"
                << "withdrawal:" << withdrawal << ";"
                << "amount:" << _amount << ";"
                << "nb_withdrawals:" << _nbWithdrawals << std::endl;
        return true;
    }
    else
    {
        Account::_displayTimestamp();
        std::cout
        << "index:" << _accountIndex << ";"
        << "p_amount:" << _amount << ";"
        << "withdrawal:refused" << std::endl;
    }
        return false;

}

void Account::makeDeposit(int deposit)
{
    if (deposit > 0)
    {
        int p_amount = _amount;
        _amount += deposit;
        _nbDeposits++;
        Account::_totalAmount += deposit;
        Account::_totalNbDeposits++;
        Account::_displayTimestamp();
        std::cout
        << "index:" << _accountIndex << ";"
        << "p_amount:" << p_amount << ";"
        << "deposit:" << deposit << ";"
        << "amount:" << _amount << ";"
        << "nb_deposits:" << _nbDeposits << std::endl;
    }
}

void    Account::displayAccountsInfos(void)
{
    Account::_displayTimestamp();
    std::cout   << "accounts:" << getNbAccounts() << ";"
                << "total:" << getTotalAmount() << ";"
                << "deposits:" << getNbDeposits() << ";"
                << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void    Account::displayStatus(void) const
{
    Account::_displayTimestamp();
    std::cout   << "index:" << _accountIndex << ";"
                << "amount:" << checkAmount() << ";"
                << "deposits:" << _nbDeposits << ";"
                << "withdrawals:" << _nbWithdrawals << std::endl;
}

void
	Account::_displayTimestamp(void)
{
    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);

    std::cout
		<< "["
		<< (now->tm_year + 1900)
        << ENSURE_DOUBLE_DIGIT((now->tm_mon + 1))
        << ENSURE_DOUBLE_DIGIT(now->tm_mday)
		<< "_"
        << ENSURE_DOUBLE_DIGIT(now->tm_hour)
        << ENSURE_DOUBLE_DIGIT(now->tm_min)
        << ENSURE_DOUBLE_DIGIT(now->tm_sec)
        << "] ";
}