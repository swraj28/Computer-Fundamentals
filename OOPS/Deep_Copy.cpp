#include <iostream>
using namespace std;
class Demo
{
public:
    int a;
    int b;
    int *p;

    Demo() {
        p = new int;
    }

    Demo(Demo &d) { // User Defined Copy Constructor
        a = d.a;
        b = d.b;
        p = new int;
        *p = *(d.p);
    }

    void setdata(int x, int y, int z) {
        a = x;
        b = y;
        *p = z;
    }

    void showdata() {
        std::cout << "value of a is : " << a << std::endl;
        std::cout << "value of b is : " << b << std::endl;
        std::cout << "value of *p is : " << *p << std::endl;
    }
};
int main() {

    Demo d1;
    d1.setdata(4, 5, 7);
    Demo d2 = d1;
    d2.showdata();
    return 0;
}


//*****************************************************************************************************

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
    Car E(D); // Copy Constructor

    E.name[0] = 'G';
    D.print();
    E.print();

    return 0;
}
