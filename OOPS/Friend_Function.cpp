#include <iostream>
using namespace std;

class A {
private:
	int a;

public:
	A() { a = 0; }

	friend class B; // Friend Class
};

class B {
private:
	int b;

public:
	void showA(A& x)
	{
		// Since B is friend of A, it can access
		// private members of A
		std::cout << "A::a=" << x.a;
	}
};

int main()
{
	A a;
	B b;
	b.showA(a);
	return 0;
}

//***********************************************************************************

#include <iostream>
using namespace std;

class B;

class A {
public:
	void showB(B&);
};

class B {
private:
	int b;

public:
	B() { b = 0; }
	friend void A::showB(B& x); // Friend function
};

void A::showB(B& x)
{
	// Since showB() is friend of B, it can
	// access private members of B
	std::cout << "B::b = " << x.b;
}

int main()
{
	A a;
	B x;
	a.showB(x);
	return 0;
}
