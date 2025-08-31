#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>

using namespace std;

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    cout << " index:" << _accountIndex << ";amount:";
    cout << _amount << ";deposits:" << _nbDeposits;
    cout << ";withdrawals:" << _nbWithdrawals << endl;
}

Account::Account( int initial_deposit )
{
	_nbDeposits = 0;
	_nbWithdrawals = 0;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    cout << " index:" << _nbAccounts << ";amount:";
    cout << initial_deposit << ";created" << endl;
    _accountIndex = _nbAccounts;
    _amount = initial_deposit;
    _nbAccounts++;
}

Account::~Account( void )
{
    _displayTimestamp();
    cout << " index:" << _accountIndex << ";amount:";
    cout << _amount << ";closed" << endl;
}

void Account::_displayTimestamp(void)
{
    std::time_t now = std::time(0);
    std::tm *local_time = std::localtime(&now);
    cout << "[" << 1900 + local_time->tm_year << setw(2) << setfill('0') << 1 + local_time->tm_mon;
    cout << setw(2) << setfill('0') << local_time->tm_mday << "_";
    cout << setw(2) << setfill('0') << local_time->tm_hour << setw(2) << setfill('0') << local_time->tm_min;
    cout << setw(2) << setfill('0') << local_time->tm_sec << "]";
}

void    Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    cout << " accounts:" << _nbAccounts << ";";
    cout << "total:" << _totalAmount << ";";
    cout << "deposits:" << _totalNbDeposits << ";";
    cout << "withdrawals:" << _totalNbWithdrawals << endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
    cout << " index:" << _accountIndex;
    cout << ";p_amount:" << _amount;
    cout << ";withdrawal:";
    if (withdrawal > _amount)
    {
        cout << "refused" << endl;
        return (false);
    }
    _nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    _amount -= withdrawal;
    cout << withdrawal << ";amount:" << _amount;
    cout << ";nb_withdrawals:" << _nbWithdrawals << endl;
    return (true);
}

void	Account::makeDeposit( int deposit )
{
    _nbDeposits++;
    _totalAmount += deposit;
    _displayTimestamp();
    cout << " index:" << _accountIndex << ";p_amount:";
    cout << _amount << ";deposit:" << deposit;
    cout << ";amount:" << deposit + _amount;
    cout << ";nb_deposits:" << _nbDeposits << endl;
    _amount += deposit;
    _totalNbDeposits++;
}
