#include <cassert>

// singly_linked_list_impl.hpp

// Constructs an empty Singly Linked List.
template <class T>
SinglyLinkedList<T>::SinglyLinkedList()
{
	num_elements = 0;
	next = nullptr;
}

// Constructs this SinglyLinkedList as a copy of the other.
template <class T>
SinglyLinkedList<T>::SinglyLinkedList(const SinglyLinkedList<T>& list)
{
	copy(list);
}

// Deallocates all memory allocated by this SinglyLinkedList.
template <class T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
	destroy();
}

// Destroys this list and creates a copy of the input list.
template <class T>
const SinglyLinkedList<T>& SinglyLinkedList<T>::operator=(const SinglyLinkedList<T>& list)
{
	destroy();
	copy(list);
}

// Accessors

// Returns number of elements in the SinglyLinkedList.
template <class T>
int64_t SinglyLinkedList<T>::size() const
{
	return num_elements;
}

// Returns true if the SinglyLinkedList holds no elements.
template <class T>
bool SinglyLinkedList<T>::empty() const
{
	return num_elements == 0;
}

// Modifiers

// Places the element on the front of the SinglyLinkedList.
template <class T>
void SinglyLinkedList<T>::push_front(const T& element)
{

}

// Removes an element from the front of the SinglyLinkedList.
template <class T>
void SinglyLinkedList<T>::pop_front()
{
	Node<T> *first = head;
	head = head->next;

	first->next = nullptr;
	delete first;
}

// Places the element on the end of the SinglyLinkedList.
template <class T>
void SinglyLinkedList<T>::push_back(const T& element)
{

}

// Removes an element from the end of the SinglyLinkedList.
template <class T>
void SinglyLinkedList<T>::pop_back()
{

}

// Removes all elements from the SinglyLinkedList.
template <class T>
void SinglyLinkedList<T>::clear()
{
	destroy();
}


// Helper Methods

// Copies the contents of the input Vector to this Vector.
template <class T>
void SinglyLinkedList<T>::copy(const SinglyLinkedList<T> & other)
{
	Node<T> *other_node = other.head;
	Node<T> *this_node = nullptr;
	Node<T> *prev_node = nullptr;

	while (other_node != nullptr)
	{
		this_node = new Node<T>(other_node.element);

		if (prev_node != nullptr)
		{
			prev_node->next = this_node;
		}
		prev_node = this_node;
		other_node = other_node->next;
	}

	this.num_elements = other.num_elements;
}

// Deallocates memory and clears Vector member variables.
template <class T>
void SinglyLinkedList<T>::destroy()
{
	Node<T> *node = head;
	while (head != nullptr)
	{
		head = head->next;
		node->next = nullptr;
		delete node;
		node = head;
	}
}

