#include "Row.h"

Row::Row()
{
	this->studentName = NULL;
	this->studentAge = 0;
	this->subject = NULL;
	this->grade = 0.0;
	this->date = NULL;
}


Row::~Row()
{
	destroy();
}

Row::Row(char * otherStudentName, int otherStudentAge, char * otherSubject, double otherGrade, char *otherDate)
{
	setStudentName(otherStudentName);
	setStudentAge(otherStudentAge);
	setSubject(otherSubject);
	setGrade(otherGrade);
	setDate(otherDate);
}

Row::Row(const Row & other)
{
	copy(other);
}

Row & Row::operator=(const Row &other)
{
	if (this != &other)
	{
		destroy();
		copy(other);
	}
	return *this;
}

const char * Row::getStudentName() const
{
	return this->studentName;
}

int Row::getStudentAge() const
{
	return this->studentAge;
}

const char * Row::getSubject() const
{
	return this->subject;
}

double Row::getGrade() const
{
	return this->grade;
}

const char * Row::getDate() const
{
	return this->date;
}

void Row::setStudentName(char * otherStudentName)
{
	delete[] studentName;

	int lenStudentName = strlen(otherStudentName) + 1;
	this->studentName = new char[lenStudentName];
	strcpy_s(studentName, lenStudentName, otherStudentName);
}

void Row::setStudentAge(int otherStudentAge)
{
	this->studentAge = otherStudentAge;
}

void Row::setSubject(char * otherSubject)
{
	delete[] subject;

	int lenSubject = strlen(otherSubject) + 1;
	this->subject = new char[lenSubject];
	strcpy_s(subject, lenSubject, otherSubject);
}

void Row::setGrade(double otherGrade)
{
	this->grade = otherGrade;
}

void Row::setDate(char * otherDate)
{
	delete[] date;

	int lenDate = strlen(otherDate) + 1;
	this->date = new char[lenDate];
	strcpy_s(date, lenDate, otherDate);
}


void Row::copy(const Row &other)
{
	setStudentName(other.studentName);
	setStudentAge(other.studentAge);
	setSubject(other.subject);
	setGrade(other.grade);
	setDate(other.date);
}

void Row::destroy()
{
	delete[] studentName;
	delete[] subject;
	delete[] date;

}

bool compareByStudentNameAsc(Row* left, Row* right)
{
	if (strcmp(left->getStudentName(), right->getStudentName()) <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}

}

bool compareByStudentNameDesc(Row* left, Row* right)
{
	if (strcmp(left->getStudentName(), right->getStudentName()) >= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool compareByStudentAgeAsc(Row* left, Row* right)
{
	if (left->getStudentAge() <= right->getStudentAge())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool compareByStudentAgeDesc(Row* left, Row* right)
{
	if (left->getStudentAge() >= right->getStudentAge())
	{
		return true;
	}
	else
	{
		return false;
	}
}


bool compareByStudentSubjectAsc(Row* left, Row* right)
{
	if (strcmp(left->getSubject(), right->getSubject()) <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool compareByStudentSubjectDesc(Row* left, Row* right)
{
	if (strcmp(left->getSubject(), right->getSubject()) >= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool compareByStudentGradeAsc(Row* left, Row* right)
{
	if (left->getGrade() <= right->getGrade())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool compareByStudentGradeDesc(Row* left, Row* right)
{
	if (left->getGrade() >= right->getGrade())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool compareByStudentDateAsc(Row* left, Row* right)
{
	if (strcmp(left->getDate(), right->getDate()) <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool compareByStudentDateDesc(Row* left, Row* right)
{
	if (strcmp(left->getDate(), right->getDate()) >= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

