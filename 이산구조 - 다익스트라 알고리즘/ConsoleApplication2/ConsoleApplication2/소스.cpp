#include <iostream>
using namespace std;

class parent{
public:
	void prn();
};

void parent :: prn(){
	cout << "PM" << endl;
}

class child:public parent{
public:
	void prn();
};

void child::prn()
{
	cout << "CM" << endl;
}

void main()
{
	parent p;
	child c;
	parent *pptr = &c;
	child *cptr = (child*)pptr;
	cptr->prn();
}