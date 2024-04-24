#ifdef ARRAY_H
# ifndef ARRAY_T
#  define ARRAY_T

template <typename T>
Array<T>::Array()
	: _ptr(nullptr), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n)
	: _ptr(new T[n]), _size(n)
{
	for (size_t i = 0; i < _size; i++)
		_ptr[i] = T();
}

template <typename T>
Array<T>::Array(Array<T> const& src)
	: _ptr(nullptr), _size(0)
{
	this->operator=(src);
}

template <typename T>
Array<T>::~Array()
{
	delete [] _ptr;
}

template <typename T>
Array<T>& Array<T>::operator=(Array<T> const& rhs)
{
	this->~Array();
	_ptr = new T[rhs._size];
	_size = rhs._size;
	for (size_t i = 0; i < _size; i++)
		_ptr[i] = rhs[i];
	return *this;
}

template <typename T>
T& Array<T>::operator[](size_t i) const
{
	if (i < 0 || i >= _size)
		throw std::exception();
	return _ptr[i];
}

template <typename T>
size_t Array<T>::size() const
{
	return _size;
}

# endif
#endif
