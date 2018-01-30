#include<iostream>
#include "LinkedList.h"

int main()
{
	LinkedList<int> temp;
	temp.pushBack(1);
	temp.pushBack(2);
	temp.pushBack(3);
	temp.pushBack(4);
	temp.print();
	temp.pushFront(5);
	std::cout << std::endl;
	temp.print();

	std::cout << std::endl;
	temp.popFront();
	std::cout << std::endl;
	temp.print();

	temp.popBack();
	std::cout << std::endl;
	temp.print();



	return 0;
}