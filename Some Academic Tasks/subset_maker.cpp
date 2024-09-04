//#include<iostream>
//using namespace std;
//
//int** ComputeSubsets(int* a, int size, int k)
//{
//	static int total = 10;
//	static int curr;
//	static int skip;
//	static int start;
//	
//
//
//	//----INIT
//	
//	
//	static int** arr = new int* [total];
//	for (int i = 0; i < size; i++)
//	{
//		arr[i] = new int[k];
//	}
//
////	fillsubs(arr, a, size, k, skip + k - 1, size);
//
//	//--------
//
//	if (curr == (total - k))
//	{
//		for (int z = 0; z < total; z++)
//		{
//			for (int j = 0; j < k; j++)
//			{
//				cout << arr[z][j] << " ";
//			}
//			cout << "\n";
//		}
//		return arr;
//	}
//	//--------
//
//	int i = 0;
//	int j = 0;
//
//
//	/*for (i = 0; i < size; i++)
//	{
//		for ( j = 0; j < k; j++)
//		{
//			arr[i][j]
//		}
//	}*/
//
//
//	for (i = 0; i < k - 1; i++)
//	{
//		arr[curr][i] = a[i];
//	}
//
//	arr[curr][i] = a[skip + i];
//	skip++;
//	curr++;
//
//	if (skip >= k)
//	{
//		start++;
//		skip = 0;
//	}
//	
//	return ComputeSubsets(a, size, k);
//
//}
//
//
//int main()
//{
//	int x = 5;
//	int* a = new int[x]{1,2,3,4,5};
//	
//	int k = 3;
//	int** ax = ComputeSubsets(a, x, k);
//
//	return 0;
//}