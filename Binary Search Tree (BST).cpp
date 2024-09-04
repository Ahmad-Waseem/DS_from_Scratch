#include<iostream>
#include <vector>
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


class Node
{
public:
	int data;
	Node* left;
	Node* right;

	Node(int a = 0) { left = NULL; right = NULL; data = a; }
	 
};

void deleteAll(Node* curr);

class BST
{
	Node* root;

public:
	BST() { root = NULL; }
	Node* getRoot() { return root; }
	int Find_Width();
	void insert(int a);
	void inorder();
	void inorderiter();
	void postorder();
	void postorderiter();
	void preorder();
	void preorderiter();
	bool Search(int a);
	bool IsBST(Node* root);
	void operator=(const BST& );
	bool operator==(const BST& );
	void Delete(int val);
	int count_nodes();
	bool update(int key1, int key2);
	void PathSum(vector<int>& sums);
	void mrr();
	Node* LowestCommonAncestor(int a, int b);
	void Make_Skew(Node* root);
	~BST() { deleteAll(root); }
};

//--------------------------------------------

void deleteAll(Node* curr)
{
	if (curr != NULL)
	{
		if (curr->left == NULL && curr->right == NULL)
		{
			delete curr;
		}
		else
		{
			deleteAll(curr->left);
			deleteAll(curr->right);
		}
	}
}


//-------------------------------------------

int BST::count_nodes()
{
	if (root == NULL)
	{
		return 0;
	}
	int counter = 0;
	Stack<Node*> stack;
	stack.Push(root);//root first, works last


	while (!stack.isEmpty())
	{

		Node* temp = stack.Top();
		counter++;
		stack.Pop();

		if (temp->right != NULL)	//right first because of stacking
		{
			stack.Push(temp->right);
		}

		if (temp->left != NULL)
		{
			stack.Push(temp->left);
		}
	}
	return counter;
}


//------------------------------------------------

//void BST::Make_Skew(Node* root)
//{
//	static Node* prev;
//	static bool once = true;
//	if (root->right == NULL && root->left == NULL)
//	{
//		return;
//	}
// 
// 
// 

//  Make_Skew(root->left);	//visits all lefts till last
//	prev->right = root;
//	prev = root;			//store left most of the branch
//	if (once) { once = false; this->root = prev; }	//make it root if first one
// //prev->left = NULL;		//makes its left null
//	Make_Skew(root->right);	//Go to right nodes

//
//}
void BST::Make_Skew(Node* root) //using LVR
{
	static Node* newroot = NULL;
	static Node* prev;
	
	if (root == NULL)
	{
		return;
	}

	Make_Skew(root->left);    //visits all lefts till last

	if (newroot == NULL)		//checks if new root have been crowned
	{
		this->root = root;
		newroot = root;			//new root filled(Don't use this variable)
		root->left = NULL;
		prev = root;
	}
	else
	{
		prev->right = root;
		root->left = NULL;
		prev = root;
	}

	Make_Skew(root->right);
}

//--------------------------------------------------
Node* findmax(Node* curr2)
{
	if (curr2->right == NULL)
	{
		return curr2;
	}

	else if (curr2 == NULL)
	{
		return NULL;
	}

	else
	{
		return findmax(curr2->right);
	}

}

void dlt(Node* curr)
{
	Node* temp;
	if (curr == NULL)
		return;
	
	else if (curr->right == NULL && curr->left == NULL)
	{
		delete curr;
	}
	else if (curr->left != NULL && curr->right != NULL)
	{
		temp = findmax(curr->left);
		int var = curr->data;
		curr->data = temp->data;
		temp->data = var;
		dlt(temp);
	}
	else
	{
		cout << "itis";
		temp = curr;
		if (curr->left == NULL)
		{
			curr = curr->right;
		}
		else if (curr->right == NULL)
		{
			curr = curr->left;
		}
		else
			curr = NULL;
		delete temp;
	}
}

//---------------------------------




void BST::Delete(int val)
{
	
	Node* curr = root;
	while (curr != NULL)
	{
		if (curr->data == val)
			break;
		else if (curr->data > val)
		{
			curr = curr->left;
		}
		else if (curr->data < val)
		{
			curr = curr->right;
		}
	}
	cout << curr->data << "-----";
	dlt(curr);
}










//-------------------------------------------------------------
bool equationchecker(Node* currfOR1, Node* currfOR2)
{
	if (currfOR1 == NULL && currfOR2 == NULL)
	{
		return true;
	}
	else if((currfOR1 == NULL) ^ (currfOR2 == NULL))
	{
		return false;
	}
		// insert root then go to left first, then insert it
	if (currfOR1->data != currfOR2->data)
	{
		return false;
		
	}
	else
	{
		cout << currfOR1->data;
		equationchecker(currfOR1->left, currfOR2->left);	//visits all lefts till last
		equationchecker(currfOR1->right, currfOR2->right);	//come to last lefts right, then repeat
		return false;
	}	
}

bool BST:: operator==(const BST& original)
{
	Node* THEnode = root;
	Node* anode = original.root;
	return equationchecker(THEnode, anode);
	
}



//-------------------------------------------------------------
void equator(const BST& ori, BST& fill, Node* curr)
{
	if (curr == NULL)
	{
		return;
	}
	fill.insert(curr->data);	// insert root then go to left first, then insert it
	equator(ori, fill, curr->left);	//visits all lefts till last
	equator(ori, fill, curr->right);	//come to last lefts right, then repeat

}

void BST:: operator=(const BST& original)
{
	Node* anode = original.root;
	equator(original, *this ,anode);
	return;
}

//----------------------------------------------------------------------
bool BST::Search(int a)
{
	Node* curr = root;
	while (curr != NULL)
	{
		if (curr->data == a)
			return true;
		else if (curr->data > a)
		{
			curr = curr->left;
		}
		else if (curr->data < a)
		{
			curr = curr->right;
		}
	}
	return false;
}

//------------------------------
void printpre(Node* curr)//VLR
{
	if (curr == NULL)
	{
		return;
	}
	cout << curr->data << " ";
	printpre(curr->left);	//visits all lefts till last
	printpre(curr->right);	//towards right then  /\
								//				  ||
}
void BST::preorder()
{
	Node* n = root;
	printpre(n);
}

//------------------------------


//------------------------------
void BST::preorderiter()//VLR
{
	if (root == NULL)
	{
		return;
	}


	Stack<Node*> stack;
	stack.Push(root);//root first, works last


	while (!stack.isEmpty())
	{

		Node* temp = stack.Top();
		cout << temp->data << " ";
		stack.Pop();

		if (temp->right != NULL)	//right first because of stacking
		{
			stack.Push(temp->right);
		}

		if (temp->left != NULL)
		{
			stack.Push(temp->left);
		}
	}						
}

//------------------------------

void printpost(Node* curr)//LRV
{
	if (curr == NULL)
	{
		return;
	}
	
	printpost(curr->left);	
	printpost(curr->right);
	cout << curr->data << " ";
}

void BST::postorder()
{
	Node* n = root;
	printpost(n);
}

//------------------------------
void BST::inorderiter()//VLR
{
	if (root == NULL)
	{
		return;
	}
	Node* curr = root;

	Stack<Node*> stack;
	

	while (curr != NULL || stack.isEmpty() == false)	//LVR
	{
		//--------
		while (curr != NULL)	//go to full right
		{
			stack.Push(curr);
			curr = curr->left;
		}
		curr = stack.Top();	
		stack.Pop();
		//--------


		cout << curr->data << " ";
		curr = curr->right;
	}
}


//------------------------------
void printin(Node* curr)//performs LVR
{
	if (curr == NULL)
	{
		return;
	}

	printin(curr->left);	//visits all lefts till last
	cout << curr->data << " ";
	printin(curr->right);	//towards right then  /\
							//					  ||
}
void BST::inorder()
{
	Node* n = root;
	printin(n);
}

//-----------------------------------------------------------------------------------
void BST::insert(int a)
{
	Node* n = new Node(a);

	if (root == NULL)
	{
		root = n;
		return;
	}
	Node* curr = root;
	while (true)
	{
		if (curr->data == a)
			return;
		else if (curr->data > a)
		{
			if (curr->left == NULL)
			{
				curr->left = n;
				return;
			}
			curr = curr->left;
		}
		else if (curr->data < a)
		{
			if (curr->right == NULL)
			{
				curr->right = n;
				return;
			}
			curr = curr->right;
		}

	}
}
//--------------------------------------------------------------------------------------------
void Mirror_BST(Node* curr);
void BST::mrr()
{
	Node* temp = root;
	Mirror_BST(temp);
}

void Mirror_BST(Node* curr)
{
	
	if (curr == NULL)
	{
		return;
	}
	else 
	{
		
		Mirror_BST(curr->left);			//goes to left until NULL
		Mirror_BST(curr->right);		//goes to right and repeats the statement above


		/*we will get the rightiest node of left, will swap it to leftiest of right and so on*/
		Node* temp;
		temp = curr->right;
		curr->right = curr->left;
		curr->left = temp;
	}
}



//-------------------------------------------------------------------------------------------



Node* LCA(Node* nod, int a, int b)
{
	if (nod != NULL)
	{
		if ((a >= nod->data && b <= nod->data) || (a <= nod->data && b >= nod->data))
		{
			return nod;
		}
		else if (a < nod->data && b < nod->data)
		{
			return (LCA(nod->left, a, b));
		}
		else if (a > nod->data && b > nod->data)
		{
			return (LCA(nod->right, a, b));
		}
	}
	return NULL;
}


Node* BST::LowestCommonAncestor(int a, int b)
{
	Node* temp = LCA(root, a, b);
	Node* curr = root;
	if (temp != NULL)
	{
		cout << curr->data << " ";
		while (curr->data != temp->data)
		{
			if (curr->data > temp->data)
			{
				curr = curr->left;
			}
			else if (curr->data < temp->data)
			{
				curr = curr->right;
			}
			cout << curr->data << " ";
		}
	}
	return temp;
}
//-----------------------------------------------

int height(Node* curr)
{
	if (curr == NULL)
	{
		return 0;
	}
	else
	{
		int lH = height(curr->left);
		int rH = height(curr->right);


		if (lH < rH)	//if lefth less than righth
		{
			return (rH + 1);
		}
		else
		{
			return (lH + 1);
		}
	}
}

int Curr_Width(Node* temp, int level)
{

	if (temp == NULL)
	{
		return 0;
	}
	if (level == 1)
	{
		return 1;
	}
	else if (level > 1)
	{
		return Curr_Width(temp->left, level - 1) + Curr_Width(temp->right, level - 1);
	}

}

int BST::Find_Width()
{
	Node* temp = root;
	int curr_width;
	int max = 0;

	int x = 1;;
	int h = height(temp);//total hieght = level+1;
	while (x <= h)
	{
		curr_width = Curr_Width(temp, x);
		if (curr_width > max)
		{
			max = curr_width;
		}
		x++;
	}

	return max;
}


//------------------------------------------------------------


int main()
{
	BST l;
	l.insert(2);//root
	l.insert(1);//root->left
	l.insert(5);//root->right
	l.insert(8);//5->right
	l.insert(4);//5->left
	l.insert(3);//1->right

	cout << "Inorder: "; l.inorder();
	cout << "\nInorder iterative: "; l.inorderiter();
	cout << endl;
	cout << "\nPreorder: "; l.preorder();
	cout << "\nPreorder Iterative: "; l.preorderiter();
	cout << endl;
	cout << "\nPostorder: "; l.postorder(); cout << endl;
	
	cout << "\nTotal Nodes: " << l.count_nodes();
	cout << endl;
	BST l1;
	l1 = l;
	
	l1.insert(12321);
	l1.insert(-2);
	
	//cout << "\nPostorder: "; l1.inorder(); cout << endl;
	//l.Delete(5);
	//cout << "\nPostorder: "; l.inorder(); cout << endl;


	//cout << "Inorder: "; l1.inorder(); cout << "\n";
	//l1.mrr();
	//cout << "Inorder: "; l1.inorder(); cout << "\n";
	//cout << l1.Find_Width();
	cout << "Skewed: ";
	l.Make_Skew(l.getRoot());
	l.inorder();
	
}