#include<iostream>
using namespace std;
int mul(int, int);
float mul(float, int);


int mul(int a, int b)
{
    return a * b;
}
float mul(float x, int y)
{
    return x * y;
}
int main()
{
    int r1 = mul(6, 7);
    float r2 = mul(float(0.2), 3);
    std::cout << "r1 is : " << r1 << std::endl;
    std::cout << "r2 is : "  << r2 << std::endl;
    return 0;
}

// Ambiguities In function Overloading:-

//*****************************************************************
// 1. Type Conversion:-

void fun(int);
void fun(float);
void fun(int i)
{
    std::cout << "Value of i is : " << i << std::endl;
}
void fun(float j)
{
    std::cout << "Value of j is : " << j << std::endl;
}

int main()
{
    fun(12);
    fun(1.2);
    return 0;
}

/*
The fun(1.2) calls the second function according to our prediction.
But, this does not refer to any function as in C++, all the floating point constants are treated as double not as a float.
If we replace float to double, the program works. Therefore, this is a type conversion from float to double.
*/
//************************************************************************

// 2. Function with default argument:-

void fun(int);
void fun(int, int);
void fun(int i)
{
    std::cout << "Value of i is : " << i << std::endl;
}
void fun(int a, int b = 9)
{
    std::cout << "Value of a is : " << a << std::endl;
    std::cout << "Value of b is : " << b << std::endl;
}
int main()
{
    fun(12);

    return 0;
}

/*
the compiler could not be able to select among fun(int i) and fun(int a,int b=9).
*/

//****************************************************************************

// 3. Fuction with pass by reference.

void fun(int);
void fun(int &);
int main()
{
    int a = 10;
    fun(a); // error, which f()?
    return 0;
}
void fun(int x)
{
    std::cout << "Value of x is : " << x << std::endl;
}
void fun(int &b)
{
    std::cout << "Value of b is : " << b << std::endl;
}

/*
the compiler does not know which function is needed by the user as there is no syntactical difference between the fun(int) and fun(int &).
*/

