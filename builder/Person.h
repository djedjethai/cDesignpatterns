#include<iostream>

class PersonAddressBuilder;
class PersonJobBuilder;
class PersonBuilder;
class PersonBuilderBase;

class Person {
public:
	std::string streetAddress, postCode, city;
	std::string companyName, position;
	int annualIncome = 0;

	Person(){};

	// move constructor
	Person(Person&& other)
		:streetAddress{std::move(other.streetAddress)},
		postCode{std::move(other.postCode)},
		city{std::move(other.city)},
		companyName{std::move(other.companyName)},
		position{std::move(other.position)}{
			annualIncome = 0;
		};
	
	// copy constructor(the default one is deleted as a move one is explicitly declare)
	Person(const Person& other)
		:streetAddress{other.streetAddress},
		postCode{other.postCode},
		city{other.city},
		companyName{other.companyName},
		position{other.position},
		annualIncome{other.annualIncome}{};

	static PersonBuilder create();

	void getPersonalData();
};

class PersonBuilderBase{
protected:
	Person& person;
	explicit PersonBuilderBase(Person& person):person{person}{};
public:
	operator Person(){
		return person;
	};

	// builder facet
	PersonAddressBuilder lives();
	PersonJobBuilder works();
};

class PersonBuilder: public PersonBuilderBase{
	Person p; // object being built
public:
	PersonBuilder():PersonBuilderBase{p} {};	
};

class PersonAddressBuilder: public PersonBuilderBase{
	typedef PersonAddressBuilder self;
public:
	explicit PersonAddressBuilder(Person& person):PersonBuilderBase{person}{};
	self& at(std::string streetAddress);
	self& withPostcode(std::string postcode);
	self& in(std::string city);
};

class PersonJobBuilder: public PersonBuilderBase{
	typedef PersonJobBuilder self;
public:
	explicit PersonJobBuilder(Person& person):PersonBuilderBase{person}{};
	self& at(std::string company);
	self& asA(std::string position);
	self& earning(int salary);	
};

