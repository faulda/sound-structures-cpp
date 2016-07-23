#pragma once

// array.hpp
// Class declaration for the Array class.

#include <stdint.h>

template<class T>
class Array
{
public:
	// Constructs an Array with the specified number of elements. Size must be
	// greater than 0.
	Array(int64_t size);

	// Destroys the Array.
	~Array();

// Accessors

	// Returns the size of this array.
	int64_t size() const;

	// Returns a const reference to the element at index.
	const T& operator[](int64_t index) const;

// Modifiers

	// Returns a modifiable reference to the element at index.
	T& operator[](int64_t index);

private:
	int64_t _size;
	T* elements;
};