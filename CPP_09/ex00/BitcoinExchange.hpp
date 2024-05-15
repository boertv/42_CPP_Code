#ifndef BITCOINEXCHANGE_H
# define BITCOINEXCHANGE_H

#include <iostream>
#include <map>

class BitcoinExchange
{
	std::map<std::string, float> btc_history;
	BitcoinExchange();

public:
	BitcoinExchange(std::string const& btc_file);
	BitcoinExchange(BitcoinExchange const& src);
	~BitcoinExchange();
	BitcoinExchange& operator=(BitcoinExchange const& rhs);

	bool empty() const;
	void process_line(std::string const& input_line) const;
	void process_file(std::string const& input_file) const;
};

#endif
