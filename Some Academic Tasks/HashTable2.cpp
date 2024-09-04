#include<iostream>
using namespace std;

template<class T>
class LinkedList
{

private:

	class Node
	{
	public:
		friend class LinkedList<T>;
		Node* next;
		T data;

		Node(T dta)
		{
			data = dta;
			next = NULL;
		}
	};

	Node* head;

public:
	LinkedList()
	{
		head = NULL;
	}
	void Insert_head(T value)
	{
		Node* n = new Node(value);

		if (head == NULL)
		{
			head = n;
		}
		else
		{
			n->next = head;
			head = n;
		}
	}
	void Insert_tail(T value)
	{
		Node* n = new Node(value);
		if (head == NULL)
		{
			head = n;
		}
		else
		{
			Node* curr = head;
			while (curr->next != NULL)
			{
				curr = curr->next;

			}
			curr->next = n;
		}
	}
	void dlt(T value)
	{
		if (head == NULL)
		{
			return;
		}
		else
		{
			Node* curr = head;
			Node* prev = NULL;

			while (curr->data != value && curr != NULL)
			{
				prev = curr;
				curr = curr->next;
			}

			if (curr != NULL && curr->data == value && prev != NULL)
			{
				if (curr->next != NULL)
				{
					prev->next = curr->next;
				}
				else
				{
					prev->next = NULL;
				}
			}
			else if (prev == NULL && head->data == value)
			{
				if (head->next != NULL)
				{
					head = head->next;
				}
				else
				{
					head = NULL;
				}
			}
		}
	}
	void print();
};

template<typename T>
void LinkedList<T>::print()
{
	Node* curr = head;

	while (curr != NULL)
	{
		cout << curr->data << "\t";
		curr = curr->next;
	}
}


class HashTable
{
	
	LinkedList<string>* arr;//T = string
	int size;

public:
	HashTable(int sze);
	unsigned long int hf2(string str);
	void insert(string value);
	void deletekey(string value);
	void updatekey(string key1, string key2);
	void print();
};

HashTable::HashTable(int sze)
{
	size = sze;
	arr = new LinkedList<string>[size];//array of heads

}

unsigned long int HashTable::hf2(string str)
{
	unsigned long int value = 0;

	for (int i = 0; i < str.size(); i++)
	{
		value += pow(33, i) * str[i];		//(c^n)*char
	}

	return (value % size);
}


void HashTable::insert(string value)
{
	int index = hf2(value);
	arr[index].Insert_head(value);
}

void HashTable::deletekey(string value)
{
	int index = hf2(value);
	arr[index].dlt(value);
}

void HashTable::updatekey(string key1, string key2)
{


	deletekey(key1);
	insert(key2);
}

void HashTable::HashTable::print()
{


	for (int i = 0; i < size; i++)
	{
		arr[i].print();


	}

}


int main() 
{

	HashTable hts(5);

	hts.insert("abcde");
	hts.insert("fghijd");
	hts.insert("hello");
	hts.insert("ho");
	hts.insert("heoio");
	hts.insert("sdfsdfs");
	
	hts.print();
	cout << "\n";
	hts.deletekey("hello");

	hts.print();
	cout << "\n";
	hts.updatekey("abcde", "edsher");
	hts.print();
	cout << "\n";

}


