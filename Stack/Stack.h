#ifndef STACK_H
#define STACK_H
using namespace std;

template <typename T>
class Stack
{
public:
	Stack<T>(int n);
	~Stack<T>();
	Stack<T>(const Stack<T>& other);
	Stack<T>& operator=(const Stack<T>& other);
	void push(T x);
	void pop();
	T top1() const;
	bool IsEmpty1();
	void print() const;
	void resize();
private:
	T*stack;
	int capacity;
	int top;
};
#endif

#include <cassert>
#include <iostream>
#include <cstdlib>
#include <ctime>

template <typename T>
Stack<T>::Stack(int n)
{
	this->capacity = n;
	stack = new T[n];
	top = 0;

}
template <typename T>
Stack<T>::~Stack()
{
	delete[] stack;

}
template <typename T>
Stack<T>::Stack(const Stack<T>& other)
{
	this->capacity = other.capacity;
	this->top = other.top;
	this->stack = new T[other.capacity];
	for (int i = 0; i < other.top; i++)
	{
		stack[i] = other.stack[i];
	}
}
template <typename T>
Stack<T>& Stack<T>:: operator=(const Stack<T>& other)
{
	if (this != &other)
	{
		delete[] stack;
		this->capacity = other.capacity;
		this->top = other.top;
		this->stack = new T[other.capacity];
		for (int i = 0; i < other.top; i++)
		{
			stack[i] = other.stack[i];
		}
	}
	return *this;
}

template <typename T>
void Stack<T>::push(T x)
{
	if ((top) == capacity)
	{
		resize();
	}
	stack[top] = x;
	top++;
}
template <typename T>
void Stack<T>::pop()
{
	top--;
}
template <typename T>
T Stack<T>::top1() const
{
	return stack[top - 1];
}

template <typename T>
bool Stack<T>::IsEmpty1()
{
	return top == 0;
}
template <typename T>
void Stack<T>::print() const
{
	for (int i = top - 1; i >= 0; i--)
	{
		cout << stack[i] << endl;
	}
}
template <typename T>
void Stack<T>::resize()
{
	capacity *= 2;
	T*	stack1 = new T[capacity];
	for (int i = 0; i < this->top; i++)
	{
		stack1[i] = stack[i];
	}
	delete[] stack;
	stack = stack1;
}


int main()
{
	Stack<int> a(2);
	a.push(1);
	a.push(2);
	a.push(3);
	a.push(4);
	a.push(5);
	a.pop();
	cout << a.top1() << endl;
	//a.print();
	////a.print();
	//a.pop();
	//cout << a.top1() << endl;
	//cout <<boolalpha<< a.IsEmpty1() << endl;
	system("pause");
	return 0;
}
