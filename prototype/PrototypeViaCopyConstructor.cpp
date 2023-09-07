#include<iostream>
#include<string>
#include"PrototypeViaCopyConstructor.h"

// Address
// copy const
Address::Address(const std::string& street, const std::string& city, int suite):street{street}, city{city}, suite{suite}{};

std::ostream& operator<<(std::ostream& os,const Address& addr){
	os << "Live street: " << addr.street << " In the city: " << addr.city << " Suite: " << addr.suite << std::endl;
	return os;	
};


// Contact
Contact::Contact():name{"unknow"}, address{new Address{"insert street", "insert city", 0}}{};

Contact::Contact(std::string name, Address* addr):name{name}, address{addr}{};

// copy constructor
// can use address{new Address{*other.address}} bc of the copy const of Address
Contact::Contact(const Contact& other):name{other.name}, address{new Address{*other.address}}{
	// address = new Address(other.address->street, other.address->city, other.address->suite);
};
Contact::~Contact(){
	delete address;
}

std::ostream& operator<<(std::ostream& os, const Contact& ctt){
	os << "My Name is: " << ctt.name << " My address is: " << *ctt.address << std::endl;
	return os;
};

// Define the static variables outside the struct
Contact EmployeeFactory::main;
Contact EmployeeFactory::aux;

// PrototypeFactory
std::unique_ptr<Contact> EmployeeFactory::NewMainOfficeEmployee(std::string name, int suite){
	return NewEmployee(name, suite, main);
};

std::unique_ptr<Contact> EmployeeFactory::NewAuxOfficeEmployee(std::string name, int suite){
	return NewEmployee(name, suite, aux);
};


std::unique_ptr<Contact> EmployeeFactory::NewEmployee(std::string name, int suite, Contact& proto){
	auto result = std::make_unique<Contact>(proto);
	result->name = name;
	result->address->suite = suite;
       	return result;	       
};

