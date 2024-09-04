#include<iostream>
#include<string>
using namespace std;



class Node
{
public:
	Node* next;
	string data;

	Node()
	{
		next = NULL;
	}
	Node(string v)
	{
		next = NULL;
		data = v;
	}
};



class LinkedList
{
	Node* head;
	Node* tail;

public:
	LinkedList() { head = NULL; tail = NULL; }
	bool insertAtTail(string const Val);
	bool DeleteFromTail();
	bool DeleteFromHead();
	bool IsEmpty() { return head == NULL; }
	bool IsFull() { return head != NULL; }
	string Top();
	bool isLast() { return (head->next == NULL); }
	void Print();

	~LinkedList();
};


LinkedList::~LinkedList()
{
	Node* curr;

	while (head != NULL)
	{
		curr = head;
		head = head->next;
		delete curr;
	}
}


bool LinkedList::DeleteFromHead()
{
	if (head != NULL)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
		return true;
	}
	return false;
}


string LinkedList::Top()
{
	if (head == NULL)
	{
		return NULL;
	}
	return head->data;

}

void LinkedList::Print()
{
	cout << endl;
	Node* curr = head;
	while (curr != NULL)
	{
		cout << curr->data << " ";
		curr = curr->next;
	}
}


bool LinkedList::insertAtTail(string const Val)
{
	Node* n = new Node(Val);
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


bool LinkedList::DeleteFromTail()
{
	if (head != NULL)
	{
		Node * temp = head;

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




class Queue
{
	LinkedList* que;

public:
	Queue()
	{
		que = new LinkedList;
	}
	bool Enqueue(string Val) { return que->insertAtTail(Val); };
	bool dequeue() { return que->DeleteFromHead(); };
	void PrintData() { que->Print(); };
	string Top() { return que->Top(); }
	bool isEmpty() { return que->IsEmpty(); }
	bool islast() { return (que->isLast()); }

	~Queue() { delete que; }
};



void radix(Queue& q, int n, int k, int& div)
{
	if (k == 0)
		return;
	int cmod = 0;
	int iter = 0;
	Queue* m;
	m = new Queue[10];

	for (int i = 0; i < n; i++)
	{
		cmod = ((q.Top()[k-1] / div) % 10);
		m[cmod].Enqueue(q.Top());
		q.dequeue();
	}
	for (; iter < 10;)
	{
		while (!(m[iter].isEmpty()))
		{
			q.Enqueue(m[iter].Top());
			m[iter].dequeue();
		}
		iter++;
	}
	div *= 10;
	--k;
	radix(q, n, k, div);
}



int main()
{
	Queue que;
	cout << "Enter \n-number of entries: ";

	int n, k;
	cin >> n;
	cout << "\n-digit count for each: ";
	cin >> k;
	int div = 1;

	string val;
	for (int i = 0; i < n; i++)
	{
		cout << "\nEnter value: ";
		cin >> val;
		que.Enqueue(val);
	}
	radix(que, n, k, div);
	que.PrintData();

	return 0;
}