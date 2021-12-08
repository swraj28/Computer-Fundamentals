#include <bits/stdc++.h>
using namespace std;


class Base
{
private:
    int data;
protected:
    int val;

public:
    Base(): val(3), data(33)
    {
        cout << "\nBase class called\n";
    }

    friend void BaseFriendFunc();

};

class Derived: public Base
{
private:
    double data1;
protected:
    char dval;
public:
    int yeppi;
    Derived(): dval('a'), data1(33.333), yeppi(0)
    {
        cout << "\nDerived class called\n";
    }

    friend void DerivedFriendfunc();
};

// friend of Base
void BaseFriendFunc()
{
    Derived dummy; // or access via Base dummy (object);

    cout << "BaseFriendFunc Base private " << dummy.data;
    cout << "\nBaseFriendFunc Base protected " << dummy.val;
    cout << "\nBaseFriendFunc Derived public " << dummy.yeppi;
    // can't access cout << "\nDerived protected " << dummy.dval;
    // can't access Derived private -> dummy.data1;
}

// friend of Derived
void DerivedFriendfunc()
{
    Derived dummy;

    cout << "\nDerivedFriendfunc Derived private " << dummy.data1;
    cout << "\nDerivedFriendfunc Derived protected " << dummy.dval;
    cout << "\nDerivedFriendfunc Base protected " << dummy.val; // since inherited in Derived and becomes protected
    // can't access Base's private dummy.data; as private data never gets inherited in Derived
}

int main() {

    BaseFriendFunc();
    DerivedFriendfunc();

    return 0;
}
