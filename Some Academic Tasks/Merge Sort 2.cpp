#include<iostream>
using namespace std;

void Merge(int arr0[], int arr1[], int end0, int end1)
{
	int size = end0 + end1;
	int* arr = new int[size];
	for (int i = 0, j = 0, k = 0; i < size; i++)
	{
		if (arr0[j] < arr1[k])
		{
			arr[i] = arr0[j];
			j++;
		}
		else
		{
			arr[i] = arr0[k];
			k++;
		}
	}
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	system("pause>0");
	cout << endl;
}

void MergeSort(int arr[], int low, int high)
{
	static int kk;
	cout << ++kk;

	

	if (low >= high || high == 0)
	{
		return;
	}
	int half = high / 2;  //=5-->low+(high-low)/2
	int sechalf = half + 1;
	int* arr1 = new int[half]; //   10/2 =5

	for (int i = 0; i < half; i++)
	{
		arr1[i] = arr[i];
	}

	int* arr2 = new int[sechalf];   //  10/2+1 =6: (high-high/2)= high/2 +1
	for (int i = (sechalf); i < high; i++)
	{
		arr2[i - (sechalf)] = arr[i];
	}

	MergeSort(arr1, 0, half);

	if (half != 0)
	{
		MergeSort(arr2, 0, sechalf);
	}

	Merge(arr1, arr2, half, sechalf);

}

int main()
{
	int x = 10;
	int* a = new int[x];
	for (int i = 0; i < x; i++)
	{
		cin >> a[i];
	}
	MergeSort(a, 0, x);


}