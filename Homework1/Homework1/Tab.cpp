#include "Tab.h"
#include <ctime>
#include<string.h>


Tab::Tab()
{
	URL = NULL;
	setURL("about:blank");
}


Tab::~Tab()
{
	destroy();
}

Tab::Tab(char * otherURL)
{
	URL = NULL;
	setURL(otherURL);
}

Tab::Tab(const Tab & other)
{
	copy(other);
}

Tab & Tab::operator=(const Tab & other)
{
	if (this != &other)
	{
		destroy();
		copy(other);
	}
	return *this;
}

const char * Tab::getURL() const
{
	return this->URL;
}

int Tab::getTime() const
{
	return this->time;
}
bool Tab::isCurrentTab()const
{
	return this->isCurrent;
}

void Tab::setURL(char *otherURL)
{
	destroy();

	this->URL = new char[strlen(otherURL) + 1];
	for (size_t i = 0; i < strlen(otherURL) + 1; ++i)
	{
		URL[i] = otherURL[i];
	}
	this->time = std::time(NULL);
	this->isCurrent = true;

}
void Tab::setIsCurrentTab()
{
	if (isCurrent == true)
	{
		this->isCurrent = false;
	}
	else
	{
		this->isCurrent = true;
	}
}

void Tab::printInformatinForTab() const
{
	if (isCurrent == true)
	{
		std::cout << '>';
	}
	int i = 0;
	if (URL[i] == ' ')
	{
		++i;
	}
	for (; i < strlen(URL) + 1; ++i)
	{
		std::cout << URL[i];
	}
	std::cout << time << std::endl;

}

bool compareByURL(Tab*  left, Tab* right)
{
	if (strcmp(left->getURL(), right->getURL()) <0)
	{
		return true;
	}
	else if (strcmp(left->getURL(), right->getURL()) == 0)
	{
		if (left->getTime() <= right->getTime())
		{
			return true;
		}
		else
		{
			return false;
		}

	}
	else//if ((strcmp(URL, other.getURL()) >0))
	{
		return false;
	}
}

bool compareByTime(Tab * left, Tab* right)
{
	if (left->getTime() < right->getTime())
	{
		return true;
	}
	else if (left->getTime() == right->getTime())
	{

		if (strcmp(left->getURL(), right->getURL()) <= 0)
		{
			return true;
		}

		if (strcmp(left->getURL(), right->getURL()) >0)
		{
			return false;
		}

	}

	else
	{
		return false;
	}
}

void Tab::copy(const Tab & other)
{

	int len = strlen(other.URL) + 1;
	this->URL = new char[len];
	strcpy_s(URL, strlen(URL) + 1, other.URL);


	this->time = std::time(NULL);
	this->isCurrent = other.isCurrent;
}

void Tab::destroy()
{
	if (URL != NULL)
	{
		delete[] URL;
		time = 0;
		isCurrent = false;
	}
}

