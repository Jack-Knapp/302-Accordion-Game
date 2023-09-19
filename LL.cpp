/*
Name: Jack Knapp, 302.1
Purpose: Linked List, Stack Review
Description: Program to play Accordian card game
Input: Deck of cards from text file
What to do?:  Play a game of Accordian with the provided
    deck using a circular doubly linked list of stacks
Output: The formatted results of the card game
*/

#include "LL.h"

template <class type>
typename LL<type>::iterator LL<type>::iterator::operator++(int)
{
	iterator current(position);
	position = position->next;

	return current;
}

template <class type>
typename LL<type>::iterator LL<type>::iterator::operator++()
{
	position = position->next;

	return *this;
}

template <class type>
typename LL<type>::iterator LL<type>::iterator::operator--(int)
{
	iterator current(position);
	position = position->prev;

	return current;
}

template <class type>
typename LL<type>::iterator LL<type>::iterator::operator--()
{
	position = position->prev;

	return *this;
}

/* 
 * LL : Default Constructor
 * parameters: N/A
 * return value: N/A
 */
template <class type>
LL<type>::LL()
{
	dummy = new node;
	dummy->prev = dummy;
	dummy->next = dummy;
}

/* 
 * LL : Copy Constructor
 * parameters: An LL object
 * return value: N/A
 */
template <class type>
LL<type>::LL(const LL<type>& copy)
{	
	dummy = new node;
	dummy->prev = dummy;
	dummy->next = dummy;
	copyList(copy);
}

/* 
 * = : = Operator Overload
 * parameters: LL object of rhs
 * return value: LL object
 */
template <class type>
const LL<type>& LL<type>::operator=(const LL<type>& rhs)
{
	if (this != &rhs)
	{
		this->clearList();
		this->copyList(rhs);
	}

	return *this;
}

/* 
 * ~LL : Destructor
 * parameters: N/A
 * return value: N/A
 */
template <class type>
LL<type>::~LL()
{
	this->clearList();
	delete dummy;
}

/* 
 * headInsert : Insert a given item into the head of the linked list
 * parameters: An item to insert
 * return value: N/A
 */
template <class type>
void LL<type>::headInsert(const type& item)
{	
	//create a node and store the item
	node* temp = new node;
	temp->item = item;

	//empty list case
	if (dummy->next == dummy) {
		temp->next = dummy;
		temp->prev = dummy;
		dummy->next = temp;
		dummy->prev = temp;
		return;
	}
	//main case where list is not empty
	else {
		temp->next = dummy->next;
		node* temp2 = dummy->next;
		temp2->prev = temp;
		dummy->next = temp;
		temp->prev = dummy;
		return;
	}
}

/* 
 * tailInsert : Insert a given item into the tail of the linked list
 * parameters: An item to insert
 * return value: N/A
 */
template <class type>
void LL<type>::tailInsert(const type& item)
{	
	//create a node and store the item
	node* temp = new node;
	temp->item = item;

	//empty list case
	if (dummy->prev == dummy) {
		temp->next = dummy;
		temp->prev = dummy;
		dummy->next = temp;
		dummy->prev = temp;
		return;
	}
	//main case where list is not empty
	else {
		temp->next = dummy;
		node* temp2 = dummy->prev;
		temp2->next = temp;
		temp->prev = temp2;
		dummy->prev = temp;
		return;
	}
}

/* 
 * headRemove : Remove the head of the linked list
 * parameters: N/A
 * return value: N/A
 */
template <class type>
void LL<type>::headRemove()
{	
	//Assign some pointers
	node* temp = dummy->next;
	node* head = temp->next;

	//only one node case
	if (temp->next == dummy) {
		dummy->next = dummy;
		dummy-> prev = dummy;
		delete temp;
		return;
	}
	//more than one node case
	else {
		dummy->next = head;
		head-> prev = dummy;
		temp->next = nullptr;
		temp->prev = nullptr;
		delete temp;
		return;
	}
}

/* 
 * tailRemove : Remove the tail of the linked list
 * parameters: N/A
 * return value: N/A
 */
template <class type>
void LL<type>::tailRemove()
{	
	//assign some pointers
	node* temp = dummy->prev;
	node* tail = temp->prev;

	//only one node case
	if (temp->prev == dummy) {
		dummy->next = dummy;
		dummy->prev = dummy;
		delete temp;
		return;
	}
	//more than one node case
	else {
		dummy->prev = tail;
		tail->next = dummy;
		delete temp;
		return;
	}
}

/* 
 * removeAtPosition : Remove the node at a given position from the linked list
 * parameters: An iterator with a location
 * return value: N/A
 */
template <class type>
void LL<type>::removeAtPosition(LL<type>::iterator & it)
{
	//head remove if head then reset iterator
	if (it == this->begin()) {
		it++;
		this->headRemove();
		return;
	}

	//tail remove if tail then reset iterator
	else if (it == --(this->end())) {
		it--;
		this->tailRemove();
		return;
	}

	//standard case delete, then move iterator
	else {
		node* temp2 = it.position;
		node* temp = temp2->prev;
		node* temp3 = temp2->next;
		temp->next = temp3;
		temp3->prev = temp;
		it++;
		delete temp2;
		return;
	}
}

/* 
 * clearList : Remove all nodes except dummy
 * parameters: N/A
 * return value: N/A
 */
template <class type>
void LL<type>::clearList()
{
	while (dummy->next != dummy) {
		this->headRemove();
	}
	return;
}

/* 
 * copyList : make this a copy of the passed linked list
 * parameters: A linked list to copy
 * return value: this as a copy of the parameter
 */
template <class type>
void LL<type>::copyList(const LL<type>& copyThisList)
{	
	//create some nodes
	node* temp = copyThisList.dummy;
	node* temp2 = temp->prev;

	//loop to insert the nodes
	while (temp != temp2) {
		this->headInsert(temp2->item);
		temp2 = temp2->prev;
	}
	return;
}