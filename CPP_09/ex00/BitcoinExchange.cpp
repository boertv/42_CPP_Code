#include "BitcoinExchange.hpp"
#include <fstream>

/* STATIC HELPER FUNCTIONS */
static void trim_whitespace(std::string& str, bool trim_leading_nl = false)
{
	std::string::iterator it = str.begin();
	while (it != str.end() && (trim_leading_nl || *it != '\n') && std::isspace(*it))
		++it;
	if (str.begin() != it)
		str.erase(str.begin(), it);
	std::string::reverse_iterator rit = str.rbegin();
	while (rit != str.rend() && *rit != '\n' && std::isspace(*rit))
		++rit;
	it = rit.base();
	if (it != str.end())
		str.erase(it, str.end());
}

static bool check_nbr(std::string const& nbr, bool allow_dash = 0)
{
	bool point = allow_dash;
	for (std::string::const_iterator it = nbr.begin(); it != nbr.end(); ++it)
	{
		if (std::isdigit(*it))
			continue ;
		if (allow_dash && *it == '-')
			continue ;
		if (!point && *it == '.')
		{
			point = true;
			continue ;
		}
		return false;
	}
	return true;
}

static bool check_date(std::string const& date)
{
	if (date.size() != 10)
		return false;
	if (!check_nbr(date, true))
		return false;
	if (date.find('-') != 4 || date.find('-', 5) != 7 || date.find('-', 8) != std::string::npos)
		return false;
	int	month = (date[5] - '0') * 10 + (date[6] - '0');
	int	day = (date[8] - '0') * 10 + (date[9] - '0');
	if (month > 12)
		return false;
	if (month == 2)
	{
		int	year = (date[0] - '0') * 1000 + (date[1] - '0') * 100 + (date[2] - '0') * 10 + (date[3] - '0');
		if (!(year % 400) || (!(year % 4) && year % 100))
		{
			if (day > 29)
				return false;
		}
		else if (day > 28)
			return false;
	}
	else if ((month <= 7 && month % 2) || (month >=8 && !(month % 2)))
	{
		if (day > 31)
			return false;
	}
	else if (day > 30)
		return false;
	return true;
}

/*
CLASS BITCOINEXCHANGE
*/

/* CONSTRUCTORS AND OPERATOR= */
BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const& src) { this->operator=(src); }

BitcoinExchange::BitcoinExchange(char const* btc_file)
{
	std::ifstream ifs(btc_file);
	if (!ifs.good())
	{
		std::cout << "Error: could not open the database '" << btc_file << "'\n";
		return ;
	}
	while (ifs.good())
	{
		std::pair<std::string, double>	temp_pair;
		std::string						temp_nbr;
		std::getline(ifs, temp_pair.first, ',');
		if (ifs.eof() && !temp_pair.first.compare("\n"))
			break ;
		trim_whitespace(temp_pair.first, true);
		// check for a nl, print an error only with whatever is leading that nl
		std::getline(ifs, temp_nbr, '\n');
		trim_whitespace(temp_nbr);
		if (!temp_pair.first.compare("date") && !temp_nbr.compare("exchange_rate"))
			continue ;
		if (!check_nbr(temp_nbr) || !check_date(temp_pair.first))
		{
			std::cout << "Error: bad database element '" << temp_pair.first << "," << temp_nbr << "'\n";
			btc_history.clear();
			return ;
		}
		temp_pair.second = atof(temp_nbr.c_str());
		if (!btc_history.insert(temp_pair).second)
		{
			std::cout << "Error: failed to build database element '" << temp_pair.first << "," << temp_nbr << "'\n";
			btc_history.clear();
			return ;
		}
	}
	if (btc_history.empty())
		std::cout << "Error: empty database\n";
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const& rhs)
{
	btc_history = rhs.btc_history;
	return *this;
}

/* MEMBER FUNCTIONS */
bool BitcoinExchange::empty() const
{
	return btc_history.empty();
}
