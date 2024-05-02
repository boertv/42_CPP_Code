#include "RPN.hpp"
#include <limits>

/* CONSTRUCTORS AND = OVERLOAD */
RPN::RPN() {}
RPN::RPN(RPN const& src) { this->operator=(src); }
RPN& RPN::operator=(RPN const& rhs) {
	work_mem = rhs.work_mem; equation = rhs.equation; return *this; }

RPN::~RPN() {}

RPN::RPN(std::string const& input)
{
	for (std::string::const_reverse_iterator rit = input.rbegin(); rit != input.rend(); ++rit)
	{
		if (std::isspace(*rit))
			continue ;
		if (std::isdigit(*rit) || is_operation(*rit))
		{
			if (std::next(rit) != input.rend() && !std::isspace(*std::next(rit)))
				throw std::invalid_argument("Error");
			equation.push(*rit);
			continue ;
		}
		throw std::invalid_argument("Error");
	}
}

/* MEMBER FUNCTIONS */
bool RPN::is_operation(char const c) const
{
	std::string const operations("+-/*");
	if (operations.find(c) == std::string::npos)
		return false;
	return true;
}

void RPN::move_to_mem()
{
	work_mem.push(equation.top() - '0');
	equation.pop();
}

void RPN::do_operation()
{
	if (work_mem.size() < 2)
		throw std::invalid_argument("Error");

	long temp_long = static_cast<long>(work_mem.top());
	work_mem.pop();
	switch (equation.top())
	{
		case '+':
			temp_long = static_cast<long>(work_mem.top()) + temp_long;
			break;
		case '-':
			temp_long = static_cast<long>(work_mem.top()) - temp_long;
			break;
		case '/':
			temp_long = static_cast<long>(work_mem.top()) / temp_long;
			break;
		case '*':
			temp_long = static_cast<long>(work_mem.top()) * temp_long;
			break;
	}
	if (temp_long > std::numeric_limits<int>::max() || temp_long < std::numeric_limits<int>::min())
		throw std::invalid_argument("Error: overflow");
	equation.pop();
	work_mem.top() = static_cast<int>(temp_long);
}

void RPN::run_calc()
{
	while (!equation.empty())
	{
		if (std::isdigit(equation.top()))
			move_to_mem();
		else
			do_operation();
	}
	if (work_mem.size() != 1)
		throw std::invalid_argument("Error");
	std::cout << work_mem.top() << std::endl;
}
