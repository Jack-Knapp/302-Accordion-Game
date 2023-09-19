#include "LL.h"
#include "LL.cpp"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
	LL<int> list;
	LL<int>::iterator it;	

	for (int i = 0; i < 20; i++)
		list.tailInsert(i);

	it = list.begin();

	list.removeAtPosition(it);

	for (int i = 0; i < 10; i++)
		it++;

	list.removeAtPosition(it);

	while (it != list.end())
		it--;

	it--;

	list.removeAtPosition(it);

	for (int i = 0; i < 7; i++)
		it--;

	list.removeAtPosition(it);

	while (it != list.begin())
		it++;

	for (; it != list.end(); it++)
		cout << (*it) << endl;

	return 0;
}