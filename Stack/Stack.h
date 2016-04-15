#pragma once
#ifndef STACK_H
#define STACK_H


template <typename T>
class Stack
{
public:
	Stack<T>(int n );
	~Stack<T>();
	Stack<T>(const &Stack<T> other);
	Stack<T> operator=(const &Stack<T> other);
    void push(T x);
	void pop();
	T top() const;
	bool IsEmpty();
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
Stack<T>::Stack<T>(int n)
{
	this->capacity=n;
	stack=new T[n];
	top=0;

}
template <typename T>
Stack<T>::~Stack<T>()
{
	delete [] stack;

}
template <typename T>
Stack<T>::Stack<T>(const &Stack<T> other)
{
	this->capacity=other.capacity;
	this->top=other.top;
	for	(int i=0,int<other.top,i++)
	{
		stack[i]=other.stack[i];
	}

}
template <typename T>
Stack<T>::Stack<T> operator=(const &Stack<T> other)
{
	if(this!=&other)
	{
		delete [] stack;
		this->capacity=other.capacity;
	this->top=other.top;
	for	(int i=0,int<other.top,i++)
	{
		stack[i]=other.stack[i];
	}
	}
	return *this;
}

template <typename T>
Stack<T>::void push(T x)
{
	stack[i]=x;
	top++;
}
template <typename T>
	Stack<T>::void pop()
	{
		top--;
	}
template <typename T>
T Stack<T>::top() const
{
	return stack[top];

}

template <typename T>
Stack<T>::bool IsEmpty()
{
	return top==0;
}
