#pragma once

template<typename T>
class Node
{
public:
	T m_data;
	Node<T>* m_next;

	Node(const T& set, Node<T>* next)
	{
		m_data = set;
		m_next = next;
	}
}; 

template<typename T2>
class CIterator
{
private:
	Node<T2>* m_cur;

public:
	CIterator(Node<T2>*ptr = nullptr) : m_cur(ptr) { }

	CIterator& operator++()
	{
		m_cur = m_cur->m_next;
		return *this;
	}

	T2& operator*()
	{
		return m_cur->m_data;
	}

	bool operator==(const CIterator &ref)
	{
		return m_cur == ref.m_cur;
	}

	bool operator!=(const CIterator &ref)
	{
		return m_cur != ref.m_cur;
	}
};

template<typename T3>
class CList
{
private:
	Node<T3>* m_head;

public:
	CList() : m_head(nullptr) { }
	~CList() { if (m_head) delete m_head; }

	void PushFront(const T3& a)
	{
		m_head = new Node<T3> (a, m_head);
	}
	typedef CIterator<T3> m_iterator;

	m_iterator begin()
	{
		return m_iterator(m_head);
	}

	m_iterator end()
	{
		return m_iterator(nullptr);
	}
};