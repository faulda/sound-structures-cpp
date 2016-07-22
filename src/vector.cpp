#include <cassert>

#include "vector.hpp"

// vector.cpp
// Function implementations for the Vector class.

template<class T>
Vector<T>::Vector() : Vector(Default_Allocation_Size)
{
}

template<class T>
Vector(int64_t size)
{
	init(size);
}

// Copy constructor. Initializes this Vector as a copy of the input.
template<class T>
Vector(const Vector& vector)
{
	copy(vector);
}

template<class T>
const Vector& operator=(const Vector& vector)
{
	destroy();
	copy(vector);
}

template<class T>
~Vector()
{
	destroy();
}

// Returns number of elements in the Vector.
template<class T>
int64_t size() const
{
	return num_elements;
}

// Returns a const reference to the element at the index.
template<class T>
const T& operator[](int64_t index) const
{
	assert(index >= 0 && index < num_elements);

	return elements[index];
}


// Returns a modifiable reference to the element at the index.
template <class T>
T& Vector<T>::operator[](int64_t index)
{
	assert(index >= 0 && index < num_elements);

	return elements[index];
}

// Places the element on the end of the Vector. May trigger a resize.
template<class T>
void Vector<T>::push_back(const T& element)
{
	if (array_size == num_elements)
	{
		resize_internal(array_size * 2);
	}

	elements[num_elements] = element;
	++num_elements;
}

// Places all the elements from the input Vector onto the back of this Vector.
template <class T>
void Vector<T>::push_back(const Vector<T>& new_elements)
{
	if (num_elements + elements.size() > array_size)
	{
		resize_internal(2*(num_elements + elements.size()));
	}

	for (int64_t index = 0; index < new_elements.size(); ++index)
	{
		elements[num_elements + index] = new_elements[index];
	}

	num_elements += new_elements.size();
}

// Removes an element from the end of the Vector.
template <class T>
void Vector<T>::pop_back()
{
	--num_elements;
}

// Removes all elements from the Vector;
template <class T>
void Vector<T>::clear()
{
	destroy();
	init(Default_Allocation_Size);
}

// Resizes the Vector to hold the number of elements specified. The
// input element is used to fill new spots.
template <class T>
void Vector<T>::resize(int64_t size, const T& filler_element)
{
	if (size < num_elements)
	{
		num_elements = size;
	}
	else // size >= num_elements
	{
		if (size > array_size)
		{
			resize_internal(size * 2);
		}
		
		for (int64_t index = num_elements; index < size; ++index)
		{
			elements[index] = filler_element;
		}
		num_elements = size;
	}
}

// Shrinks the Vector to hold only the number of elements specified.
template <class T>
void Vector<T>::shrink_to_fit()
{
	if (array_size > num_elements)
	{
		resize_internal(num_elements);
	}
}

// Creates an empty Vector with specified array size.
template <class T>
void Vector<T>::init(int64_t size)
{
	num_elements = 0;
	array_size = 5;

	elements = new T[array_size];
}

// Copies the contents of the input Vector to this Vector.
template <class T>
void Vector<T>::copy(const Vector& vector)
{
	num_elements = vector.num_elements;
	array_size = vector.array_size;

	elements = new T[array_size];

	for (int64_t index = 0; index < num_elements; ++index)
	{
		elements[index] = vector.elements[index];
	}
}

// Deallocates memory and clears Vector member variables.
template <class T>
void Vector<T>::destroy()
{
	delete[] elements;
	elements = nullptr;

	num_elements = 0;
	array_size = 0;
}

// Changes the allocated capacity of the vector up or down to the specified size.
// Does not modify the number of elements.
template <class T>
void Vector<T>::resize_internal(int64_t size)
{
	assert(size > 0);

	array_size = size;
	T* new_elements = new T[array_size];
	for (int64_t index = 0; index < num_elements; ++index)
	{
		new_elements[index] = elements[index];
	}

	delete[] elements;
	elements = new_elements;
}
