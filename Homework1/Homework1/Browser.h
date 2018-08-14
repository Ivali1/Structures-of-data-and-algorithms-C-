#pragma once
#pragma once
#include "Tab.h"
#include "DoubleLinkedList.h"
class Browser
{
public:
	Browser();
	void go(char* URL);
	void insert(char* URL);
	void back();
	void forward();
	void remove();
	void print();
	void queries();
private:
	elem<Tab*>* current;
	DoubleLinkedList<Tab*> tabs; //list from pointers to tabs
};


