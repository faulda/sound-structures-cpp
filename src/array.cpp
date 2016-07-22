#include <cassert>

#include "array.hpp"


// Constructs an Array with the specified number of elements. Size must be
// greater than 0.
template <class T>
Array<T>::Array(int64_t size)
{
	assert(size > 0);

	this.size = size;
	this.elements = new T[size];
}

// Destroys the Array.
template <class T>
Array<T>::~Array()
{
	delete this.elements[];
	this.elements = nullptr;
	this.size = 0;
}

// Returns the size of this array.
template <class T>
int64_t Array<T>::size() const 
{
	return size;
}

// Returns a const reference to the element at index.
template <class T>
const T& Array<T>::operator[](int64_t index) const
{
	assert(index >= 0 && index < size);

	return elements[index];
}

// Returns a modifiable reference to the element at index.
template <class T>
T& Array<T>::operator[](int64_t index)
{
	assert(index >= 0 && index < size);

	return elements[index];
}
