#ifndef MY_STACK_H
#define MY_STACK_H

#include <cstdlib>
#include <stdexcept>

template <class type>
class myStack
{
public:
	myStack();
	myStack(const myStack<type>&);
	const myStack& operator=(const myStack<type>&);
	~myStack();

	void push(const type&);
	type peek() const;
	std::size_t getSize() const;
	type pop();
	bool isEmpty() const;
private:
	void clearStack();
	void copyStack(const myStack<type>&);
	type * stackElements;
	std::size_t capacity, size;
};
#endif