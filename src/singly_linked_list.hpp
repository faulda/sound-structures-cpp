#pragma once

// vector.hpp
// Class declaration for the Vector class.

#include <stdint.h>


// Node class represents each element of the list.
// All members are public becase the class is only
// used internally by SinglyLinkedList and not
// exposed to callers of the class.
template <class T>
class Node
{
public:
	Node(T elem = T(), Node<T> *nxt = nullptr)
	{
		element = elem;
		next = nxt;
	}

	T element;
	Node<T> *next;
};


template <class T>
class SinglyLinkedList
{
public:

	// Constructs an empty Singly Linked List.
	SinglyLinkedList();
	
	// Constructs this SinglyLinkedList as a copy of the other.
	SinglyLinkedList(const SinglyLinkedList& list);
	
	// Deallocates all memory allocated by this SinglyLinkedList.
	~SinglyLinkedList();

	// Destroys this list and creates a copy of the input list.
	const SinglyLinkedList<T>& operator=(const SinglyLinkedList<T>& list);

	// Accessors

	// Returns number of elements in the SinglyLinkedList.
	int64_t size() const;

	// Returns true if the SinglyLinkedList holds no elements.
	bool empty() const;

	// Modifiers

	// Places the element on the front of the SinglyLinkedList.
	void push_front(const T& element);
	
	// Removes an element from the front of the SinglyLinkedList.
	void pop_front();

	// Places the element on the end of the SinglyLinkedList.
	void push_back(const T& element);

	// Removes an element from the end of the SinglyLinkedList.
	void pop_back();

	// Removes all elements from the SinglyLinkedList.
	void clear();


private:

	// Helper Methods

	// Copies the contents of the input Vector to this Vector.
	void copy(const SinglyLinkedList<T> & other);

	// Deallocates memory and clears Vector member variables.
	void destroy();

	// Member variables

	int64_t num_elements;
	Node<T> *head;

	// Constants
	const int64_t Default_Allocation_Size = 10;
};


// Because templated class, implementations must be in same file.
// They are stored in a separate file, vector_impl.hpp.
#include "singly_linked_list_impl.hpp"
