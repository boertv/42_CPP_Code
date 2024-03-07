#include <iostream>
#include <fstream>
#include <string>

static int	flush_errmsg(std::ifstream& infile, std::ofstream& outfile, std::string msg)
{
	infile.close();
	outfile.close();
	std::cerr << msg << '\n';
	return 1;
}

static int	open_streams(std::ifstream& infile, std::ofstream& outfile, const char* file_name)
{
	std::string		string = file_name;

	infile.open(string);
	if (infile.fail())
	{
		std::cerr << "couldn't open '" << string << "'\n";
		return 1;
	}
	outfile.open(string.append(".replace"), std::ifstream::trunc);
	if (outfile.fail())
	{
		infile.close();
		std::cerr << "couldn't create/open " << string << '\n';
		return 1;
	}
	return (0);
}

static int	input_parsing(std::ifstream& infile, std::ofstream& outfile, std::string& s1)
{
	if (s1.empty())
		return flush_errmsg(infile, outfile, "the 'string to be replaced' can't be empty");
	if (s1.find('\n') != std::string::npos)
		return flush_errmsg(infile, outfile, "the 'string to be replaced' can't contain a newline");
	return 0;
}

static std::string	replace_in_string(std::string& inbuffer, std::string& s1, std::string s2)
{
	std::string		outbuffer;
	size_t			old_cursor;
	size_t			cursor;

	if (inbuffer.empty())
		return inbuffer;
	old_cursor = 0;
	cursor = inbuffer.find(s1);
	while (cursor != std::string::npos)
	{
		outbuffer.append(inbuffer, old_cursor, cursor);
		outbuffer.append(s2);
		old_cursor = cursor + s1.size();
		cursor = inbuffer.find(s1, old_cursor);
	}
	outbuffer.append(inbuffer, old_cursor);
	return outbuffer;
}

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "please provide a file and two strings\n";
		return 1;
	}

	std::ifstream	infile;
	std::ofstream	outfile;
	if (open_streams(infile, outfile, av[1]))
		return 1;

	std::string		s1 = av[2];
	std::string		s2 = av[3];
	if (input_parsing(infile, outfile, s1))
		return 1;

	std::string		inbuffer;
	getline(infile, inbuffer);
	outfile << replace_in_string(inbuffer, s1, s2);
	while (!infile.eof())
	{
		outfile << '\n';
		getline(infile, inbuffer);
		outfile << replace_in_string(inbuffer, s1, s2);
	}
	infile.close();
	outfile.close();
}
