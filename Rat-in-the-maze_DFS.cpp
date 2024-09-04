////ACCURATE CHAL RAHA VRO..!!
//
//#include<iostream>
//#include<string>
//#include <windows.h>
//#include "mygraphics.h"
//#include "myconsole.h"
//using namespace std;
//
//
//void clearscreen()
//{
//	HANDLE hOut;
//	COORD Position;
//
//	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
//
//	Position.X = 0;
//	Position.Y = 0;
//	SetConsoleCursorPosition(hOut, Position);
//}
//
//template<typename T>
//class Node
//{
//public:
//	Node<T>* next;
//	T data;
//	int x;
//	int y;
//
//	Node()
//	{
//		next = NULL;
//	}
//	Node( int r, int c, T v)
//	{
//		next = NULL;
//		data = v;
//		x = r;
//		y = c;
//
//	}
//};
//
//
//template<typename T>
//class LinkedList
//{
//	Node<T>* head;
//
//public:
//	LinkedList() { head = NULL; }
//	bool insertAtHead(int, int, T const Val);
//	bool DeleteFromHead();
//	bool IsEmpty() { return head == NULL; }
//	bool IsFull() { return !(head == NULL); }
//	void Top(int& rx, int& cx, int& dir);
//	T Topx() { return head->x; }
//	T Topy() { return head->y; }
//	T Topd() { return head->data; }
//	void Print();
//
//	~LinkedList();
//};
//
//template<typename T>
//LinkedList<T>::~LinkedList()
//{
//	Node<T>* curr;
//
//	while (head != NULL)
//	{
//		curr = head;
//		head = head->next;
//		delete curr;
//	}
//}
//
//
//template<typename T>
//void LinkedList<T>::Top(int &rx, int &cx, int &dir)
//{
//	rx = head->x;
//	cx = head->y;
//	dir = head->data;
//
//}
//
//template<typename T>
//void LinkedList<T>::Print()
//{
//	cout << endl;
//	Node<T>* curr = head;
//	while (curr != NULL)
//	{
//		cout << curr->data ;
//		cout << curr->x << curr->y << " \n";
//		curr = curr->next;
//	}
//}
//
//template<typename T>
//bool LinkedList<T>::insertAtHead( int r, int c, T const Val)
//{
//	Node<T>* n = new Node<T>( r, c, Val);
//	if (head == NULL)
//	{
//		head = n;
//		return true;
//	}
//	else
//	{
//		n->next = head;
//		head = n;
//		return true;
//	}
//
//	return false;
//}
//
//template<typename T>
//bool LinkedList<T>::DeleteFromHead()
//{
//	if (head != NULL)
//	{
//		Node<T>* temp = head;
//		head = head->next;
//		delete temp;
//		return true;
//	}
//	return false;
//}
//
//
//
//template<typename T>
//class Stack
//{
//	LinkedList<T>* Stk;
//
//public:
//	Stack()
//	{
//		Stk = new LinkedList<T>;
//	}
//	bool Push( int, int, T Val);
//	bool Pop();
//	void PrintData() { Stk->Print(); }
//	void Top(int& r, int& c, int& dir);
//	
//	
//	T TopC() { return (Stk->Topy()); }
//	T TopR() { return (Stk->Topx()); }
//	T TopD() { return (Stk->Topd()); }
//	bool isEmpty() { return Stk->IsEmpty(); }
//	~Stack() { delete Stk; }
//};
//
//template<typename T>
//void Stack<T>::Top(int& r, int& c, int& dir)
//{
//	Stk->Top(r, c, dir);
//}
//
//template<typename T>
//bool Stack<T>::Push(int r, int c, T Val)
//{
//	return (Stk->insertAtHead(r, c, Val));
//}
//
//template<typename T>
//bool Stack<T>::Pop()
//{
//	return Stk->DeleteFromHead();
//}
//
////*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
//
//void PrintMaze(int** arr, int row_size, int col_size)
//{
//	int x1 = 10;
//	int y1 = 10;
//	int x2 = x1 + 20;
//	int y2 = y1 + 20;
//	for (int i = 0; i < row_size; i++)
//	{
//		for (int j = 0; j < col_size; j++)
//		{
//			if (arr[i][j] == 3)
//			{
//				myRect(x1, y1, x2, y2, RGB(0, 0, 1), RGB(0, 150, 155));
//				x1 = x2 + 20;
//				x2 = x1 + 20;
//				//cout << "\033[32m" <<arr[i][j] << "\t";
//			}
//			else if (arr[i][j] == 4)
//			{
//				myRect(x1, y1, x2, y2, RGB(0, 0, 1), RGB(0, 0, 255));
//				x1 = x2 + 20;
//				x2 = x1 + 20;
//				//cout << "\033[32m" <<arr[i][j] << "\t";
//			}
//			else if (arr[i][j] == 1)
//			{
//				myRect(x1, y1, x2, y2, RGB(0, 0, 1), RGB(255, 0, 0));
//
//				x1 = x2 + 20;
//				x2 = x1 + 20;
//				//cout << "\033[31m" << arr[i][j] << "\t";
//			}
//			else if (arr[i][j] == 2)
//			{
//				myRect(x1, y1, x2, y2, RGB(0, 0, 255), RGB(0, 255, 0));
//				//cout << "\033[1m\033[33m" << arr[i][j] << "\t";
//				x1 = x2 + 20;
//				x2 = x1 + 20;
//			}
//			
//			else 
//			{
//				myRect(x1, y1, x2, y2, RGB(0, 0, 1), RGB(0, 0, 0));
//				x1 = x2 + 20;
//				x2 = x1 + 20;
//				//cout << "\033[37m" <<arr[i][j] << "\t";
//			}
//		}
//		y1 = y2 + 20;
//		y2 = y1 + 20;
//		x1 = 10;
//		x2 = x1 + 20;
//
//	}
//}
//
//
//// 0 means Empty
//// 1 means Blocked
//// 2 means Destination
//// 3 means visited
//
//// 3 means UP
//// 2 means RIGHT
//// 1 means DOWN
//// 0 means LEFT
//template<typename T>
//bool RatInTheMaze(Stack<T>& stack)
//{
//	system("pause>0");
//	int r, c, dir;
//	srand(time(NULL));
//	int row_size = rand() % 8 + 8;
//	srand(time(NULL));
//	int col_size = rand() % 8 + 8;
//	int** arr = new int* [row_size];
//	bool up = true;
//	bool down = true;
//	bool right = true;
//	bool left = true;
//	int prevPerforemed = stack.TopD();
//
//	for (int i = 0; i < row_size; i++)
//	{
//		arr[i] = new int[col_size] {0};
//	}
//	
//	bool chk = false;
//	stack.Top(r, c, dir);
//	int forrandom = (row_size * col_size) / 2;
//	int random = (rand() % forrandom) + 8;
//	for (int i = 0; i < random; i++)
//	{
//		int r_R = (rand() % row_size);
//		int c_R = (rand() % col_size);
//
//		if (r_R != r && c_R != c)
//			arr[r_R][c_R] = 1;
//	}
//	
//	arr[rand() % row_size][rand() % col_size] = 2;
//	PrintMaze(arr, row_size, col_size);
//	while (true)
//	{
//		/*If the last direction given IS CURRENTLY BEING USED and next is INSIDE DOMAIN EXPANSION{NO NEED FOR UP}*/
//
//		if (stack.TopD() == 0)// && left)//GOING LEFT
//		{
//			if (stack.TopC() - 1 >= 0)
//			{
//
//				if (arr[r][c - 1] == 1 || arr[r][c - 1] == 3 || arr[r][c - 1] == 4)
//				{
//					stack.Pop();
//					dir = 1;
//					stack.Push(r, c, dir);
//
//					//checkif(r, c, stack.TopD(), prevPerforemed);
//
//					//stack.Push(r, c, dir);
//					left = false;
//				}
//				else if (arr[r][c - 1] == 2)
//				{
//					cout << "\nFOUND";
//					stack.Push(r, --c, dir);
//					arr[r][c] = 3;
//					clearscreen();
//					PrintMaze(arr, row_size, col_size);
//					return true;
//				}
//				else if (arr[r][c] == 0 || arr[r][c] == 3)
//				{
//
//					stack.Push(r, --c, dir);
//					arr[r][c] = 3;
//					up = true;
//					down = true;
//					left = true;
//					right = true;
//					prevPerforemed = stack.TopD(); //it will keep track about what was the last we performed
//				}
//
//
//			}
//			else
//			{
//
//				stack.Pop();
//				dir = 1;
//				stack.Push(r, c, dir);
//				left = false;
//			}
//
//		}/*If going Up does not work, we will go DOWN in the next loop cycle*/
//		else if (stack.TopD() == 1)
//		{
//			if (stack.TopR() + 1 < row_size)
//			{
//
//				if (arr[r + 1][c] == 1 || arr[r + 1][c] == 3 || arr[r + 1][c] == 4)
//				{
//					stack.Pop();
//					dir = 2;
//					stack.Push(r, c, dir);
//
//					//checkif(r, c, stack.TopD(), prevPerforemed);
//					/*dir = 2;
//					stack.Push(r, c, dir);*/
//					down = false;
//				}
//				else if (arr[r + 1][c] == 2)
//				{
//					cout << "\nFOUND";
//					stack.Push(++r, c, dir);
//					arr[r][c] = 3;
//					clearscreen();
//					PrintMaze(arr, row_size, col_size);
//					return true;
//				}
//				else if (arr[r][c] == 0 || arr[r][c] == 3)
//				{
//
//					stack.Push(++r, c, dir);
//					arr[r][c] = 3;
//					up = true;
//					down = true;
//					left = true;
//					right = true;
//					prevPerforemed = stack.TopD();
//				}
//
//			}
//			else
//			{
//				stack.Pop();
//				dir = 2;
//				stack.Push(r, c, dir);
//				down = false;
//			}
//		}/*going Right may be Right!!!!*/
//		else if ((stack.TopD() == 2))
//		{
//			if (stack.TopC() + 1 < col_size)
//			{
//
//				if (arr[r][c + 1] == 1 || arr[r][c + 1] == 3 || arr[r][c + 1] == 4)
//				{
//					stack.Pop();
//					dir = 3;
//					stack.Push(r, c, dir);
//					//checkif(r, c, stack.TopD(), prevPerforemed);
//					//dir = 3;
//					//stack.Push(r, c, dir);
//					right = false;
//				}
//				else if (arr[r][c + 1] == 2)
//				{
//					cout << "\nFOUND";
//					stack.Push(r, ++c, dir);
//					arr[r][c] = 3;
//					clearscreen();
//					PrintMaze(arr, row_size, col_size);
//					return true;
//				}
//				else if (arr[r][c] == 0 || arr[r][c] == 3)
//				{
//
//					stack.Push(r, ++c, dir);
//					arr[r][c] = 3;
//					up = true;
//					down = true;
//					left = true;
//					right = true;
//					prevPerforemed = stack.TopD();
//				}
//
//
//			}
//			else
//			{
//				stack.Pop();
//				dir = 3;
//				stack.Push(r, c, dir);
//				right = false;
//			}
//		}/*Only for UP*/
//		else if ((stack.TopD() == 3))
//		{
//			if (stack.TopR() - 1 >= 0)
//			{
//
//				if (arr[r - 1][c] == 1 || arr[r - 1][c] == 3 || arr[r - 1][c] == 4)
//				{
//
//					stack.Pop();
//					dir = 0;
//					stack.Push(r, c, dir);
//					//checkif(r, c, stack.TopD(), prevPerforemed);
//
//					//stack.Push(r, c, dir);
//					up = false;
//				}
//				else if (arr[r - 1][c] == 2)
//				{
//					cout << "\nFOUND";
//					stack.Push(--r, c, dir);
//					arr[r][c] = 3;
//					clearscreen();
//					PrintMaze(arr, row_size, col_size);
//					return true;
//				}
//				else if (arr[r][c] == 0 || arr[r][c] == 3)
//				{
//
//					stack.Push(--r, c, dir);
//					arr[r][c] = 3;
//					up = true;
//					down = true;
//					left = true;
//					right = true;
//					prevPerforemed = stack.TopD();
//				}
//
//
//
//			}
//			else
//			{
//				stack.Pop();
//				dir = 0;
//				stack.Push(r, c, dir);
//				up = false;
//			}
//
//		}
//
//		int openDirs = 0;
//		if (up == false)
//			openDirs += 1;
//		if (down == false)
//			openDirs += 1;
//		if (right == false)
//			openDirs += 1;
//		if (left == false)
//			openDirs += 1;
//
//		if (openDirs > 3)
//		{
//			arr[r][c] = 4;
//			stack.Pop();
//			if (stack.isEmpty())
//			{
//				cout << "\nNO WAY HOME";
//				return 0;
//			}
//			stack.Top(r, c, dir);
//			up = true;
//			down = true;
//			left = true;
//			right = true;
//		}
//
//
//		clearscreen();
//		PrintMaze(arr, row_size, col_size);
//
//		Sleep(100);
//
//
//	}
//
//	return 0;
//}
//
//int main()
//{
//
//
//
//	Stack<int> stack;
//	stack.Push(1, 3, 0);//x,y,d
//	RatInTheMaze(stack);
//
//}