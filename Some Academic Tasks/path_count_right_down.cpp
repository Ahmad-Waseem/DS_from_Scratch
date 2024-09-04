#include<iostream>
using namespace std;



int countPaths(int n, int m)
{
	//static int i = 0;
	
	if (n == 0 || m == 0)
		return 1;

	return countPaths(n - 1, m) + countPaths(n, m - 1);

	/*if (n == 0 && m == 0)
		return i;
	else if (n == 0)
	{
		i++;
		return countPaths(n, m - 1); 
		
	}
	else if (m == 0)
	{
		i++;
		return countPaths(n-1, m);
		
	}
	else
	{
		i += 2;
		return countPaths(n - 1, m - 1);
	}*/
	
	
}


int main()
{

	int x = 2;
	int y = 2;
	cout << "\nThe exsistance of solution is: " << countPaths(x, y);

	return 0;
}