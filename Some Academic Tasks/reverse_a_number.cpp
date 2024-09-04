#include<iostream>
using namespace std;

int reversi(int n, int& power)
{
	static int s;
	
	if (n == 0)
	{
		return s;
	}

	int r = n % 10;
	s = (s * 10) + r;


	return reversi(n/power, power);//will transfer 1234 and pow=10

}


int main()
{
	
	int num = 1234567;
	int p = 10;
	cout << reversi(num, p);

}