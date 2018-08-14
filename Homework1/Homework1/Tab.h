#pragma once
#include<iostream>
const int MAXLENURL = 1024;

class Tab

{
public:
	Tab();
	~Tab();
	Tab(char*);
	Tab(const Tab& other);
	Tab& operator=(const Tab& other);
	const char* getURL()const;
	int getTime()const;
	void setURL(char*);
	bool isCurrentTab()const;
	void setIsCurrentTab();
	void printInformatinForTab()const;
	friend bool compareByURL(Tab*, Tab*);
	friend bool compareByTime(Tab*, Tab*);
private:
	void copy(const Tab& other);
	char* URL;
	//because time return secunds from 1.1.1970
	unsigned long int time;
	void destroy();
	bool isCurrent;
};
