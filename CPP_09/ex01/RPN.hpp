#ifndef RPN_H
# define RPN_H

# include <iostream>
# include <stack>

class RPN
{
	std::stack<int> work_mem;
	std::stack<char> equation;

	RPN();
	RPN(RPN const& src);
	RPN& operator=(RPN const& rhs);

	bool is_operation(char const c) const;
	void move_to_mem();
	void do_operation();

public:
	~RPN();
	RPN(std::string const& input);

	void run_calc();
};

#endif
