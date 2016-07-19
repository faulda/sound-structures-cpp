#pragma once

// vector.hpp
// Class declaration for the Vector class.

#include <stdint.h>

template<class T>
public class Vector
{
public:
	Vector();
	Vector(int64_t size);

// Copy
	Vector(const Vector& vector);
	const Vector& operator=(const Vector& vector);

	~Vector();

// Accessors

	// Returns number of elements in the Vector.
	int64_t size() const;

	// Returns a const reference to the element at the index.
	const T& operator[](int64_t index) const;

	
// Modifiers
	
	// Returns a modifiable reference to the element at the index.
	T& operator[](int64_t index);

	// Places the element on the end of the Vector. May trigger a resize.
	void push_back(const T& element);

	// Places all the elements from the input Vector onto the back of this Vector.
	void push_back(const Vector<T>& elements);
	
	// Removes an element from the end of the Vector.
	void pop_back();

	// Removes all elements from the Vector;
	void clear();

	// Resizes the Vector to hold the number of elements specified. The
	// input element is used to fill new spots.
	void resize(int64_t size, const T& filler_element);

private:

// Helper Methods

	// Creates an empty Vector with specified array size.
	void init(int64_t size);
	
	// Copies the contents of the input Vector to this Vector.
	void copy(const Vector& vector);

	// Deallocates memory and clears Vector member variables.
	void destroy();

	// Changes the allocated capacity of the vector up or down to the specified size.
	// Does not modify the number of elements.
	void resize_internal(int64_t size);

// Member variables

	int64_t num_elements;
	int64_t array_size;
	T* elements;

// Constants
	const int64_t Default_Allocation_Size = 5;
};