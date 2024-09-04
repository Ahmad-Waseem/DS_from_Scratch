#include<iostream>
using namespace std;
class Hashtable 
{
	int size;
	int* arr;
	bool flag;
	int coll;
public:
	Hashtable(bool flag, int method) 
	{
		flag = flag;
		size = 10;
		coll = method;
		arr = new int[size] {0};
		if (flag == 0) 
		{
			cout << "\nNRO(No Rehash Ordered)" << endl;
		}
		
	}


	int count();
	float loadingfactor();
	int hf1(int key);
	int hf2(int key);
	int LinearP(int );
	int LinearP_step(int , int );
	int Psuedo(int );
	int dou_Hash(int , int );
	int primer(int );
	void insert(int key);
	int access(int key);
	void dlt(int key);
	void update(int, int);
	void print();
	void Rehashing();
	bool checkColl(int index);
};

int Hashtable::LinearP(int curr) 
{
	while (checkColl(curr) != 0 && checkColl(curr) != -1) 
	{
		curr = (curr + 1) % size;
	}
	return curr;
}
int  Hashtable::LinearP_step(int curr, int stpsz) 
{
	int i = 1;
	int temp = curr;
	while (checkColl(curr) != 0 && checkColl(curr) != -1)
	{
		curr = (temp + (stpsz * i)) % size;//take a step.....if not empty, take a leap
		i++;
	}
	return curr;
}

int  Hashtable::Psuedo(int curr) 
{
	int random[] = { 1,3,5,7,9,11,2,8,6,121 };
	int rnd = curr + 1;
	int temp = curr;
	while (checkColl(curr) != 0 && checkColl(curr) != -1) 
	{
		curr = (temp + random[rnd]) % size;
		rnd++;
	}
	return curr;
}

int Hashtable::hf2(int key) 
{
	return (1 + key % (size - 2));
}


int  Hashtable::dou_Hash(int curr, int val) 
{
	int i = 1;

	int temp = curr;

	while (checkColl(curr) != -1 && checkColl(curr) != 0)
	{
		curr = hf1(temp) + (i * hf2(val)) % size;	//hf1+chf2
		i++;
	}
	return curr;
}

void  Hashtable::Rehashing() //error might be here: "MIGHT BE"
{
	int temp = size;
	size = size * 2;//inc size

	int* dupli = new int[temp];
	
	//copying
	for (int i = 0; i < temp; i++) 
	{
		dupli[i] = arr[i];
	}

	delete[] arr;
	arr = new int[size] {0};

	for (int i = 0; i < temp; i++) 
	{
		if (dupli[i] != -1 && dupli[i] != 0)
		{
			insert(dupli[i]);
		}
	}
}
int Hashtable::primer(int size)
{
	int prime_num = 0;
	for (int i = 2; i < size; i++)
	{
		int chk = 0;
		for (int j = 2; j < size; j++)
		{
			if (i % j == 0)
			{
				chk++;
			}
		}
		if (chk == 1)
		{

			prime_num = i;
		}
	}
	return prime_num;
}

void Hashtable::insert(int val)
{

	if (flag == 1) 
	{
		float x = loadingfactor();
		
		if (x > 5) 
		{
			Rehashing();
		}
	}


	int real = hf1(val);

	if (checkColl(real) != 0 && checkColl(real) != -1) 
	{
		if (coll == 1) 
		{
			int newindex = LinearP(real);
			arr[newindex] = val;
		}
		else if (coll == 2) 
		{
			int constant = primer(size);
			int newindex = LinearP_step(real, constant);
			arr[newindex] = val;
		}

		else if (coll == 3) 
		{
			int newindex = Psuedo(real);
			arr[newindex] = val;
		}

		else if (coll == 4) 
		{

			int newindex = dou_Hash(real, val);
			arr[newindex] = val;
		}
	}
	else 
	{
		arr[real] = val;
	}
}
int  Hashtable::access(int key)
{
	if (coll == 1)
	{

		int real = hf1(key);//key%size;

		if (arr[real] == key)
		{
			return real;
		}

		else
		{
			int num = 0;

			int i = real + 1;
			while (arr[real] != key && arr[real] != 0 && num < 10)
			{
				real = i;
				i = (i + 1) % size;
				num++;
			}

			if (num >= 10 || arr[real] == 0)
			{
				return -1;
			}
			else
			{
				return real;
			}
		}
	}
	/*int real = hf1(val);//key%size;

		if (arr[real] == val)
		{
			return real;
		}
		else
		{
			int i = real;
			i += (i+1) % size;
			
			while (arr[i] != val)
			{
				i = (i + 1) % size;

				if (real == i)
				{
					return -1;
				}
			}

				return i;
*/
	else if (coll == 2)
	{
		int real = hf1(key);
		if (arr[real] == key)
		{
			return real;
		}

		else
		{
			int prime = primer(size);
			int a = 0, temp = real, i = 1;

			while (arr[real] != key && a < size && arr[real] != 0)
			{
				real = temp + (prime * i) % size;
				i++;
			}
			if (a >= size || arr[real] == 0) //not empty
			{
				return -1;
			}
			else
			{
				return real;
			}
		}
	}
	else if (coll == 3)
	{
		int real = hf1(key);
		int random[] = { 1,3,5,7,9,11,2,8,6,121 };

		int i = real + 1;
		int a = 0;

		while (arr[real] != key && a < size && arr[real] != 0)
		{
			real = (real + random[i]) % size;
			i++;
			a++;
		}

		if (a >= size || arr[real] == 0)
		{
			return -1;
		}
		else
		{
			return real;
		}

	}
	else if (coll == 4)
	{
		int real = hf1(key);
		int a = 0;
		int i = real + 1;


		while (arr[real] != key && a < size && arr[real] != 0)
		{
			real = real + (i * hf2(key)) % size;
			i++;
		}

		if (a >= size || arr[real] == 0)
		{
			return -1;
		}
		else
		{
			return real;
		}
	}
}

void Hashtable::dlt(int key) 
{

	int index = access(key);
	arr[index] = 0;

}

void Hashtable::update(int key1, int key2) 
{
	dlt(key1);
	insert(key2);

}

void  Hashtable::print()
{

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int Hashtable::count()
{
	int count = 0;
	for (int i = 0; i < size; i++) 
	{
		if (arr[i] != 0 && arr[i] != -1) 
		{
			count += 1;
		}
	}
	count = count * 10;//0.5 not working
	return count;
}

float Hashtable::loadingfactor() 
{
	float a;
	float b = count();
	a = (b / float(size));
	return float(a);
}

int Hashtable::hf1(int key) 
{
	return (key % size);
}

bool Hashtable::checkColl(int index) 
{
	if (arr[index] >= 2)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}


int main() 
{

	Hashtable obj1(0, 1);

	obj1.insert(10);
	obj1.insert(20);
	obj1.insert(35);
	obj1.insert(46);
	obj1.insert(36);
	obj1.insert(2);
	obj1.insert(22);
	obj1.insert(1002);
	obj1.print();

	cout << endl;
	obj1.update(35, 99);
	
	obj1.print();
	cout << "\n";

	cout << obj1.access(1002) << endl;
	system("pause");
	system("cls");


	Hashtable hts(1, 1);
	hts.insert(10);
	hts.insert(20);
	hts.insert(35);
	hts.insert(46);
	hts.insert(36);
	hts.insert(2);
	hts.insert(22);
	hts.insert(1002);
	hts.print();

	cout << endl;
	hts.update(35, 99);
	hts.dlt(99);
	hts.print();
	cout << "\n";

	cout << hts.access(1002) << endl;
	system("pause");
	system("cls"); 
	
	
	Hashtable htp(0, 2);
	htp.insert(10);
	htp.insert(20);
	htp.insert(35);
	htp.insert(46);
	htp.insert(36);
	htp.insert(2);
	htp.insert(22);
	htp.insert(1002);
	htp.print();

	cout << endl;
	htp.update(35, 99);
	htp.dlt(99);
	htp.print();
	cout << "\n";

	cout << htp.access(1002) << endl;
	system("pause");
	system("cls");
	
	Hashtable htq(1, 3);
	htq.insert(10);
	htq.insert(20);
	htq.insert(35);
	htq.insert(46);
	htq.insert(36);
	htq.insert(2);
	htq.insert(22);
	htq.insert(1002);
	htq.print();

	cout << endl;
	htq.update(35, 99);
	htq.dlt(99);
	htq.print();
	cout << "\n";

	cout << htq.access(1002) << endl;
	system("pause");
	system("cls");
}

////----------------DISCARDED FUNCTIONS AND TEST CASES
////#include<iostream>
////using namespace std;
////
////
////int findPrime(int n)
////{
////	if (n <= 2)
////	{
////		return 1;
////	}
////
////	for (int i = n - 1; n > 2; i--)//find nearest prime less then n
////	{
////		for (int j = i - 1; j > 1; j--)
////		{
////			if (i % j == 0) //if n is divisible, out of loop
////			{
////				break;
////			}
////			if (j == 2)//if it has crossed check post of 2, it is Prime
////			{
////				return i;
////			}
////		}
////	}
////	return 3;//ain wain, due to lack of self-confidence
////}
////
////
////
////class HashTable
////{
////private:
////	int size;// Size will always be odd
////	int* arr;
////public:
////	HashTable();
////	HashTable(int* arr, bool flag, int coll, int);
////	double loadingFactor();
////	int linearP(int curr);
////	int linearP_steps(int curr);
////	int Psuedo(int curr);
////	int hf1(int );
////	int hf2(int );
////	bool insert(int val);
////	bool dlt(int val);
////	bool search(int val);
////	bool update(int old, int news);
////	void print()
////	{
////		for (int i = 0; i < size; i++)
////		{
////			cout << arr[i] << " ";
////		}
////	}
////};
////
////bool HashTable::update(int val, int news)
////{
////	int index = val % size;
////	int start = index;
////	if (arr[index] == val)
////	{
////		arr[index] = -1;
////	}
////	else
////	{
////		index = (index + 1) % size;
////		while (start != index)
////		{
////			if (arr[index] == val)
////			{
////				arr[index] = -1;
////			}
////			index = (index + 1) % size;
////		}
////	}
////	insert(news);
////	return true;
////}
////
////
////bool HashTable::insert(int val)
////{
////	int index = val % size;
////	if (loadingFactor() / size == 1)
////	{
////		return 0;
////	}
////	if (arr[index] != -1)
////	{
////		arr[linearP(index)] = val;
////	}
////	return 1;
////}
////
////bool HashTable::search(int val)
////{
////	int index = val % size;
////	int start = index;
////	if (arr[index] == val)
////		return true;
////	else
////	{
////		index = (index + 1) % size;
////		while (start != index)
////		{
////			if (arr[index] == val)
////				return true;
////			index = (index + 1) % size;
////		}
////	}
////	return false;	
////}
////
////bool HashTable::dlt(int val)
////{
////	int index = val % size;
////	int start = index;
////	if (arr[index] == val)
////	{
////		arr[index] = -1;
////		return true;
////	}
////	else
////	{
////		index = (index + 1) % size;
////		while (start != index)
////		{
////			if (arr[index] == val)
////			{
////				arr[index] = -1;
////				return true;
////			}
////			index = (index + 1) % size;
////		}
////	}
////	return false;
////}
////
////
////int HashTable::hf1(int val)
////{
////	return (val % size);
////}
////
////int HashTable::hf2(int val)
////{
////	int c = 1;
////	int i = 1 + val % (size - 2);
////	while (arr[i] != -1)
////	{
////		i = 1 + val % (size - 2);
////		c += 1;
////	}
////
////
////	return c * i;
////}
////
////
////
////int HashTable::Psuedo(int curr)
////{
////	int p = 101;
////	int c = 200;
////	while (arr[curr] == -1)
////	{
////		curr = (((p * curr) + c) % size) + 1;//new = (bigPrime*old +constant) % size +1
////	}
////	return curr;
////}
////
////int HashTable::linearP(int curr)
////{
////	while (arr[curr] == -1)
////	{
////		curr = (curr + 1) % size;
////		cout << "\nCurrProbe: " << curr;
////	}
////	return curr;
////}
////
////int HashTable::linearP_steps(int curr)
////{
////	int step = findPrime(size);
////	while (arr[curr] == -1)
////	{
////		curr = (curr + step) % size;
////	}
////	return curr;
////}
////
////double HashTable::loadingFactor()
////{
////	int VAL = 0;
////	for (int i = 0; i < size; i++)
////	{
////		if (arr[i] != -1)
////		{
////			VAL++;
////		}
////	}
////
////	return (VAL);
////
////}
////
////
////HashTable::HashTable()
////{
////	size = 7;
////	int* arr = new int[size] {-1};	//-1 means cell empty
////}
////
////HashTable::HashTable(int* array, bool flag, int coll, int sizes)
////{
////	if (!flag)
////	{
////		size = sizes;
////		arr = new int[size];
////		for (int i = 0; i < size; i++)
////		{
////			arr[i] = -1;
////		}
////		for (int i = 0; i < size; i++)
////		{
////			arr[i] = array[i];
////		}
////	}
////	else
////	{
////		if (double(loadingFactor() / double(size)) > double(0.5) || true)
////		{
////			sizes *= 2;
////		}
////		size = sizes;
////		arr = new int[size];
////
////		for (int i = 0; i < size; i++)
////		{
////			arr[i] = -1;
////		}
////
////		for (int i = 0; i < size; i++)
////		{
////			int var = (array[i] % size);
////			if (arr[var] == -1)
////			{
////				arr[var] = array[i];
////			}
////			else
////			{
////				if (coll == 1)
////					arr[linearP(var)] = array[i];
////				if (coll == 2)
////					arr[linearP_steps(var)] = array[i];
////				if (coll == 3)
////					arr[Psuedo(var)] = array[i];
////				if (coll == 4)
////					arr[(hf1(array[i]) + hf2(array[i]) % size)] = array[i];
////			}
////		}
////	}
////}
////
////int main()
////{
////
////	int arr[] = { 10, 20, 30, 40, 55, 14, 7 };
////	int ss = 10;
////
////	HashTable htp(arr, 1, 1, ss);
////	htp.print();
////	cout << endl;
////
////	HashTable htq(arr, 1, 2, ss);
////	htq.print();
////	cout << endl;
////
////	HashTable htr(arr, 1, 3, ss);
////	htr.print();
////	cout << endl;
////
////	HashTable hts(arr, 1, 4, ss);
////	hts.print();
////	cout << endl;
////
////}