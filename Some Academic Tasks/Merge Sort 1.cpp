#include <iostream>
using namespace std;

//void Merge(int arr0[], int arr1[], int end0, int end1)
//{
//	int size = end0 + end1;
//	int* arr = new int[size];
//	for (int i = 0, j = 0, k = 0; i < size; i++)
//	{
//		if (arr0[j] < arr1[k])
//		{
//			arr[i] = arr0[j];
//			j++;
//		}
//		else
//		{
//			arr[i] = arr0[k];
//			k++;
//		}
//	}
//	cout << endl;
//	for (int i = 0; i < size; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	system("pause>0");
//	cout << endl;
//}
void MergeSort(int arr[], int low, int high)
{
   
   if (low >= high || high == 0)
   {
       return;
   }

   int half = low + (high - low) / 2;      //0 + (6-0) /2 = 6/2 = 3 OR (high-low)
   int sec_half = half + 1;
   MergeSort(arr, low, half);
   MergeSort(arr, sec_half, high);   //sustaining high for breaking
  

   /*For every recursive call...both of arr1 and arr2 will return single element
   then merging is performed in last to start till solution*/


   // -----stores first half
   int curr1 = 0;
   int curr_2 = 0;
   int size1 = (half - low) + 1;
   int* arr1 = new int[size1];

   for (int i = 0; i < size1; i++)
   {
       arr1[i] = arr[low + i];
   }

   // -----stores Second
   int size2 = high - half;
   int* arr2 = new int[size2];
   for (int i = 0; i < size2; i++)
   {
       arr2[i] = arr[half + i + 1];
   }



   int original = low;
   //____________MERGING_____________________________
   while (curr1 < size1 && curr_2 < size2)
   {
       if (arr1[curr1] <= arr2[curr_2])    //if(smaller then go to original FIRST)
       {
           arr[original] = arr1[curr1];
           curr1++;
       }
       else
       {
           arr[original] = arr2[curr_2];
           curr_2++;
       }
       original++;
   }
   //--------------------left ones
   while (curr1 < size1)
   {
       arr[original] = arr1[curr1];
       curr1++;
       original++;
   }

   while (curr_2 < size2)
   {
       arr[original] = arr2[curr_2];
       curr_2++;
       original++;
   }



}


// Driver code
int main()
{
   int x = 7;
   int arr[] = { 9, 8, 7, 6, 5, 4, 2 };

   MergeSort(arr, 0, x - 1);
   cout << "sorted :";
   for (int i = 0; i < x; i++)
   {
       cout << arr[i] << " ";
   }
   
   return 0;
}