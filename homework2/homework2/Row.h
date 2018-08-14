#pragma once

#include <iostream>	
#include "DoubleLinkedList.h"
class Row
{
public:
	Row();
	~Row();
	Row(char*, int, char*, double, char*);
	Row(const Row&);
	Row& operator=(const Row&);
	const char* getStudentName()const;
	int getStudentAge()const;
	const char* getSubject()const;
	double getGrade()const;
	const char* getDate()const;
	void setStudentName(char*);
	void setStudentAge(int);
	void setSubject(char*);
	void setGrade(double);
	void setDate(char*);

	friend bool compareByStudentNameAsc(Row*, Row*);
	friend bool compareByStudentNameDesc(Row*, Row*);

	friend bool compareByStudentAgeAsc(Row*, Row*);
	friend bool compareByStudentAgeDesc(Row*, Row*);

	friend bool compareByStudentSubjectAsc(Row*, Row*);
	friend bool compareByStudentSubjectDesc(Row*, Row*);

	friend bool compareByStudentGradeAsc(Row*, Row*);
	friend bool compareByStudentGradeDesc(Row*, Row*);

	friend bool compareByStudentDateAsc(Row*, Row*);
	friend bool compareByStudentDateDesc(Row*, Row*);

	std::ostream& operator<<(std::ostream& os)
	{
		os << studentName << ", " << studentAge << ", " << subject << ", " << grade << ", " << date << '\n';
		return os;
	}
private:
	char* studentName;
	int studentAge;
	char* subject;
	double grade;
	char* date;

private:
	void copy(const Row&);
	void destroy();
};

