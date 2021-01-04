#include <iostream>
#include "Iterator.h"

using namespace std;

int main()
{
	CList<int> list;
	list.PushFront(10);
	list.PushFront(20);
	list.PushFront(30);

	CList<int>::m_iterator it;

	for (it = list.begin(); it != list.end(); ++it)
	{
		cout << *it << endl;
	}
}