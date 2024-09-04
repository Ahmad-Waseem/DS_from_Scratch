#include<iostream>
#include<string>
#include<Windows.h>
#include "mygraphics.h"
#include "myconsole.h"
using namespace std;


void clearscreen()
{
	HANDLE hOut;
	COORD Position;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

template<typename T>
class Node
{
public:
	Node<T>* next;
	T data;
	int x;
	int y;

	Node()
	{
		next = NULL;
	}
	Node(int r, int c, T v)
	{
		next = NULL;
		data = v;
		x = r;
		y = c;
	}
};


template<typename T>
class LinkedList
{
	Node<T>* head;
	Node<T>* tail;

public:
	LinkedList() { head = NULL; tail = NULL; }
	bool insertAtTail(int r, int c, T const Val);
	bool DeleteFromHead();
	bool IsEmpty() { return head == NULL; }
	bool IsFull() { return head != NULL; }
	void Top(int& rx, int& cx, int& dir);
	T Topx() { return head->x; }
	T Topy() { return head->y; }
	T Topd() { return head->data; }
	bool isLast() { return (head->next == NULL); }
	void Print();

	~LinkedList();
};


template<typename T>
void LinkedList<T>::Print()
{
	cout << endl;
	Node<T>* curr = head;
	while (curr != NULL)
	{
		cout << curr->data << " ";
		curr = curr->next;
	}
}

template<typename T>
void LinkedList<T>::Top(int &rx, int &cx, int &dir)
{
	if (head != NULL)
	{
		rx = head->x;
		cx = head->y;
		dir = head->data;
	}
}
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
bool LinkedList<T>::insertAtTail(int r, int c, T const Val)
{
	Node<T>* n = new Node<T>(r, c, Val);
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
class Queue
{
	LinkedList<T>* que;

public:
	Queue()
	{
		que = new LinkedList<T>;
	}
	bool Enqueue(int r, int c, T Val) { return que->insertAtTail(r, c, Val); }
	bool dequeue() { return que->DeleteFromHead(); };
	void PrintData() { que->Print(); };
	void Top(int& r, int& c, int& dir);	
	T TopC() { return (que->Topy()); }
	T TopR() { return (que->Topx()); }
	T TopD() { return (que->Topd()); }
	bool isEmpty() { return que->IsEmpty(); }
	bool islast() { return (que->isLast()); }

	~Queue() { delete que; }
};

template<typename T>
void Queue<T>::Top(int& r, int& c, int& dir)
{
	que->Top(r, c, dir);
}


//*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*

void PrintMaze(int** arr, int row_size, int col_size, int row, int col)
{
	int* pathR = new int[arr[row][col] + 1];
	int* pathC = new int[arr[row][col] + 1];
	int TheNum = arr[row][col];

	int i = 0;
	arr[row][col] = -9;
	while (TheNum >= 0)
	{
		TheNum -= 1;
		if (((row - 1) >= 0) && arr[row - 1][col] == TheNum)//up
		{
			++i;
			//pathR[i] = row - 1;
			//pathC[i] = col;
			arr[row - 1][col] = -10;
			row -= 1;
		}
		else if (((row + 1) < row_size) && arr[row + 1][col] == TheNum)//down
		{
			++i;
			//pathR[i] = row + 1;
			//pathC[i] = col;
			arr[row + 1][col] = -10;
			row += 1;
		}
		else if (((col + 1) < col_size) && arr[row][col + 1] == TheNum)//right
		{
			++i;
			/*pathR[i] = row;
			pathC[i] = col + 1;*/
			arr[row][col + 1] = -10;
			col += 1;
		}
		else if (((col - 1) >= 0) && arr[row][col - 1] == TheNum)//left
		{
			++i;
			//pathR[i] = row;
			//pathC[i] = col - 1;
			arr[row][col - 1] = -10;
			col -= 1;
		}

	}

	/*for (int j = 0; j < arr[pathR[0]][pathC[0]]; j++)
	{

		cout << pathR[j] << pathC[j];
		arr[pathR[j]][pathC[j]] = -10;
	}*/


	int start = 100, inc = 20;
	int x1 = start;
	int y1 = start;
	int x2 = x1 + inc;
	int y2 = y1 + inc;

	
	for (int p = 0; p < row_size; p++)
	{
		for (int q = 0; q < col_size; q++)
		{
			if (arr[p][q] == -3)
			{
				myRect(x1, y1, x2, y2, RGB(0, 0, 1), RGB(0, 150, 155));
				x1 = x2 + inc;
				x2 = x1 + inc;
				//cout << "\033[32m" <<arr[i][j] << "\t";
			}
			else if (arr[p][q] == -9)
			{
				myRect(x1, y1, x2, y2, RGB(0, 233, 1), RGB(0, 0, 255));
				x1 = x2 + inc;
				x2 = x1 + inc;
				//cout << "\033[32m" <<arr[i][j] << "\t";
			}
			else if (arr[p][q] == -10)
			{
				myRect(x1, y1, x2, y2, RGB(0, 0, 1), RGB(0, 0, 255));
				x1 = x2 + inc;
				x2 = x1 + inc;
				//cout << "\033[32m" <<arr[i][j] << "\t";
			}
			else if (arr[p][q] == -1)
			{
				myRect(x1, y1, x2, y2, RGB(0, 0, 1), RGB(255, 0, 0));

				x1 = x2 + inc;
				x2 = x1 + inc;
				//cout << "\033[31m" << arr[i][j] << "\t";
			}
			else if (arr[p][q] == 0)
			{
				myRect(x1, y1, x2, y2, RGB(123, 0, 1), RGB(255, 0, 0));

				x1 = x2 + inc;
				x2 = x1 + inc;
				//cout << "\033[31m" << arr[i][j] << "\t";
			}
			else
			{
				myRect(x1, y1, x2, y2, RGB(0, 0, 1), RGB(0, 0, 0));
				x1 = x2 + inc;
				x2 = x1 + inc;
				//cout << "\033[37m" <<arr[i][j] << "\t";
			}
		}
		y1 = y2 + inc;
		y2 = y1 + inc;
		x1 = start;
		x2 = x1 + inc;

	}
}

// -1 means Blocked
// -2 means Empty
// -3 means Destination
//  0 means start
// >0 means visited

// 3 means UP
// 2 means RIGHT
// 1 means DOWN
// 0 means LEFT



// Algo_is:
/*   If gap is Found *=*=*=> PUSH!!!!!   */
/*After it is pushed, Top(r,c) and Pop() then, MOV Algo_is */
template<typename T>
bool RatInTheMaze(Queue<T>& q)
{
	int foundR = -1, foundC = -1;
	int r, c, dir;

	srand(time(NULL));
	int row_size = rand() % 8 + 8;
	srand(time(NULL));
	int col_size = rand() % 8 + 8;

	int** arr = new int* [row_size];
	bool up = true;
	bool down = true;
	bool right = true;
	bool left = true;
	int prevPerforemed = q.TopD();
	int advanced = 0;
	for (int i = 0; i < row_size; i++)
	{
		arr[i] = new int[col_size];
		for (int j = 0; j < col_size; j++)
		{
			arr[i][j] = -2;
		}
	}
	int openDirs = 1;
	int olderDirs = 0;

	bool chk = false;
	q.Top(r, c, dir);
	int forrandom = (row_size * col_size) / 2;
	int random = (rand() % forrandom) + 8;
	for (int i = 0; i < random; i++)
	{
		int r_R = (rand() % row_size);
		int c_R = (rand() % col_size);

		if (r_R != r && c_R != c)
			arr[r_R][c_R] = -1;
	}

	arr[rand() % row_size][rand() % col_size] = -3;

	arr[r][c] = advanced;
	
	while (true)
	{
		//-=-=-=-=-=-=-=-=-=-=> Go in all 4 Directions <=-=-=-=-=-=-=-=-=-=-=-=-=-\\
		GOING LEFT
		
		while (openDirs != 0)
		{
			q.Top(r, c, dir);
			if (q.TopC() - 1 >= 0)
			{
				if (arr[r][c - 1] == -2)
				{
					q.Enqueue(r, c - 1, dir + 1);
					arr[r][c - 1] = q.TopD();
					olderDirs++;
					left = false;
				}
				else if (arr[r][c - 1] == -3)
				{
				
					q.Enqueue(r, c - 1, dir + 1);
					arr[r][c - 1] = q.TopD();
					foundR = r;
					foundC = c - 1;
					clearscreen();
					PrintMaze(arr, row_size, col_size,foundR,foundC);
					return true;
				}
			}
			/*going Right may be Right!!!!*/

			if (q.TopC() + 1 < col_size)
			{
				if (arr[r][c + 1] == -2)
				{
					q.Enqueue(r, c + 1, dir+1);
					right = false;
					arr[r][c + 1] = q.TopD();
					olderDirs++;

				}
				else if (arr[r][c + 1] == -3)
				{

					q.Enqueue(r, c + 1, dir + 1);
					arr[r][c + 1] = q.TopD();
					foundR = r;
					foundC = c + 1;
					clearscreen();
					PrintMaze(arr, row_size, col_size, foundR, foundC);
					return true;
				}
			}

			/*If going Up does not work, we will go DOWN in the next loop cycle*/

			if (q.TopR() + 1 < row_size)
			{
				if (arr[r + 1][c] == -2)
				{
					q.Enqueue(r + 1, c, dir+1);
					arr[r + 1][c] = q.TopD();
					down = false;
					olderDirs++;
				}
				else if (arr[r + 1][c] == -3)
				{

					q.Enqueue(r + 1, c, dir+1);
					arr[r + 1][c] = q.TopD();
					foundR = r + 1;
					foundC = c;
					clearscreen();
					PrintMaze(arr, row_size, col_size, foundR, foundC);
					return true;
				}
			}

			/*Only for UP*/
			if (q.TopR() - 1 >= 0)
			{
				if (arr[r - 1][c] == -2)
				{
					q.Enqueue(r - 1, c, dir + 1);
					arr[r - 1][c] = q.TopD();
					up = false;
					olderDirs++;
				}
				else if (arr[r - 1][c] == -3)
				{
					q.Enqueue(r - 1, c, dir + 1);
					arr[r - 1][c] = q.TopD();
					foundR = r - 1;
					foundC = c;
					clearscreen();
					PrintMaze(arr, row_size, col_size, foundR, foundC);
					return true;
				}
			}
			
			q.dequeue();
			if (q.isEmpty())
				return 0;
			openDirs -= 1;

		}
		openDirs = olderDirs;
	
	}

	return 0;
}


int main()
{
	Queue<int> que;
	que.Enqueue(6, 7, 1);
	
	RatInTheMaze(que);

	

	return 0;
}