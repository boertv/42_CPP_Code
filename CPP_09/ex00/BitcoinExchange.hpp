#ifndef BITCOINEXCHANGE_H
# define BITCOINEXCHANGE_H

#include <iostream>
#include <map>

class BitcoinExchange
{
	std::map<std::string, float> btc_history; // is float accurate enough? i dunno that's what they asked innit

public:
	BitcoinExchange();
	BitcoinExchange(std::string const& btc_file); // maybe check if file is really closed in all cases
	BitcoinExchange(BitcoinExchange const& src);
	~BitcoinExchange();
	BitcoinExchange& operator=(BitcoinExchange const& rhs);

	bool	empty() const;
	void	process_line(std::string const& input_line) const;
	void	process_file(std::string const& input_file) const;
};

#endif
