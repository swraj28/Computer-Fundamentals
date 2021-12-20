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


// 3.Overloading Binary Operator Using Friend Fuction:-

// C++ program to show binary operator overloading

class Distance {
public:

	// Member Object
	int feet, inch;

	// No Parameter Constructor
	Distance()
	{
		this->feet = 0;
		this->inch = 0;
	}

	// Constructor to initialize the object's value
	// Parameterized Constructor
	Distance(int f, int i)
	{
		this->feet = f;
		this->inch = i;
	}

	// Declaring friend function using friend keyword
	friend Distance operator+(Distance&, Distance&);
};

// Implementing friend function with two parameters
Distance operator+(Distance& d1, Distance& d2) // Call by reference
{
	// Create an object to return
	Distance d3;

	// Perform addition of feet and inches
	d3.feet = d1.feet + d2.feet;
	d3.inch = d1.inch + d2.inch;

	// Return the resulting object
	return d3;
}

// Driver Code
int main()
{
	// Declaring and Initializing first object
	Distance d1(8, 9);

	// Declaring and Initializing second object
	Distance d2(10, 2);

	// Declaring third object
	Distance d3;

	// Use overloaded operator
	d3 = d1 + d2;

	// Display the result
	cout << "\nTotal Feet & Inches: " << d3.feet << "'" << d3.inch;
	return 0;
}


