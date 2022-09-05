#include <iostream>
#include <cstdlib>
#define SIZE 10
using namespace std;

class Stack
{
	int* arr;
	int top, capacity;
public:
	Stack(int size = SIZE); // Constructor
	~Stack();//Destructor

	void push(int); //Se insereaza un element nou in stack
	int pop();
	int peek();

	int size();
	bool Empty();
	bool Full();
};
Stack::Stack(int size) {
	arr = new int[size];
	capacity = size;
	top = -1;
}
Stack::~Stack(){
	delete[] arr;
}
void Stack::push(int x) {
	if (Full()) {
		cout << "Is full. PROGRAM TERMINATED";
	}
	cout << "Inserting: " << x << endl;
	arr[++top] = x;
}
int Stack::pop() {
	if (Empty())
	{
		cout << "Is not full. PROGRAM TERMINATED";
	}
	cout << "Removing: " << peek() << endl;
	return arr[top--]; // Se da stack-ul cu un element in minus, din cauza ca a fost eliminat
}
int Stack::peek() {
	if (!Empty())
		return arr[top];
	else
		exit(EXIT_FAILURE);
}
int Stack::size() {
	return top + 1;
}
bool Stack::Empty()
{
	return top == -1;
}
bool Stack::Full() {
	return top == capacity - 1;
}
int main()
{
	Stack pt(3);
	pt.push(1);
	pt.push(2);
	pt.pop();
	pt.pop();
	pt.push(3);
	cout << "The top element is: " << pt.peek() << endl;
	cout << "The stack size is: " << pt.size() << endl;
	if (pt.Empty())
		cout << "Stack empty" << endl;
	else
		cout << "Stack not empty" << endl;
}