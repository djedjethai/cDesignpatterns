#include<iostream>
#include<string>

using namespace std;

class Foo {
protected:
	string name = "foo";  
public:
	Foo(){
		cout << "Contructor" << endl;
	};
	
	Foo(const string& f):name{f}{
		cout << "Contructor with param" << endl;
	};

	~Foo(){
		cout << "Destructor" << endl;
	};
	
	// copy constructor
	Foo(const Foo& other):name{other.name}{
		cout << "Copy contructor" << endl;
	};	

	void printName(){
		cout << "The name is: " << name << endl;
	};	

	void setName(string n){
		name = n;
	};
};
