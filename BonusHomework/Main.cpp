#include<iostream>

struct Node {
	int data;
	Node* next;

	Node(int data, Node* next)
	{
		this->data = data;
		this->next = next;
	}
};

void createNode(Node* head, int data)
{
	Node* temp = new Node(data, NULL);
 
	if (head == NULL)
	{
		head = temp;
	}
	else
	{
		while (head->next!=NULL)
		{
			head = head->next;
		}
		head->next = temp;
	}
}

void Rearrange(Node** head)
{
	Node* temp = *head;
	int sizeOfList = 0;
	while (temp != NULL)
	{
		++sizeOfList; 
		temp = temp->next;

	}
	temp = *head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	Node* last = temp;
	temp = *head;
	Node* prev = NULL;
	while (sizeOfList >0)
	{
		if (temp->data % 2!=0)
		{
			last->next = temp;
			last = temp;
			temp = temp->next;
			last->next = NULL;
			if (prev != NULL)
			{
				prev->next = temp;
			}
		}
		else
		{
			if (prev == NULL)
			{
				prev = temp;
				*head = prev;
			
			}
			else
			{
				prev->next = temp;
				prev = prev->next;

			}
			temp = temp->next;
			
		}

		--sizeOfList;
	}

}


int main()
{
	Node* head = new Node(1,NULL);
	createNode(head, 5);
	createNode(head, 2);
	createNode(head, 700);
	createNode(head, 1);
	createNode(head, 6);
	createNode(head, 4);
	createNode(head, 7);
	createNode(head, 100);

	Node* iter = head;
	while (iter->next != NULL)
	{
		std::cout << iter->data << "->";
		iter = iter->next;
	}
	std::cout << iter->data << std::endl;
	Rearrange(&head);

	iter = head;
	while (iter->next != NULL)
	{
		std::cout << iter->data << "->";
		iter = iter->next;
	}
	std::cout << iter->data << std::endl;
	
	return 0;
}