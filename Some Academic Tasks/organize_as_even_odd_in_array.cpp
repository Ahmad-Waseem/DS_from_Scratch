#include<iostream>
using namespace std;

void evenOdd(int* A, int size)
{
	static int curr = 0;
	int tcurr = 0;
	//int* i = A;
	//int* next = i;
	//++next;
	if (curr == size)
		return;
	
	if (A[curr] % 2 != 0)
	{
		tcurr = curr;
		while (tcurr + 1 < size)
		{
			int temp = A[tcurr];
			A[tcurr] = A[tcurr + 1];
			A[tcurr + 1] = temp;
			tcurr++;
		}
	}
	curr++;
	evenOdd(A, size);

}


int main()
{
	int x = 5;
	int* arr = new int[x];
	cout<<"enter Values: ";
	for (int i = 0; i < x; i++)
	{
		cin >> arr[i];
	}


	evenOdd(arr, x);

	for (int i = 0; i < x; i++)
	{
		cout<<arr[i];
	}

	return 0;
}

