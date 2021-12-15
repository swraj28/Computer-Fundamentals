#include<bits/stdc++.h>
using namespace std;

// 1. Static Variable In a class:-

/*
Static variables when used inside function are initialized only once, and then they hold there value even through function calls.
These static variables are stored on static storage area , not in stack
*/

void counter()
{
	static int count = 0;
	cout << count++;
}

int main()
{
	for (int i = 0; i < 5; i++)
	{
		counter();
	}
}

// Output:- 0,1,2,3,4

// ---> Non Static Variable in a class:-

void counter()
{
	int count = 0;
	cout << count++;
}

int main()
{
	for (int i = 0; i < 5; i++)
	{
		counter();
	}
}

// Output:- 0 0 0 0 0

/*
If we do not use static keyword, the variable count, is reinitialized everytime when counter() function is called,
and gets destroyed each time when counter() functions ends.
But, if we make it static, once initialized count will have a scope till the end of main() function and it will carry its value through function calls too.
*/

//**************************************************************************************************

// 2. Static Class Object:-

// Objects declared static are allocated storage in static storage area, and have scope till the end of program.

/*
Static objects are also initialized using constructors like other normal objects.
Assignment to zero, on using static keyword is only for primitive datatypes (int,float,char,double,bool), not for user defined datatypes.
*/

class Abc
{
	int i;
public:
	Abc()
	{
		i = 0;
		cout << "constructor";
	}
	~Abc()
	{
		cout << "destructor";
	}
};

void f()
{
	static Abc obj;
}

int main()
{
	int x = 0;
	if (x == 0)
	{
		f();
	}
	cout << "END";
}

// output:- constructor END destructor

//The static object, which has scope till the program's lifetime, hence destructor for this object was called when main() function exits.

//******************************************************************************************************************

// 3. Static Data Member in a class:-

class X
{
public:
	static int i;
	X()
	{
		// construtor
	};
};

int X::i = 1;

int main()
{
	X obj;
	cout << obj.i;   // prints value of i
}

//*****************************************************************************************************************************

// 4. Static Member Fuction:-

class X
{
public:
	static void f()
	{
		// statement
	}
};

int main()
{
	X::f();   // calling member function directly with class name
}
