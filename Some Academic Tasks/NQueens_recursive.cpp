//#include<iostream>
//using namespace std;
//
//
////*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
//
//
//
//int* nQueens()
//{
//	int n = 8;
//	int noKill = 0;
//	bool gotKilled = false;
//	static int* arr = new int [n] {0};
//	static int queen;
//	static int c;
//
//	//-----BASE
//	if (queen >= n)
//	{
//		return arr;
//	}
//	//-------
//	//Queen i 0, c = 0
//	arr[queen] = c + 1;
//	if (queen == 0)
//	{
//		queen = 1;
//		c = 0;
//
//		arr[queen] = c + 1;
//		
//	}
//
//
//	/*Queen is at 0, hence its col is 0 but value is 1*/
//	int r = queen;
//
//
//	/*
//			<=======================	COUP DE`ITAT	===========================>
//	*/
//
//	int row = r, col = c;
//	//---------------------------------------------------> UP
//	if (row > 0)
//	{
//		gotKilled = false;
//		noKill += 1;//ALIVE
//		for (int i = row - 1; i >= 0; i--)
//		{
//			if (arr[i] == col + 1)	//if that place contains the queen already
//			{
//				gotKilled = true;
//				noKill -= 1;
//				
//				break;
//			}
//		}
//		//attacked(row, c, 0, n);
//
//	}
//	else
//	{
//		//if queen gets abandoned in territory	
//		gotKilled = false;
//		noKill += 1;//alive
//	}
//
//	//------------------------------------------------------> UP_RIGHT	
//	row = r, col = c;
//	if (row > 0 && col < n - 1)
//	{
//		gotKilled = false;
//		noKill += 1;//ALIVE
//		for (int i = row - 1, j = col + 1; (i >= 0 && j <= n) && !gotKilled; i--, j++)	//i will decrement and c will increment in each iteration
//		{
//			if (arr[i] == j + 1)
//			{
//				gotKilled = true;
//				noKill -= 1;
//				
//				break;
//			}
//		}
//	}
//	else
//	{
//		//if queen gets abandoned in territory
//		gotKilled = false;
//		noKill += 1;//ALIVE
//	}
//
//	//----------------------------------------------------> RIGHT
//	row = r, col = c;
//	if (col < n - 1)
//	{
//		gotKilled = false;
//		noKill += 1;//ALIVE
//		for (int i = col + 1; i < n && !gotKilled; i++)
//		{
//			if (arr[row] == i + 1)
//			{
//				gotKilled = true;
//				noKill -= 1;
//				
//				break;
//			}
//		}
//
//	}
//	else
//	{
//		//if queen gets abandoned in territory
//		gotKilled = false;
//		noKill += 1;//ALIVE
//	}
//
//	//-----------------------------------> DOWN-RIGHT
//
//	row = r, col = c;
//	if (col < n - 1 && row < n - 1)
//	{
//		gotKilled = false;
//		noKill += 1;//ALIVE
//		for (int i = row + 1, j = col + 1; i < n && j < n && !gotKilled; i++, j++)
//		{
//			if (arr[i] == j + 1)
//			{
//				gotKilled = true;
//				noKill -= 1;
//			
//				break;
//			}
//		}
//
//	}
//	else
//	{
//		//if queen gets abandoned in territory
//		gotKilled = false;
//		noKill += 1;//ALIVE
//	}
//
//
//	//-----------------------------------> DOWN
//
//	row = r, col = c;
//	if (row < n - 1)
//	{
//
//		gotKilled = false;
//		noKill += 1;//ALIVE
//		for (int i = row + 1; i < n && !gotKilled; i++)
//		{
//			if (arr[i] == col + 1)
//			{
//				gotKilled = true;
//				noKill -= 1;
//				
//				break;
//			}
//		}
//
//	}
//	else
//	{
//		//if queen gets abandoned in territory
//		gotKilled = false;
//		noKill += 1;//ALIVE
//	}
//
//	//-----------------------------------> DOWN-LEFT
//
//	row = r, col = c;
//	if (col > 0 && row < n - 1)
//	{
//
//		gotKilled = false;
//		noKill += 1;//ALIVE
//		for (int i = row + 1, j = col - 1; i < n && j >= 0 && !gotKilled; i++, j--)
//		{
//			if (arr[i] == j + 1)
//			{
//				gotKilled = true;
//				noKill -= 1;
//			
//				break;
//			}
//		}
//
//	}
//	else
//	{
//		//if queen gets abandoned in territory
//		gotKilled = false;
//		noKill += 1;//ALIVE
//	}
//
//	//----------------------------------------------------> LEFT
//	row = r, col = c;
//	if (col > 0)
//	{
//		gotKilled = false;
//		noKill += 1;//ALIVE
//
//		for (int i = col - 1; i >= 0 && !gotKilled; i--)
//		{
//			if (arr[row] == i + 1)
//			{
//				gotKilled = true;
//				noKill -= 1;
//			
//				break;
//			}
//		}
//
//
//	}
//	else
//	{
//		//if queen gets abandoned in territory
//		gotKilled = false;
//		noKill += 1;//ALIVE
//	}
//
//	//CHECK PARAMETERS OF EACH LOOP
//
//	//------------------------------------------------------> UP_LEFT	
//	row = r, col = c;
//	if (row > 0 && col > 0)
//	{
//		gotKilled = false;
//		noKill += 1;//ALIVE
//		for (int i = row - 1, j = col - 1; (i >= 0 && j >= 0) && !gotKilled; i--, j--)	//i will decrement and c will increment in each iteration
//		{
//			if (arr[i] == j + 1)
//			{
//				gotKilled = true;
//				noKill -= 1;
//			
//				break;
//			}
//		}
//	}
//	else
//	{
//		//if queen gets abandoned in territory
//		gotKilled = false;
//		noKill += 1;//ALIVE
//	}
//
//	
//	if (noKill == 8 && c != n - 1)
//	{
//		queen++;
//		c = 0;
//	}
//	else if ((c) == n-1)
//	{
//	
//	
//		int i;
//		queen -= 1;
//	
//		for (i = n-1; i > queen; i--)
//		{
//			arr[i] = 0;
//		}
//		c = arr[queen];
//		
//	}
//	else
//	{
//		c += 1;
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (arr[i] == j + 1)
//			{
//				cout << arr[i] << " ";
//			}
//			else
//				cout << "0 ";
//		}
//		cout << endl;
//	}
//	system("cls");
//	
//
//
//	return nQueens();
//}
//
//
//int main()
//{
//	nQueens();
//
//	return 0;
//}