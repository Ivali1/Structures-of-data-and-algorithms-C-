#include<iostream>
#include "DoubleLinkedList.h"

int main()
{
	DoubleLinkedList<int> temp;
	temp.pushBack(1);
	temp.pushBack(2);
	temp.pushBack(3);
	temp.pushBack(4);
	temp.print();


	return 0;
}