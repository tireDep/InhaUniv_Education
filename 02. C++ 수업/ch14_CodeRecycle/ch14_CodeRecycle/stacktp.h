#pragma once
template <class Type>
class Stack
{
private:
	enum { MAX = 10 };
	Type items[MAX];
	int top;

public:
	Stack();
	bool IsEmtpy();
	bool IsFull();
	bool Push(const Type & item);
	bool Pop(Type & item);
};

template <class Type>
Stack<Type>::Stack()
{
	top = 0;
}

template <class Type>
bool Stack<Type>::IsEmtpy()
{
	return top == 0;
}

template <class Type>
bool Stack<Type>::IsFull()
{
	return top == MAX;
}

template <class Type>
bool Stack<Type>::Push(const Type & item)
{
	if (top < MAX)
	{
		items[top++] = item;
		return true;
	}
	else
		return false;
}

template <class Type>
bool Stack<Type>::Pop(Type & item)
{
	if (top > 0)
	{
		item = items[--top];
		return true;
	}
	else
		return false;
}