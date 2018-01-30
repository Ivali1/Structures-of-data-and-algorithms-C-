#pragma once
#include<iostream>


template<typename T>
struct elem
{
	T data;
	elem<T>* pnext;
	elem<T>* pprev;
	elem(T otherData)
	{
		this->data = otherData;
		pnext = NULL;
		pprev = NULL;
	}
};

template<typename T>
class DoubleLinkedList
{
public:
	DoubleLinkedList();
	~DoubleLinkedList();
	size_t getSize()const;
	//return pointer to first box
	elem<T>* getFirstBox()const;
	//return data from first box
	T& getFirst()const;
	//return pointer to last box
	elem<T>* getLastBox()const;
	T& getLast()const;
	bool isEmpty();
	void pushBack(T otherData);
	void pushFront(T otherData);
	void popFront();
	void popBack();
	void print();

private:
	size_t size;
	elem<T>* first;
	elem<T>* last;

};

template<typename T>
DoubleLinkedList<T>::DoubleLinkedList()
{
	this->first = NULL;
	this->last = NULL;
	this->size = 0;
}
template<typename T>

DoubleLinkedList<T>::~DoubleLinkedList()
{
	while (!isEmpty())
	{
		popFront();
	}
	this->first = NULL;
	this->last = NULL;
}

template<typename T>
size_t DoubleLinkedList<T>::getSize()const
{
	return  this->size;
}

template<typename T>
elem<T>* DoubleLinkedList<T>::getFirstBox() const
{
	return this->first;
}

template<typename T>
T& DoubleLinkedList<T>::getFirst()const
{
	return this->first->data;
}

template<typename T>
elem<T>* DoubleLinkedList<T>::getLastBox() const
{
	return last;
}

template<typename T>
T & DoubleLinkedList<T>::getLast() const
{
	return this->last->data;
}

template<typename T>
bool DoubleLinkedList<T>::isEmpty()
{
	return this->size == 0;
}
template<typename T>
void DoubleLinkedList<T>::pushFront(T otherData)
{
	elem<T>* temp = new elem<T>(otherData);
	if (isEmpty())
	{
		first = temp;
		last = first;
		last->pnext = NULL;

	}
	else
	{
		temp->pnext = first;
		first->pprev = temp;
		first = temp;
		first->pprev = NULL;
	}
	++size;
}
template<typename T>
void DoubleLinkedList<T>::pushBack(T otherData)
{
	elem<T>* temp = new elem<T>(otherData);
	if (isEmpty())
	{
		first = temp;
		last = temp;
		last->pnext = NULL;

	}
	else
	{
		last->pnext = temp;
		temp->pprev = last;
		last = temp;
		last->pnext = NULL;

	}
	++size;
}

template<typename T>
void DoubleLinkedList<T>::popFront()
{
	if (isEmpty())
		throw "Queue is empty";
	else
	{
		elem<T>* temp = first;
		first = first->pnext;
		delete[] temp;
		--size;
	}
}

template<typename T>
void DoubleLinkedList<T>::popBack()
{
	if (isEmpty())
		throw "Queue is empty";
	else
	{
		elem<T>* temp = last;
		last = last->pprev;
		last->pnext = NULL;
		delete[] temp;
		--size;
	}
}
template<typename T>
void DoubleLinkedList<T>::print()
{
	elem<T>* temp = first;
	while (temp != NULL)
	{
		std::cout << temp->data << std::endl;
		temp = temp->pnext;
	}
}


