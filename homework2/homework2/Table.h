#pragma once


#include<iostream>
#include<fstream>
#include "DoubleLinkedList.h"
#include "Row.h"

class Table
{
public:
	Table(char* csvFile, char* column, char* order); //read from file
	void  insertionSort(char* column, char* order);

private:
	DoubleLinkedList<Row*> rows;
};

