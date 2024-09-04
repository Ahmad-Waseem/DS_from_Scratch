#include<iostream>
using namespace std;
template<typename T>
class newNode
{
public:
	newNode<T>* next;
	T data;

	newNode()
	{
		next = NULL;
	}
	newNode(T v)
	{
		next = NULL;
		data = v;
	}
};


template<typename T>
class LinkedList
{
	newNode<T>* head;

public:
	LinkedList() { head = NULL; }
	bool insertAtHead(T const Val);
	bool DeleteFromHead();
	bool IsEmpty() { return head == NULL; }
	bool IsFull() { return head != NULL; }
	T Top() { return head->data; }
	void Print();
	~LinkedList();
};

template<typename T>
LinkedList<T>::~LinkedList()
{
	newNode<T>* curr;
	
	while (head != NULL)
	{
		curr = head;
		head = head->next;
		delete curr;
	}
}




template<typename T>
void LinkedList<T>::Print()
{
	cout << endl;
	newNode<T>* curr = head;
	while (curr != NULL)
	{
		cout << curr->data << " ";
		curr = curr->next;
	}	
}

template<typename T>
bool LinkedList<T>::insertAtHead(T const Val)
{
	newNode<T>* n = new newNode<T>(Val);
	if (head == NULL)
	{
		head = n;
		return true;
	}
	else
	{
		n->next = head;
		head = n;
		return true;
	}

	return false;
}

template<typename T>
bool LinkedList<T>::DeleteFromHead()
{
	if (head != NULL)
	{
		newNode<T>* temp = head;
		head = head->next;
		delete temp;
		return true;
	}
	return false;
}



template<typename T>
class Stack
{
	LinkedList<T>* Stk;

public:
	Stack()
	{
		Stk = new LinkedList<T>;
	}
	bool Push(T Val);
	bool Pop();
	void PrintData() { Stk->Print(); }
	T Top() { return Stk->Top(); }
	bool isEmpty() { return Stk->IsEmpty(); }
	~Stack() { delete Stk; }
};

template<typename T>
bool Stack<T>::Push(T Val)
{
	return (Stk->insertAtHead(Val));
}

template<typename T>
bool Stack<T>::Pop()
{
	return Stk->DeleteFromHead();
}