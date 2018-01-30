#include<iostream>
#include "Queue.h"

int main()
{
	Queue<int> temp;
	temp.pushBack(1);
	temp.pushBack(2);
	temp.pushBack(3);
	temp.pushBack(4);
	temp.print();
	std::cout << std::endl;
	temp.popFront();
	temp.print();

	return 0;
}