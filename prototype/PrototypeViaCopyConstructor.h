#ifndef PROTOTYPE_VIA_COPY_CONSTRUCTOR_H
#define PROTOTYPE_VIA_COPY_CONSTRUCTOR_H

#include<iostream>
#include<string>
#include<memory>

class Address {
public:
	std::string street, city;
	int suite;
	Address(const std::string& street, const std::string& city, int suite);
	~Address(){};
};
std::ostream& operator<<(std::ostream& os, const Address& addr);

class Contact {
private:
	// by making the EmployeeFactory fiend, only him have access to Contact()
	// doing like so no-one else can call this constructor
	friend class EmployeeFactory;
	Contact();
public:
	std::string name;
	Address* address;
	// default contruct for prototypeFactory
	Contact(std::string name, Address* addr);
	Contact(const Contact& other);
	~Contact();
};
std::ostream& operator<<(std::ostream& os, const Contact& ctt);

// Why use a factory? Well, consider the situation where we copy a
// prototype and then forget to customize it. It will have some blank strings and
// zeros where actual data should be. Using the approaches from our discussion
// of Factories, we can, for example, make all non–fully initializing constructors
// private, declare EmployeeFactory as a friend class, and there you go—now
// the client has no way of getting a partially constructed Contact.
struct EmployeeFactory{
	static Contact main;
	static Contact aux;

	static std::unique_ptr<Contact> NewMainOfficeEmployee(std::string name, int suite);
	static std::unique_ptr<Contact> NewAuxOfficeEmployee(std::string name, int suite);

private:
	static std::unique_ptr<Contact> NewEmployee(std::string name, int suite, Contact& proto);};

#endif // PROTOTYPE_VIA_COPY_CONSTRUCTOR_H
