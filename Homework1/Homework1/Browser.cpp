#include "Browser.h"
#include"Tab.h"
#include "DoubleLinkedList.h"

Browser::Browser()
{
	Tab* tab = new Tab;
	tabs.pushFront(tab);
	current = tabs.getFirstBox();
}

void  Browser::go(char * URL)
{
	current->data->setURL(URL);
}

void Browser::insert(char * URL)
{
	int counter = 0;
	while (!tabs.getFirst()->isCurrentTab())
	{
		tabs.pushBack(tabs.getFirst());
		tabs.popFront();
		++counter;
	}
	tabs.getFirst()->setIsCurrentTab();

	tabs.pushBack(tabs.getFirst());
	tabs.popFront();
	++counter;
	Tab* newTab = new Tab(URL);
	tabs.pushFront(newTab);
	current = tabs.getFirstBox();


	for (size_t i = 1; i <= counter; i++)
	{
		tabs.pushFront(tabs.getLast());
		tabs.popBack();

	}

}

void Browser::back()
{

	if (current->pprev != NULL)
	{
		int counter = 0;
		while (!tabs.getFirst()->isCurrentTab())
		{
			tabs.pushBack(tabs.getFirst());
			tabs.popFront();
			++counter;
		}
		tabs.getFirst()->setIsCurrentTab();
		tabs.pushFront(tabs.getLast());
		tabs.popBack();
		--counter;
		tabs.getFirst()->setIsCurrentTab();
		current = tabs.getFirstBox();
		while (counter >= 1)
		{
			tabs.pushFront(tabs.getLast());
			tabs.popBack();
			--counter;
		}
	}

}
void Browser::forward()
{

	if (current->pnext != NULL)
	{
		int counter = 0;
		while (!tabs.getFirst()->isCurrentTab())
		{
			tabs.pushBack(tabs.getFirst());
			tabs.popFront();
			++counter;
		}
		tabs.getFirst()->setIsCurrentTab();
		if (tabs.getFirstBox()->pnext != NULL)
		{
			tabs.getFirstBox()->pnext->data->setIsCurrentTab();
			current = tabs.getFirstBox()->pnext;
		}

		for (size_t i = 1; i <= counter; i++)
		{
			tabs.pushFront(tabs.getLast());
			tabs.popBack();

		}
	}
}

void Browser::remove()
{
	bool isLast = false;
	bool isOnly = false;

	if (tabs.getLast()->isCurrentTab() == true)
	{
		isLast = true;
	}

	if (tabs.getSize() == 1)
	{
		isOnly = true;
	}

	int counter = 0;

	if (isOnly != true)
	{
		if (isLast == true)
		{
			tabs.getLast()->setIsCurrentTab();
			tabs.getLastBox()->pprev->data->setIsCurrentTab();
			current = tabs.getLastBox()->pprev;
			tabs.popBack();
		}
		else
		{
			while (!tabs.getFirst()->isCurrentTab())
			{
				tabs.pushBack(tabs.getFirst());
				tabs.popFront();
				++counter;
			}
			tabs.getFirst()->setIsCurrentTab();
			tabs.getFirstBox()->pnext->data->setIsCurrentTab();
			current = tabs.getFirstBox()->pnext;
			tabs.popFront();

			for (size_t i = 1; i <= counter; i++)
			{
				tabs.pushFront(tabs.getLast());
				tabs.popBack();

			}
		}

	}
	else
	{
		Tab* tab = new Tab();
		tabs.pushFront(tab);
		current = tabs.getFirstBox();
		tabs.popBack();

	}
}



void Browser::print()
{
	elem<Tab*>* iter = tabs.getFirstBox();
	while (iter != NULL)
	{
		iter->data->printInformatinForTab();
		iter = iter->pnext;
	}
}

void Browser::queries()
{
	while (true)
	{



		char* eneterQuery = new char[8];
		std::cin >> eneterQuery;

		if ((strcmp(eneterQuery, "GO") == 0) || (strcmp(eneterQuery, "INSERT") == 0))
		{


			char* URL = NULL;
			URL = new char[MAXLENURL];
			std::cin.getline(URL, MAXLENURL, '\n');

			if (strcmp(eneterQuery, "GO") == 0)
			{

				go(URL);

			}
			else if (strcmp(eneterQuery, "INSERT") == 0)
			{
				insert(URL);

			}
			delete[] URL;
		}
		else if (strcmp(eneterQuery, "BACK") == 0)
		{
			back();
		}
		else if (strcmp(eneterQuery, "FORWARD") == 0)
		{
			forward();
		}
		else if (strcmp(eneterQuery, "REMOVE") == 0)
		{
			remove();
		}
		else if (strcmp(eneterQuery, "PRINT") == 0)
		{
			print();
		}
		else if (strcmp(eneterQuery, "SORT") == 0)
		{
			char* by = new char[5];
			std::cin >> by;
			if (strcmp(by, "URL") == 0)
			{
				current->data->setIsCurrentTab();
				tabs.sort(compareByURL);
				tabs.getFirstBox()->data->setIsCurrentTab();
				current = tabs.getFirstBox();

			}
			if (strcmp(by, "TIME") == 0)
			{
				current->data->setIsCurrentTab();
				tabs.sort(compareByTime);
				tabs.getFirstBox()->data->setIsCurrentTab();
				current = tabs.getFirstBox();


			}

		}

		delete[] eneterQuery;

	}
}
