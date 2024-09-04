#include<iostream>
#include<vector>
#include<fstream>
#include<Windows.h>
using namespace std;

class Node
{
public:
   Node* left;
   Node* right;
   char data;
   int freq;

   Node()
   {
       left = NULL;
       right = NULL;
       freq = 0;
       data = NULL;
   }
   Node(const Node& n)
   {
       left = n.left;
       right = n.right;
       freq = n.freq;
       data = n.data;
   }
   Node(char x, int a)
   {
       left = NULL;
       right = NULL;
       freq = a;
       data = x;
   }
   Node(char x, int a, Node* l, Node* r)
   {
       left = l;
       right = r;
       freq = a;
       data = x;
   }


   Node(char a)
   {
       left = NULL;
       right = NULL;
       freq = 1;
       data = a;
   }

   

   void operator=(Node* n)
   {
       freq = n->freq;
       data = n->data;

   }

   void operator=(const Node &n)
   {
       freq = n.freq;
       data = n.data;
       left = n.left;
       right = n.right;
   }

};

//------------------------------------------------------------------------------------------------------

class BST
{
   Node* root;

public:
   BST() { root = NULL; }
   Node* getroot() { return root; }
   bool insert(const char& val);
   Node* Search(char val);
   void inorder();
   int CountNodes();
   int Count(Node* curr);

};

int BST::Count(Node* curr)
{
   static int x;
   
   if (curr == NULL)
       return x;
   else
   {

       Count(curr->left);
       x++;
       Count(curr->right);
       return x;
   }
}

int BST::CountNodes()
{
   Node* temp = root;
   return Count(temp);
}

bool BST::insert(const char &val)
{
	

	if (root == NULL)
	{
       Node* n = new Node(val);
		root = n;
		return true;
	}
	Node* curr = root;
	
	while (true)
	{
		
       if (curr->data == val)
       {
           curr->freq += 1;
           return false;
       }
		else if (curr->data > val)
		{
           
			if (curr->left == NULL)
			{
               Node* n = new Node(val);
				curr->left = n;
				return true;
			}
			
			curr = curr->left;

		}
		else if (curr->data < val)
		{
           
			if (curr->right == NULL)
			{
               Node* n = new Node(val);
				curr->right = n;
				return true;
			}
			
			curr = curr->right;
		}

	}
}

Node* BST::Search(char val)
{
	Node* curr = root;
	while (curr != NULL)
	{
		if (curr->data == val)
			return curr;
		else if (curr->data > val)
		{
			curr = curr->left;
		}
		else if (curr->data < val)
		{
			curr = curr->right;
		}
	}
	return NULL;
}

void printin(Node* curr)//performs LVR
{
   if (curr == NULL)
   {
       return;
   }

   cout << curr->freq << curr->data << endl;
   printin(curr->left);	//visits all lefts till last

   printin(curr->right);	//towards right then  /\
   								//					  ||
}

void BST::inorder()
{
   Node* n = root;
   printin(n);
}


//------------------------------------------------------------------------------------------------------

class minHeap
{

public:
   minHeap(int N = 0)
   {
       size = 0;                   //root = 0, left = 2n+1, right = 2n+2
       length = N;
       arr = new Node[length];  
   }
   void Insert(Node* x);
   void InsertfromBST(BST&);
   bool isEmpty() { return size == 0; }
   bool isOne() { return size == 1; }
   void Necromancer();
   Node deleteMin();
   Node* HuffmanEncoding();
   // parameterized constructor that will take an array of random numbers and its size in parametersand initialize the heap with randomvalues.It will call the buildMinHeap() function to convert the random values into a heap.
	/*void buildMinHeap(); // It will generate heap from random values stored in the object.
   // Inserts the key value in the heap array such that, the resultant heap tree is a complete binary treeand it follows min heap order.
	// Inserts the key value in the heap array such that, the resultant heap tree is a complete binary treeand it follows min heap order.
   // returns true if it is empty
	const Node<T>& getMin() const; //returns minimum value this operation should be performed in O(1)
	// deletes minimum value this operation should be performed in O(logN)
	bool deleteAll(char key); //remove all occurrences of key value from the heap and update the heap accordingly.
   void heapSortdes(int arr[], int n);
   void heapSortasc(int arr[], int n);*/
   void print()
   {
       for (int i = 0; i < size; i++)
       {
           cout << arr[i].data;
       }
   }
   	


   void Heapify();
   int getSize() { return size; }
private:
   Node* arr;                  //= new Node[i], where Node[i] is a node itselves
   int size;                   //number of characters residing
   int length;                 //number of unique characters
	void bubble_up(int ii);     // A recursive method to heapify a subtree with the root at given index.It maintains heap property during insertion
	void bubble_down(int);      // It maintains heap property during deletion
   
};


void print2DUtil(Node* root, int space = 5)
{
   const int COUNT = 10;
   // Base case
   if (root == NULL)
       return;

   // Increase distance between levels
   space += COUNT;

   // Process right child first
   print2DUtil(root->right, space);

   // Print current node after space
   // count
   cout << endl;
   for (int i = COUNT; i < space; i++)
       cout << " ";
   cout << root->data << "\n";

   // Process left child
   print2DUtil(root->left, space);
}


void printspecial(Node*rot)
{
   print2DUtil(rot, 5);
}

Node* encryptor(vector<string>& code, vector<char>& alph, string sum, Node* curr, bool dir)//inorder LVR
{
   if (curr->left == NULL && curr->right == NULL)
   {
       alph.push_back(curr->data);
       code.push_back(sum);
       return NULL;
   }
   encryptor(code, alph, sum + "0", curr->left, dir);
   encryptor(code, alph, sum += "1", curr->right, dir);
}
void searchelement(string& str, Node* curr, char key1, bool& chk)
{
   if (curr == NULL)
   {
       str = str.substr(0, str.size() - 1);
       return;
   }
   else
   {
       if (curr->data == key1)
       {
           chk = true;
           return;
       }
       else if (chk == false)
       {

           if (chk != true)
           {
               str = str + "0";
           }
           searchelement(str, curr->left, key1, chk);
           if (chk != true)
           {
               str = str + "1";
           }
           searchelement(str, curr->right, key1, chk);
           if (chk != true)
           {
               str = str.substr(0, str.size() - 1);
               return;
           }

       }

   }
}

void printbin(Node* r)
{
   string s = "";
   bool b = false;
   
   if (r == NULL)
       return;

   if (r->data != '$')
   {
       searchelement(s, r, r->data, b);
       cout << endl << s << " : " << r->data;
   }
   printbin(r->left);
   
   printbin(r->right);

}

void minHeap::Necromancer()
{
   for (int i = 0; i < length; i++)
   {
       arr[i].left = NULL;
       arr[i].right = NULL;
   }
}


Node* minHeap::HuffmanEncoding()
{
   Necromancer();
   Node* root;
   Node* curr1;
   Node* curr2;
   /*We have to get last 2 deleted nodes */
   while (!(isOne()))
   {
       Node n = deleteMin();
       curr1 = new Node(n.data, n.freq, n.left, n.right);
       Node n1 = deleteMin();
       curr2 = new Node(n1.data, n1.freq, n1.left, n1.right);
    
       root = new Node('$', curr1->freq + curr2->freq);

       root->left = curr1;
       root->right = curr2;

       Insert(root);
       
   }
   
   Node n = deleteMin();
   Node* retuner = new Node(n.data, n.freq, n.left, n.right);
   
   return retuner;
}


Node minHeap::deleteMin()
{
   int temp = size;

   if (temp == 0)
   {
       return NULL;
   }
   Node n = arr[0];//the node which is being deleted; the minimum freq value
   n.left = arr[0].left;
   n.right = arr[0].right;

   arr[0] = arr[temp - 1];
   arr[0].left = arr[temp - 1].left;
   arr[0].right = arr[temp - 1].right;
   

   size -= 1;              //decrease size after deletion

   bubble_down(0);
   return n;
}


void minHeap::Heapify()
{
   int arr;
   int len = length;
   for (int i = len - 1; i >= 0; --i)
   {
       bubble_down(i);
   }
}

void minHeap::Insert(Node* x)
{
   arr[size] = x;
   arr[size].left = x->left;
   arr[size].right = x->right;
   
   bubble_up(size);
   size++;
}

void InsfrmBST(minHeap& h, Node* curr)
{
   static int s = 1;

   if (curr==NULL)
   {
       return;
   }
   InsfrmBST(h, curr->left);
   h.Insert(curr);
   cout << s++ << " ";
   InsfrmBST(h, curr->right);
   

}

void minHeap::InsertfromBST(BST& b)
{
   InsfrmBST(*this, (b.getroot()));
}



void minHeap::bubble_up(int ii)
{
   if (ii == 0)
       return;

   int parent = (ii - 1) / 2;	// index -=1 => index/2


	if (int(arr[ii].freq) < int(arr[parent].freq))	//if parent freq is greater, swap with parent
   {
       Node temp;

       temp = arr[parent];
       arr[parent] = arr[ii];
       arr[ii] = temp;
       
       bubble_up(parent);				//now our beloved child is at parents position...if smaller than elder, REPNL
   }

}
//
//template<typename T>
void minHeap::bubble_down(int ii)
{
   
   int s = size;
   int left = 2 * ii + 1;
   int right = 2 * ii + 2;

   if (left >= s)
       return; 

   int minimum = ii;

   if (arr[ii].freq > arr[left].freq)
   {
       minimum = left;
   }

   if ((right < s) && (arr[minimum].freq > arr[right].freq))
   {
       minimum = right;
   }

   if (minimum != ii)
   {
       Node temp;
       temp = arr[ii];
       arr[ii] = arr[minimum];
       arr[minimum] = temp;
       bubble_down(minimum);
   }
}
//___________________________________________________________________________________________________


int getIndex(vector<char> v, int K)
{
   auto it = find(v.begin(), v.end(), K);

   if (it != v.end())
   {
       int index = it - v.begin();
       return index;
   }
   else
   {
       return -1;//not usable though
   }
}

void MakeEncFile(const vector<string>& code, const vector<char>& alph)
{

   ifstream readfile;
   readfile.open("Sampletexts.txt");

   ofstream bin;
   bin.open("Nuke.dat", ios::binary | ios::out);

   unsigned char ch;
   unsigned char buffer = 0x00; //the character to be read will be stored in ch
   //the binaray wil use buffer
   int bitcount = 0;

   while (!readfile.eof())
   {
       readfile >> std::noskipws >> ch;
       int k = getIndex(alph, ch);                 //k will return index where string resides in code;

       for (int i = 0; i < (code[k].size()); i++)
       {
           buffer = buffer << 1;                    //shift left once

           if (code[k][i] == '0')
           {
               buffer = buffer | 0x00;//place that as bit in last
           }
           else if (code[k][i] == '1')
           {
               buffer = buffer | 0x01;         //place that as bit in last.i.e. buffer + 00000001
           }

           bitcount += 1;
           if (bitcount == 8)//after plaing 8th, PUSH in file
           {
               bin.write((char*)&buffer, 1);
               buffer = buffer & 0x00;         //mov ax, 0x0000
               bitcount = 0;
           }
       }
   }

   if (bitcount != 0)
   {
       buffer << (8 - bitcount);
   }


   bin.write((char*)&buffer, 1);//buffer in 8 bit=1 byte
   buffer = buffer & 0x00;         //AND ax, 0x0000 <=> buffer = buffer ^ buffer;
   bitcount = 0;

   bin.close();
   readfile.close();
   cout << "\nData Loading Successful\n";
   return;
}


void storage(vector<string>& str, unsigned char c)
{
   unsigned char mask = 128;  //128 = 10000000
   unsigned char num;
   for (int i = 1; i <= 8; i++)
   {
       num = c;
       num = num & mask;// Xxxxxxxx & 10000000 = X0000000

       if (int(num) == int(mask))
       {
           str.push_back("1");
       }
       else if (int(num) == 0)
       {
           str.push_back("0");
       }

       mask = mask >> 1;
   }
}

void pasteTofile(const vector<string>& code, Node* temp, Node* root)
{
   /*CLEAR THE CONFUSION: 'string "code" consists of STRINGS of '0' or '1' only!'*/
   ofstream writefile("writing.txt");

   for (int i = 0; i < code.size(); i++)
   {
       if (temp->data != '$')
       {
           writefile << (temp->data);
           cout << (temp->data);
           temp = root;
       }
       if (code[i] == "0")
       {
           temp = temp->left;
       }
       else if (code[i] == "1")
       {
           temp = temp->right;
       }
   }
}

void decFile(Node* curr)
{
   unsigned char ch = 0x00;
   unsigned char var = 0x00;
   
   fstream binry("Nuke.dat", ios::in | ios::binary);
   
   vector<string> str;

   while (!binry.eof())
   {
       binry >> ch;
       storage(str, ch);
   }

   pasteTofile(str, curr, curr);

}




int main()
{
   ifstream reddit("Sampletexts.txt");

   if (!reddit)
   {
       return 0;
   }

   if (!(reddit.is_open()))
   {
       return 0;
   }

   BST l;

   char x;

   while (!reddit.eof())
   {
       reddit >> std::noskipws >> x;
       l.insert(x);
   }
   reddit.close();
  // l.inorder();
   minHeap hp(l.CountNodes());
   //cout << l.CountNodes() << endl;
   hp.InsertfromBST(l);
   //TESTING HEAP==============================================
   hp.print();
   hp.Heapify();
   //TESTING HEAP==============================================

   Node* root = hp.HuffmanEncoding();

   cout << "\n==================================Data loaded as Huff===============================================";
   Node* p = root;
   //printbin(p);



   vector<string> cde;
   vector<char> alpha;

   encryptor(cde, alpha, "", root, false);
   cout << endl;
   for (int i = 0; i < alpha.size(); i++)
   {
       cout << cde[i] << " : " << alpha[i] << endl;
   }    
   MakeEncFile(cde, alpha);
   decFile(root);

   return 0;
}
