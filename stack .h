#pragma once
# include <iostream>
# define size 50 
using namespace std;
class stack
{
private:
	int top;
	int item[size];
public:
	stack();
	~stack();
	bool is_full();
	bool is_empty();
	void push(int x);
	int  pop();
	void display();
	void displayHelper(int index);
};



stack::stack() {
	top = -1;

}
stack ::~stack() {
	top = -1;

}
bool stack::is_full() {//to ensure if the stack is full or not
	if (top == size - 1) {

		return 1;
	}
	return 0;
}
bool stack::is_empty() {//to ensure if the stack is empty or not
	if (top == -1)
	{

		return 1;
	}
	return 0;
}
void stack::push(int x) {
	if (is_full()) {
		cout << " the stack is over flow ";
		return;
	}
	item[++top] = x;

};
int stack::pop() {

	if (is_empty()) {
		cout << " stack is under flow";
		return -1;
	}

	return item[top--];
}
void stack::displayHelper(int index) {
	if (index < 0) // Base case: stop when index is less than 0
	{

		return;
	}
	// Print the current element
	cout << item[index] << " ";

	// Recursively call displayHelper with the previous index
	displayHelper(index - 1);
}
void stack::display() {
	if (is_empty()) {
		cout << " ther is no elements to print " << endl;
		return;
	}

	// Start recursion from the top of the stack
	displayHelper(top);
	cout << endl;
}

