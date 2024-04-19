#ifndef DATA_H
# define DATA_H

struct Data
{
	Data();
	Data(Data const& src);
	~Data();
	Data& operator=(Data const& rhs);

	int		some_data;
	bool	some_flag;
};


#endif
