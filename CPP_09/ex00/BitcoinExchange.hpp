#ifndef BITCOINEXCHANGE_H
# define BITCOINEXCHANGE_H

#include <iostream>
#include <map>

class BitcoinExchange
{
	std::map<std::string, float> btc_history; // is float accurate enough?
	BitcoinExchange();

public:
	BitcoinExchange(char const* btc_file);
	BitcoinExchange(BitcoinExchange const& src);
	~BitcoinExchange();
	BitcoinExchange& operator=(BitcoinExchange const& rhs);

	bool empty() const;
};

#endif
