#include "BitcoinExchange.hpp"
#include <fstream>

/*
STATIC HELPER FUNCTIONS
*/
static void trim_whitespace(std::string& str)
{
	std::string::iterator it = str.begin();
	while (it != str.end() && std::isspace(*it))
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

static bool check_nbr(std::string const& nbr, bool ban_comma = false)
{
	if (nbr.empty())
		return false;

	std::string::const_iterator it = nbr.begin();
	if (*it == '-')
		return false;
	for (; it != nbr.end(); ++it)
	{
		if (*it == '.' && !ban_comma)
		{
			ban_comma = true;
			continue ;
		}
		if (!std::isdigit(*it))
			return false;
	}
	return true;
}

static bool check_date(std::string const& date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	if (!check_nbr(date.substr(0, 4), true) || !check_nbr(date.substr(5, 2), true) || !check_nbr(date.substr(8), true))
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

BitcoinExchange::BitcoinExchange(std::string const& btc_file)
{
	std::ifstream ifs(btc_file);
	if (!ifs.good())
		throw std::invalid_argument("could not open the database: " + btc_file);
	while (ifs.good())
	{
		std::string line;
		std::getline(ifs, line);
		if (line.empty())
			continue ;
		if (line.find(',') == std::string::npos)
			throw std::invalid_argument("bad database element: " + line);
		std::pair<std::string, double> temp_pair;
		temp_pair.first = line.substr(0, line.find(','));
		std::string temp_nbr = line.substr(line.find(',') + 1);
		trim_whitespace(temp_pair.first);
		trim_whitespace(temp_nbr);
		if (!temp_pair.first.compare("date") && !temp_nbr.compare("exchange_rate"))
			continue ;
		if (!check_nbr(temp_nbr) || !check_date(temp_pair.first))
			throw std::invalid_argument("bad database element: " + temp_pair.first + "," + temp_nbr);
		temp_pair.second = static_cast<float>(atof(temp_nbr.c_str()));
		if (!btc_history.insert(temp_pair).second)
			throw std::invalid_argument("failed to build database element: " + temp_pair.first + "," + temp_nbr);
	}
	if (btc_history.empty())
		throw std::invalid_argument("empty database");
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

void BitcoinExchange::process_line(std::string const& input_line) const
{
	if (input_line.empty())
		return ;
	if (input_line.find("|") == std::string::npos)
		throw std::invalid_argument("bad input: " + input_line);
	std::string date = input_line.substr(0, input_line.find("|"));
	std::string amount = input_line.substr(input_line.find("|") + 1);
	trim_whitespace(date);
	trim_whitespace(amount);
	if (!date.compare("date") && !amount.compare("value"))
		return ;
	if (!check_date(date))
		throw std::invalid_argument("bad date: " + date); // also differentiate?
	if (!check_nbr(amount))
		throw std::invalid_argument("bad value: " + amount); // differentiate between negative, bigger than 1000, not a nbr, ..?

	std::cout << date << " => " << amount << " = ";
	std::cout << (static_cast<float>(std::atof(amount.c_str())) * (*btc_history.lower_bound(date)).second);
	std::cout << "\n";
}

void BitcoinExchange::process_file(std::string const& input_file) const
{
	std::string		line;
	std::ifstream	ifs(input_file);
	if (!ifs.good())
		throw std::invalid_argument("could not open " + input_file);
	while (ifs.good())
	{
		std::getline(ifs, line);
		try {
			process_line(line); }
		catch (std::exception const& e) {
			std::cout << "Error: " << e.what() << "\n"; }
	}
}
