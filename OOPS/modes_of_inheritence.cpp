#include<bits/stdc++.h>
using namespace std;

// C++ Implementation to show that a derived class
// doesn’t inherit access to private data members.
// However, it does inherit a full parent object
class A
{
public:
	int x;
protected:
	int y;
private:
	int z;
};

class B : public A
{
	// x is public
	// y is protected
	// z is not accessible from B
};

class C : protected A
{
	// x is protected
	// y is protected
	// z is not accessible from C
};

class D : private A // 'private' is default for classes
{

	// x is private
	// y is private
	// z is not accessible from D
};

//*****************************************************************************

// 1. Public Inheritence:-

// C++ program to demonstrate the working of public inheritance

class Base {
private:
	int pvt = 1;

protected:
	int prot = 2;

public:
	int pub = 3;

	// function to access private member
	int getPVT() {
		return pvt;
	}
};

class PublicDerived : public Base {
public:
	// function to access protected member from Base
	int getProt() {
		return prot;
	}
};

int main() {
	PublicDerived object1;
	cout << "Private = " << object1.getPVT() << endl;
	cout << "Protected = " << object1.getProt() << endl;
	cout << "Public = " << object1.pub << endl;
	return 0;
}

//*************************************************************************************

// 2.Protected Inheritence:-

// C++ program to demonstrate the working of protected inheritance

class Base {
private:
	int pvt = 1;

protected:
	int prot = 2;

public:
	int pub = 3;

	// function to access private member

	int getPVT() {
		return pvt;
	}
};

class ProtectedDerived : protected Base {
public:
	// function to access protected member from Base
	int getProt() {
		return prot;
	}

	// function to access public member from Base
	int getPub() {
		return pub;
	}
};

int main() {
	ProtectedDerived object1;
	cout << "Private cannot be accessed." << endl;
	cout << "Protected = " << object1.getProt() << endl;
	cout << "Public = " << object1.getPub() << endl;
	return 0;
}

//**********************************************************************

// 3. Private Inheritence:-

// C++ program to demonstrate the working of private inheritance

#include <iostream>
using namespace std;

class Base {
private:
	int pvt = 1;

protected:
	int prot = 2;

public:
	int pub = 3;

	// function to access private member
	int getPVT() {
		return pvt;
	}
};

class PrivateDerived : private Base {
public:
	// function to access protected member from Base
	int getProt() {
		return prot;
	}

	// function to access public member from Base.
	int getPub() {
		return pub;
	}
};

int main() {
	PrivateDerived object1;
	cout << "Private cannot be accessed." << endl;
	cout << "Protected = " << object1.getProt() << endl;
	cout << "Public = " << object1.getPub() << endl;
	return 0;
}


