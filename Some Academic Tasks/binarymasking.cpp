#include<iostream>
#include<vector>
using namespace std;


void storage(vector<char>& str, char c)
{
   unsigned char mask = 128;  //128 = 10000000
   unsigned char num;
   for (int i = 1; i <= 8; i++)
   {
       num = c;
       num = num & mask;// Xxxxxxxx & 10000000 = X0000000

       if (int(num) == int(mask))
       {
           str.push_back('1');
       }
       else if (int(num) == 0)
       {
           str.push_back('0');
       }

       mask = mask >> 1;
   }


}
int main()
{
       // a = 5(00000101), b = 9(00001001)
   unsigned char a = 128, b = 9;

       // The result is 00000010
   vector<char> st;
       b = (b << 0);
       storage(st, a);
       storage(st, b);
       for (int i = 0; i < st.size(); i++)
       {
           cout << st[i];
       }

       return 0;
   

}