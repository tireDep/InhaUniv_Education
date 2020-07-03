#pragma once

template <class Item>
class QueueTP
{
private:
	enum { Q_Size = 10 };

	class Node	// 내포 클래스
	{
	public:
		Item item;
		Node *next;
		Node(const Item & i) : item(i), next(0) { }
	};

	Node *front;
	Node *rear;
	int items;
	const int qsize;
	QueueTP(const QueueTp & q):qsize(0) { }
	QueueTP & operator=(const QueueTP & q) { return *this; }

public:
	QueueTP(int qs = Q_Size);
	~QueueTP();
	bool IsEmpty() const { return items == 0; }
	bool IsFull() const { return items == qsize; }
	int QueueCount() const { return items; }
	bool Enqueue(const Item & item);
	bool Dequeue(Item & item);
};

template <class Item>
QueueTP<Item>::QueueTP(int qs) : qsize(qs)
{ 
	front = rear = 0;
	items = 0;
}

template <class Item>
QueueTP<Item>::~QueueTP()
{
	Node *temp;
	while (front != 0)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
}

template <class Item>
bool QueueTP<Item>::Enqueue(const Item & item)
{
	if (IsFull())
		return false;
	Node * add = new Node(item);
	items++;

	if (front == 0)
		front = add;
	else
		rear->next = add;
	
	rear = add;

	return true;
}

template <class Item>
bool QueueTP<Item>::Dequeue(Item & item)
{
	if (front == 0)
		return false;
	item = front->item;
	items--;
	Node * temp = front;
	front = front->next;
	delete temp;

	if (items == 0)
		rear = 0;

	return true;
}