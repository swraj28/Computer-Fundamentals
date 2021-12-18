#include<bits/stdc++.h>
using namespace std;

//1 . Overloading Of Unary Operator:-

class Distance {
public:

	// Member Object
	int feet, inch;

	// Constructor to initialize the object's value
	Distance(int f, int i) {
		this->feet = f;
		this->inch = i;
	}

	// Overloading(-) operator to perform decrement
	// operation of Distance object
	void operator -() {
		feet--;
		inch--;
		cout << "\nFeet & Inches(Decrement): " << feet << "'" << inch;
	}
};

// Driver Code

int main() {
	// Declare and Initialize the constructor
	Distance d1(8, 9);

	// Use (-) unary operator by single operand
	-d1;
	return 0;
}

// 2. Overloading Of Binary Operator:-

class Complex {
private:
	int real, imag;
public:
	Complex(int r = 0, int i = 0) {real = r; imag = i;}

	// This is automatically called when '+' is used with
	// between two Complex objects
	Complex operator + (Complex const &obj) {
		Complex res;
		res.real = real + obj.real;
		res.imag = imag + obj.imag;
		return res;
	}
	void print() { cout << real << " + i" << imag << endl; }
};

int main()
{
	Complex c1(10, 5), c2(2, 4);
	Complex c3 = c1 + c2; // An example call to "operator+"
	c3.print();
}

