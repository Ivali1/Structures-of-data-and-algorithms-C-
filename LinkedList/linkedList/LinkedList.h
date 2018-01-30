#pragma once
#pragma once
#include<iostream>


template<typename T>
struct elem
{
	T data;
	elem<T>* pnext;
	elem(T otherData)
	{
		this->data = otherData;
		pnext = NULL;
	}
};

template<typename T>
class LinkedList
{
public:
	LinkedList();
	~LinkedList();
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
LinkedList<T>::LinkedList()
{
	this->first = NULL;
	this->last = NULL;
	this->size = 0;
}
template<typename T>

LinkedList<T>::~LinkedList()
{
	while (!isEmpty())
	{
		popFront();
	}
	this->first = NULL;
	this->last = NULL;
}

template<typename T>
size_t LinkedList<T>::getSize()const
{
	return  this->size;
}

template<typename T>
elem<T>* LinkedList<T>::getFirstBox() const
{
	return this->first;
}

template<typename T>
T& LinkedList<T>::getFirst()const
{
	return this->first->data;
}

template<typename T>
elem<T>* LinkedList<T>::getLastBox() const
{
	return last;
}

template<typename T>
T & LinkedList<T>::getLast() const
{
	return this->last->data;
}

template<typename T>
bool LinkedList<T>::isEmpty()
{
	return this->size == 0;
}
template<typename T>
void LinkedList<T>::pushFront(T otherData)
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
		first = temp;
	}
	++size;
}
template<typename T>
void LinkedList<T>::pushBack(T otherData)
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
		last = temp;
		last->pnext = NULL;

	}
	++size;
}

template<typename T>
void LinkedList<T>::popFront()
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
void LinkedList<T>::popBack()
{
	if (isEmpty())
		throw "Queue is empty";
	else
	{
		elem<T>* temp = first;
		elem<T>* previous = temp;
		while (temp->pnext != NULL)
		{ 
			previous = temp;
			temp = temp->pnext;
		}
		last = previous;
		last->pnext = NULL;
		delete[] temp;
		--size;
	}
}
template<typename T>
void LinkedList<T>::print()
{
	elem<T>* temp = first;
	while (temp != NULL)
	{
		std::cout << temp->data << std::endl;
		temp = temp->pnext;
	}
}


