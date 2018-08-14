#include "DoubleLinkedList.h"
#include "Row.h"
#include "Table.h"

const size_t MaxSizeStudentName = 150;
const size_t MaxSizeSubject = 50;
const size_t MaxSizeDate = 11;


Table::Table(char* csvFile, char* column, char* order)
{
	std::ifstream file;
	file.open(csvFile);
	char* line = new char[1000];
	if (!file.good())
	{
		std::cout << "Unable to open file";

	}
	else
	{
		file.getline(line, 1000, '\n');
		delete[] line;

		while (!file.eof())
		{
			char studentName[MaxSizeStudentName];
			file.getline(studentName, MaxSizeStudentName, ',');

			char comma;

			int studentAge;
			file >> studentAge;

			file >> comma;

			char* subject = new char[MaxSizeSubject];
			file.getline(subject, MaxSizeSubject, ',');

			double grade;
			file >> grade;

			file >> comma;
			char* date = new char[MaxSizeDate];
			file.getline(date, MaxSizeDate, '\n');

			Row* row = new Row;

			row->setStudentName(studentName);
			row->setStudentAge(studentAge);
			row->setGrade(grade);
			row->setSubject(subject);
			row->setDate(date);
			rows.pushBack(row);
			delete[] subject;
			delete[] date;
			rows.getLast()->operator<<(std::cout);

		}

	}
	insertionSort(column, order);


}

void Table::insertionSort(char* column, char* order)
{
	if (strcmp(column, "name") == 0 && strcmp(order, "asc") == 0)
	{
		rows.insertionSort(compareByStudentNameAsc);
	}
	else if (strcmp(column, "name") == 0 && strcmp(order, "desc") == 0)
	{
		rows.insertionSort(compareByStudentNameDesc);
	}
	else if (strcmp(column, "age") == 0 && strcmp(order, "asc") == 0)
	{
		rows.insertionSort(compareByStudentAgeAsc);
	}
	else if (strcmp(column, "age") == 0 && strcmp(order, "desc") == 0)
	{
		rows.insertionSort(compareByStudentAgeDesc);
	}
	else  if (strcmp(column, "subject") == 0 && strcmp(order, "asc") == 0)
	{
		rows.insertionSort(compareByStudentSubjectAsc);
	}
	else if (strcmp(column, "subject") == 0 && strcmp(order, "desc") == 0)
	{
		rows.insertionSort(compareByStudentSubjectDesc);
	}
	else  if (strcmp(column, "grade") == 0 && strcmp(order, "asc") == 0)
	{
		rows.insertionSort(compareByStudentGradeAsc);
	}
	else if (strcmp(column, "grade") == 0 && strcmp(order, "desc") == 0)
	{
		rows.insertionSort(compareByStudentGradeDesc);
	}
	else  if (strcmp(column, "date") == 0 && strcmp(order, "asc") == 0)
	{
		rows.insertionSort(compareByStudentDateAsc);
	}
	else if (strcmp(column, "date") == 0 && strcmp(order, "desc") == 0)
	{
		rows.insertionSort(compareByStudentDateDesc);
	}
}

