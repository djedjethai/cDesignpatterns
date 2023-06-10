#include<iostream>
#include<memory>
#include"Foo.h"

unique_ptr<Foo> returnFooUniquePtr(){
	return make_unique<Foo>("unique");
};

shared_ptr<Foo> returnFooSharePtr(){
	shared_ptr<Foo> f = make_shared<Foo>("share");
	return f;
};

Foo* returnFooPtr(){
	Foo* f = new Foo();
	return f;
}

Foo returnFoo(){
	Foo f;
	return f; 
};

// return a structure from a func
int main() {
	// // use a pointer approach
	// Foo* f = returnFooPtr();
	// f->printName();
	// delete f;

	// copy should call the copy constructor but does not ?? 
	Foo original("origin");
	Foo copy = original; // copy constructor
	original.printName();
	copy.printName();
	
	// // shared ptr
	// shared_ptr<Foo>t = returnFooSharePtr();
	// t->printName();
	// shared_ptr<Foo> s =  t; // in this case it does not use the copy construct
	// s->printName();
	// t->setName("robert");
	// s->printName(); // print robert, point to the same resistor
	
	// unique_ptr<Foo> f = returnFooUniquePtr();
        // unique_ptr<Foo> s = f; // can ot as it's a unique ptr	
        //  unique_ptr<Foo> s(f); // can ot as it's a unique ptr	

	return 0;
};
