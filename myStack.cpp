/*
Name: Jack Knapp, 302.1
Purpose: Linked List, Stack Review
Description: Program to play Accordian card game
Input: Deck of cards from text file
What to do?:  Play a game of Accordian with the provided
    deck using a circular doubly linked list of stacks
Output: The formatted results of the card game
*/

#include <cstdlib>
#include "myStack.h"

/* 
 * myStack : Default Constructor
 * parameters: N/A
 * return value: N/A
 */
template <class type>
myStack<type>::myStack()
{
	//set class vars to default values, alloc mem
	size = 0;
	capacity = 5;
	stackElements = new type[capacity];
}

/* 
 * myStack : Copy Constructor
 * parameters: myStack object to copy
 * return value: N/A
 */
template <class type>
myStack<type>::myStack(const myStack<type>& copy)
{	
	//copy passed object
	size = copy.size;
	capacity = copy.capacity;
	stackElements = new type[capacity];

	//deep copy passed stack elements
	for (int i=0; i<size; i++) {
		stackElements[i] = copy.stackElements[i];
	}
}

/* 
 * operator= : = Operator
 * parameters: rhs myStack object
 * return value: this myStack
 */
template <class type>
const myStack<type>& myStack<type>::operator=(const myStack<type>& rhs)
{
	if (this != & rhs)
	{
		//deleting the old stack
		if (size > 0) {
			delete[] stackElements;
			
			size = 0;
			capacity = 0;	
		}

		//Allocating the new stack
		size = rhs.size;
		capacity = rhs.capacity;
		stackElements = new type[capacity];

		//deep copy rhs into this
		for (int i=0; i<size; i++) {
			stackElements[i] = rhs.stackElements[i];
		}
	}
	return *this;
}

/* 
 * ~myStack : Destructor
 * parameters: N/A
 * return value: N/A
 */
template <class type>
myStack<type>::~myStack()
{
	//Delete memory, default vars
    delete[] stackElements;
    size = 0;
    capacity = 0;
}

/* 
 * push : push new item onto the stack
 * parameters: item to push
 * return value: N/A
 */
template <class type>
void myStack<type>::push(const type& item)
{	
	//check whether stack has space
	if (size == capacity) {
		//resize
		type* copyArr = new type[capacity*2];
			
		//deep copy old array to new one
		for (int i=0; i<size; i++) {
			copyArr[i] = stackElements[i];
		}
		
		//delete old arr
		delete []stackElements;

		//shallow copy new array
		//and set copy array to null
		stackElements = copyArr;
		copyArr = nullptr;

		capacity *= 2; //double array size	
	}

	//save item to stack, increment size
	stackElements[size] = item;
	size++;	
}

/* 
 * peek : return the top item of the stack
 * parameters: N/A
 * return value: N/A
 */
template <class type>
type myStack<type>::peek() const
{	
	//throw error if empty, else return top item
	type item;
	if (size==0) {
		throw std::__throw_out_of_range;
	}
	else {
		item = stackElements[size-1];
		return item;
	}
}

/* 
 * getSize : size getter
 * parameters: N/A
 * return value: returns size
 */
template <class type>
std::size_t myStack<type>::getSize() const
{
	return size;	
}

/* 
 * pop : Removes top item from stack and returns it
 * parameters: N/A
 * return value: top item from stack
 */
template <class type>
type myStack<type>::pop()
{
	//grab top item, decrement, return it
	type item = stackElements[size-1];
	size -=1;
	return item;
}

/* 
 * isEmpty : checks whether stack is empty or not
 * parameters: N/A
 * return value: bool based on whether stack is empty
 */
template <class type>
bool myStack<type>::isEmpty() const
{
	if (size == 0){
		return true;
	}
	return false;
}

/* 
 * clearStack : Deletes all elements in stack and deallocs them,
		then restores vars to default values
 * parameters: N/A
 * return value: N/A
 */
template <class type>
void myStack<type>::clearStack()
{	
	//Empty, delete the stack
	for (int i=0; i<size; i++) {
        delete stackElements[i];
    }
    delete[] stackElements;

	//set vars to default vals
	stackElements = nullptr;
	size = 0;
	capacity = 0;
}

/* 
 * copyStack : converts this to a copy of passed stack
 * parameters: a stack object
 * return value: N/A
 */
template <class type>
void myStack<type>::copyStack(const myStack<type>& copyThisStack)
{
	//reset vars per passed object
	size = copyThisStack.size;
	capacity = copyThisStack.capacity;
	stackElements = new type[capacity];

	//deep copy stack elements
	for (int i=0; i<size; i++) {
		stackElements[i] = copyThisStack.stackElements[i];
	}
}

