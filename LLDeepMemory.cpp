#include "LL.h"
#include "LL.cpp"
#include <iostream>
#include <string>
using namespace std;

void printList(const LL<string>&);

int main()
{
	LL<string> list1;

	string do_, re_, mi_, fa_, sol_, ti_, yeah;

	do_ = "Do";
	re_ = "Re";
	mi_ = "Mi";
	fa_ = "Fa";
	sol_ = "Sol";
	ti_ = "Ti";

	yeah = "yeah";

	list1.tailInsert(mi_);
	list1.tailInsert(fa_);

	LL<string> list2(list1);

	list2.headInsert(re_);
	list2.tailInsert(sol_);

	LL<string> list3;

	list3.headInsert(yeah);
	list3.headInsert(yeah);
	list3.tailInsert(yeah);

	list3 = list2;

	list3.headInsert(do_);
	list3.tailInsert(ti_);

	cout << endl << "list1" << endl;
	printList(list1);

	cout << endl << "list2" << endl;
	printList(list2);

	cout << endl << "list3" << endl;
	printList(list3);

	return 0;
}

void printList(const LL<string>& list)
{
	LL<string>::iterator it;

	for (it = list.begin(); it != list.end(); it++)
		cout << (*it) << " ";

	cout << endl;

	return;
}