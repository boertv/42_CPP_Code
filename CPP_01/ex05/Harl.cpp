#include "Harl.hpp"
#include <iostream>

Harl::Couple::Couple(const char* level, void (Harl::*function)())
	: level(level), function(function) {}

void	Harl::debug() {
	std::cout << "[DEBUG] ";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-royal burger. I really do!\n"; }

void	Harl::info() {
	std::cout << "[INFO] ";
	std::cout << "I cannot believe adding extra bacon costs more money ? ";
	std::cout << "You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n"; }

void	Harl::warning() {
	std::cout << "[WARNING] ";
	std::cout << "I think I deserve to have some extra bacon for free. ";
	std::cout << "I've been coming for years whereas you started working here since last month...\n"; }

void	Harl::error() {
	std::cout << "[ERROR] ";
	std::cout << "This is unacceptable! I want to speak to the manager now!\n"; }

void	Harl::complain(std::string level)
{
	const int		harl_size = 4;
	Harl::Couple	couples[harl_size] = {Harl::Couple("DEBUG", &Harl::debug),
									Harl::Couple("INFO", &Harl::info),
									Harl::Couple("WARNING", &Harl::warning),
									Harl::Couple("ERROR", &Harl::error)};

	int	i = 0;
	while (i < harl_size && level.compare(couples[i].level))
		i++;
	if (i < harl_size)
		(this->*couples[i].function)();
}
