#include "Person.h"

// Person
void Person::getPersonalData(){
std::cout << "Live: " << city << " - " << streetAddress << " - " << postCode << std::endl;
		std::cout << "Work: " << position << " - " << companyName << " - " << annualIncome << std::endl;
};

PersonBuilder Person::create(){
	return PersonBuilder();
}

// PersonBuilderBase
PersonAddressBuilder PersonBuilderBase::lives(){
	return PersonAddressBuilder(person);
};

PersonJobBuilder PersonBuilderBase::works(){
	return PersonJobBuilder(person);
};


// PersonAddressBuilder
PersonAddressBuilder::self& PersonAddressBuilder::at(std::string streetAddress){
	person.streetAddress = streetAddress;
	return *this;
};

PersonAddressBuilder::self& PersonAddressBuilder::withPostcode(std::string postcode){
	person.postCode = postcode;
	return *this;
};

PersonAddressBuilder::self& PersonAddressBuilder::in(std::string city){
	person.city = city;
	return *this;
};



// PersonJobBuilder
PersonJobBuilder::self& PersonJobBuilder::at(std::string company){
	person.companyName = company;
	return *this;
};

PersonJobBuilder::self& PersonJobBuilder::asA(std::string position){
	person.position = position;
	return *this;
};

PersonJobBuilder::self& PersonJobBuilder::earning(int salary){
	person.annualIncome = salary;
	return *this;
};
