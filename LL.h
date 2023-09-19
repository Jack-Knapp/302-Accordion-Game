#ifndef LL_H
#define LL_H
#include <cstdlib>
#include "myStack.h"

template <class type>
class LL
{
private:
	struct node
	{
		type item;
		node * next;
		node * prev;
	};

	void clearList();
	void copyList(const LL<type>&);

	node * dummy;
	
public:

	class iterator
	{
	private:
		node * position;

	public:
		friend class LL;
		iterator() : position(nullptr) {}
		iterator(node * n) : position(n) {}
		type& operator*() { return position->item; }
		bool operator==(const iterator& rhs) { return position == rhs.position; }
		bool operator!=(const iterator& rhs) { return position != rhs.position; }

		iterator operator++(int);
		iterator operator++();

		iterator operator--(int);
		iterator operator--();
	};

	LL();
	LL(const LL<type>&);
	const LL<type>& operator=(const LL<type>&);
	~LL();
	void headInsert(const type&);
	void tailInsert(const type&);
	void headRemove();
	void tailRemove();
	void removeAtPosition(iterator&);
	bool isEmpty() const { return dummy->next == dummy; }
	iterator begin() const { return iterator(dummy->next); }
	iterator end() const { return iterator(dummy); }
};
#endif