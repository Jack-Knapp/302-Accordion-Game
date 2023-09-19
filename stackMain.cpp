#include "myStack.h"
#include "myStack.cpp"
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int main()
{
	myStack<std::string> stack1;

	for (int i = 0; i < 20; i++)
		stack1.push(std::to_string(i));

	myStack<std::string> stack2(stack1);

	stack2.pop();
	stack2.pop();

	stack2.push("Hello");
	stack2.push("All");

	myStack<std::string> stack3;

	for (int i = 0; i < 7; i++)
		stack3.push(std::to_string(i + 20));

	stack3 = stack1;

	stack3.pop();
	stack3.pop();
	stack3.pop();
	stack3.pop();

	stack3.push("Eleventy six");
	stack3.push("Two is a number");
	stack3.push("Yes");

	cout << endl << "Stack1" << endl;
	for (int i = 0; i < stack1.getSize() / 2; i++)
		cout << stack1.pop() << endl;

	cout << endl << "Stack2" << endl;
	for (int i = 0; i < stack2.getSize() / 2; i++)
		cout << stack2.pop() << endl;

	cout << endl << "Stack3" << endl;
	for (int i = 0; i < stack3.getSize() / 2; i++)
		cout << stack3.pop() << endl;

	return 0;
}