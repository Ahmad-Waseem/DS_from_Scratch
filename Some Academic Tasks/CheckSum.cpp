#include<iostream>
using namespace std;



bool check_sum(int* A, int size)
{
	static int i;

	if (i == size)
		return false;

	for (int j = 0; j < i; j++)
	{
		for (int k = j + 1; k < i; k++)
		{
			if (A[i] == A[j] + A[k])
				return true;
		}
	}
	
	i++;
	return check_sum(A, size);

}


int main()
{

	int x = 5;
	int* arr = new int[x];
	cout << "enter Values: ";
	for (int i = 0; i < x; i++)
	{
		cin >> arr[i];
	}
	cout << "\nThe exsistance of solution is: " << check_sum(arr, x);

}