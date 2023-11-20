#include<iostream>

#include"Person.h"

struct Person::PersonImpl{
	void greet(Person* p);
};


Person::Person():impl(new PersonImpl){};

Person::~Person(){ delete impl;};


void Person::greet(){
	impl->greet(this);
};

void Person::PersonImpl::greet(Person* p){
	std::cout << "Hello from: " << p->name << std::endl; 
	printf("Hello with printf: %s", p->name.c_str());
}
