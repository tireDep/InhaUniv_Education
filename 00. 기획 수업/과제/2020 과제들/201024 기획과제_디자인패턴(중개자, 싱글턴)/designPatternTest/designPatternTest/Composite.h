#pragma once
#include <iostream>
#include <vector>
using namespace std;

class CComponent
{
public:
	virtual void traverse() = 0;
};

class CLeaf : public CComponent
{
	// 1. Scalar class   3. "isa" relationship
	int value;
public:
	CLeaf(int val)
	{
		value = val;
	}
	void traverse()
	{
		cout << value << ' ';
	}
};

class CComposite : public CComponent
{
	// 1. Vector class   3. "isa" relationship
	vector < CComponent * > children; // 4. "container" coupled to the interface
public:
	// 4. "container" class coupled to the interface
	void add(CComponent *ele)
	{
		children.push_back(ele);
	}
	void traverse()
	{
		for (int i = 0; i < children.size(); i++)
			// 5. Use polymorphism to delegate to children
			children[i]->traverse();
	}
};