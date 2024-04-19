#include "Data.hpp"

Data::Data() : some_data(13), some_flag(false) {}
Data::Data(Data const& src) { operator=(src); }
Data::~Data() {}
Data& Data::operator=(Data const& rhs)
	{ some_data = rhs.some_data; some_flag = rhs.some_flag; return *this; }
