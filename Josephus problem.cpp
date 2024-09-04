#include<iostream>
#include<string>
#include<Windows.h>
#include "mygraphics.h"
#include "myconsole.h"
using namespace std;


template<typename T>
class Node
{
public:
	Node<T>* next;
	T data;

	Node()
	{
		next = NULL;
	}
	Node(T v)
	{
		next = NULL;
		data = v;
	}
};


template<typename T>
class LinkedList
{
	Node<T>* head;
	Node<T>* tail;

public:
	LinkedList() { head = NULL; tail = NULL; }
	bool insertAtTail(T const Val);
	bool DeleteFromTail();
	bool DeleteFromHead();
	bool IsEmpty() { return head == NULL; }
	bool IsFull() { return head != NULL; }
	T Top();
	bool isLast() { return (head->next == NULL); }
	void Print();
	void PrintG(int n);
	~LinkedList();
};

template<typename T>
LinkedList<T>::~LinkedList()
{
	Node<T>* curr;

	while (head != NULL)
	{
		curr = head;
		head = head->next;
		delete curr;
	}
}

template<typename T>
bool LinkedList<T>::DeleteFromHead()
{
	if (head != NULL)
	{
		Node<T>* temp = head;
		head = head->next;
		delete temp;
		return true;
	}
	return false;
}

template<typename T>
T LinkedList<T>::Top()
{
	if (head == NULL)
	{
		return NULL;
	}
	return head->data;

}

template<typename T>
void LinkedList<T>::Print()
{
	cout << endl;
	Node<T>* curr = head;
	while (curr != NULL)
	{
		cout << curr->data << "";
		curr = curr->next;
	}
}

template<typename T>
void LinkedList<T>::PrintG(int n)
{
	int r = 10;
	
	Node<T>* curr = head;
	int start = 10; int end = 10;
	int x1 = start;
	int x2 = start + end;
	int y1 = start;
	int y2 = start + end;
	while (curr != NULL)
	{
		myEllipse(x1, int y1, int x2, int y2, COLORREF colorForeground, COLORREF colorBackground);
		x1 += (x1 * x1 + 10);
		y1 += (y1 * y1 + 10);
		curr = curr->next;
	}
}


template<typename T>
bool LinkedList<T>::insertAtTail(T const Val)
{
	Node<T>* n = new Node<T>(Val);
	if (head == NULL)
	{
		head = n;
		tail = n;
		return true;
	}
	else
	{
		tail->next = n;
		tail = n;
		return true;
	}

	return false;
}

template<typename T>
bool LinkedList<T>::DeleteFromTail()
{
	if (head != NULL)
	{
		Node<T>* temp = head;

		while ((temp->next)->next != NULL)//finding last before last
		{
			temp = temp->next;
		}
		tail = temp;
		temp = temp->next;
		tail->next = NULL;
		delete temp;

	}

	return false;
}



template<typename T>
class Queue
{
	LinkedList<T>* que;

public:
	Queue()
	{
		que = new LinkedList<T>;
	}
	bool Enqueue(T Val) { return que->insertAtTail(Val); }
	bool dequeue() { return que->DeleteFromHead(); }
	void PrintData() { que->Print(); }
	void PrintGraphics(int n) { que->PrintG(n); }
	T Top() { return que->Top(); }
	bool isEmpty() { return que->IsEmpty(); }
	bool islast() { return (que->isLast()); }

	~Queue() { delete que; }
};

template<typename T>
void Josi(Queue<T>& q, int skips, int &n, int st)
{

	if (q.islast())
		return;

	Queue<T> temp;
	int var = ((st + skips) % n);
	for (int i = 0; i < n; i++)
	{
		if (i != var)
			temp.Enqueue(q.Top());
		q.dequeue();
	}
	n -= 1;
	for (int i = 0; i < n; i++)
	{
		q.Enqueue(temp.Top());
		temp.dequeue();
	}
	st = var;
	//temp.~Queue();
	q.PrintData();
	Josi(q, skips, n , st);

}



//template<typename T>
//void Josi(Queue<T>& q, int skips)
//{
//
//	if (q.islast())
//		return;
//
//	Queue<T> temp;
//	int i;
//	for ( i = 0; i < skips; i++)
//	{
//		temp.Enqueue(q.Top());
//		q.dequeue();
//		if (q.isEmpty())
//			break;
//	}
//	for (int j = 0; j <= i-1; j++)
//	{
//		q.Enqueue(temp.Top());
//		temp.dequeue();
//	}
//	//temp.~Queue();
//	q.PrintData();
//	Josi(q, skips);
//
//}


int main()
{
	Queue<int>que;
	int n, s, k;
	cin >> n;
	cin >> s;
	cin >> k;
	
	for (int i = 0; i < n; i++)
	{
		que.Enqueue((i+1));
	}
	que.PrintData();
	Josi(que, k-1, n, s-1);
	
	
	return 0;
}