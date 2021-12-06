#include<iostream>
using namespace std;

class Circle {

// private data member
private:
	double radius = 1.0;

public:
	// public member function
	double compute_area() {

		// member function can access private
		// data member radius
		return 3.14 * radius * radius;

	}
};

// main function
int main() {

	// creating object of the class

	Circle obj;

	// trying to access private data member
	// directly outside the class

	// obj.radius = 1.5; // this will give compile error

	cout << "Area is:" << obj.compute_area();

	return 0;
}


// Access the private data members of a class indirectly using the
// public member functions of the class.

#include<iostream>
using namespace std;

class Circle {
private:
	// private data member
	double radius;

public:
	// public member function
	double compute_area(double r) {

		// member function can access private
		// data member radius
		radius = r;
		double area = 3.14 * radius * radius;
		cout << "Radius is:" << radius << endl;
		cout << "Area is: " << area;
	}
};

// main function
int main() {

	// creating object of the class
	Circle obj;
	// trying to access private data member
	// directly outside the class

	obj.compute_area(1.5);

	return 0;
}