///Imlamentation Stack
#include<iostream>

template<typename  T>
struct item
{
	T data;
	item* next;


	item(T otherData)
	{
		data = otherData;
		next = NULL;

	}


};
template<typename  T>
class Stack
{
public:
	Stack();
	Stack(const Stack<T>& other);
	Stack<T>& operator=(const Stack<T>& other);
	~Stack();
	void push(T otherData);
	void pop();
	T peek();
	size_t length();
	bool isEmpty();
	void print();
private:
	size_t lenStack;
	item<T>* top;
	void copy(const Stack<T>& other);
};

template<typename  T>
Stack<T>::Stack()
{
	this->lenStack = 0;
	this->top=NULL;
}

template<typename  T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other)
{
	if (this != &other)
	{
		while (lenStack > 0)
		{
			pop();
		}
		copy(other);
	}
	return *this;
}

template<typename  T>
Stack<T>::Stack(const Stack<T>& other)
{
	copy(other);

}

template<typename  T>
Stack<T>::~Stack()
{
	while (lenStack > 0)
	{
		pop();
	}
}
template<typename  T>
void Stack<T>::push(T otherData)
{
	item<T>*  temp =	new item<T>(otherData);
	if (isEmpty())
	{
		top = temp;
	}
	else
	{
		temp->next = top;
		top = temp;
	}
	++lenStack;

}
template<typename  T>
void Stack<T>::pop()
{
	if (isEmpty())
	{
		throw  "The stack is empty ";
		
	}
	else
	{

		item<T>* temp = top;
		top = top->next;
		delete [] temp;
		--lenStack;
	
	}
}
template<typename  T>
T Stack<T>::peek()
{
	return top->data;
}


template<typename  T>
size_t Stack<T>::length()
{
	return  lenStack;
}

template<typename  T>
bool Stack<T>::isEmpty()
{
	return top == NULL;
}

template<typename  T>
void Stack<T>::copy(const Stack<T>& other)
{
	Stack t;
	item<T>* index;
	index = other.top;

	while (index != NULL)
	{
		t.push(index->data);
		index = index->next;

	}
	while (!(t.isEmpty()))
	{
		this->push(t.peek());

		t.pop();
	}
}


int main()
{
	std::cout << "Hello" << std::endl;
	
	Stack<int> obj;
	obj.push(1);
	std::cout<<obj.peek();
	obj.push(2);
	std::cout<<obj.peek()<<std::endl;
	std::cout << "len: " << obj.length() << std::endl;
	Stack<int> b(obj);
	std::cout << "len b " << b.length() << std::endl;
 
	Stack<int> c;
	c = obj;
	std::cout << "len c " << b.length() << std::endl;

	return 0;
}