// Program 1
#include <bits/stdc++.h>
using namespace std;

class Base {
public:
    int x;
};

class Derived : Base { }; // Is equivalent to class Derived : private Base {}

int main()
{
    Derived d;
    d.x = 20; // Compiler error because inheritance is private

    cout << d.x << endl;

    return 0;
}

struct Base {
public:
    int x;
};

struct Derived : Base { }; // Is equivalent to struct Derived : public Base {}

int main()
{
    Derived d;

    d.x = 20; // Works fine because inheritance is public

    cout << d.x << endl;

    return 0;
}