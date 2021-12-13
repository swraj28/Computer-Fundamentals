// CPP program to illustrate
// Private Destructor
#include <iostream>
using namespace std;

class Test {
private:
	~Test() {}
};
int main() {
}

//The above program compiles and runs fine. Hence, we can say that : It is not compiler error to create private destructors.

//***********************************************************

class Test {
private:
	~Test() {}
};
int main()
{
	Test t;
}

//The above program fails in compilation. The compiler notices that the local variable ‘t’ cannot be destructed because the destructor is private.

//***********************************************************

class Test {
private:
	~Test() {}
};
int main()
{
	Test* t;
}

//The above program works fine. There is no object being constructed, the program just creates a pointer of type “Test *”, so nothing is destructed.

//******************************************************************

class Test {
private:
	~Test() {}
};
int main()
{
	Test* t = new Test;
}

// The above program also works fine. When something is created using dynamic memory allocation,
//it is programmer’s responsibility to delete it. So compiler doesn’t bother.

//**************************************************************************

class Test {
private:
	~Test() {}
};
int main()
{
	Test* t = new Test;
	delete t;
}

// This will work fine but someshow if we forget to use delete operator then the dynamic object will not get deleted and
// memory leak may happen.

// The correct practice has been written below.

//**********************************************************************

// A class with private destructor
class Test {
private:
	~Test() {}
public:
	friend void destructTest(Test*);
};

// Only this function can destruct objects of Test

void destructTest(Test* ptr) {
	delete ptr;
	cout << "Destructor Called" << '\n';
}

int main() {

	// create an object
	Test* ptr = new Test;

	// destruct the object
	destructTest(ptr);

	return 0;
}
