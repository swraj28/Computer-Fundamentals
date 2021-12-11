#include <iostream>
#include<cstring>
using namespace std;

class Car {

private:
	int price;

public:

	int model_no;
	char *name;

	//Constructor
	Car() {
		//Override the default Constructor
		name = NULL;
		cout << "Making a car.." << endl;
	}

	// Constructor with parameters - Parametrised Constructor

	Car(int p, int mn, char *n) {
		price = p;
		model_no = mn;
		int l = strlen(n);
		name = new char[l + 1];
		strcpy(name, n);
	}

	//Deep Copy Constructor
	Car(Car &X) {
		// cout<<"Making a Copy of Car";
		price = X.price;
		model_no = X.model_no;
		int l = strlen(X.name);
		name = new char[l + 1];
		strcpy(name, X.name);
	}

	// User Defined Copy Assignment Operator (Deep Copy)
	void operator = (Car &X) {
		cout << "In Copy Assignment Operator" << endl;
		price = X.price;
		model_no = X.model_no;
		int l = strlen(X.name);
		name = new char[l + 1];
		strcpy(name, X.name);
	}

	void setName(char *n) {
		if (name == NULL) {
			name = new char[strlen(n) + 1];
			strcpy(name, n);
		} else {
			//Later...
			//Delete the oldname array and allocate a new one.
		}
	}

	void start() {
		cout << "Grrrr...starting the car " << name << endl;
	}

	void setPrice(int p) {
		if (p > 1000) {
			price = p;
		}
		else {
			price = 1000;
		}
	}

	int getPrice() {
		return price;
	}

	void print() {
		cout << name << endl;
		cout << model_no << endl;
		cout << price << endl;
		cout << endl;
	}
};

int main() {


	Car D(100, 200, "BMW");

	Car E(200, 400, "Audi") ;


	D = E; //Copy Assigment Operator ->Shallow Copy (If we donot overload the '=' assignment operator)

	D.name[0] = 'O';
	D.print();
	E.print();

	return 0;
}