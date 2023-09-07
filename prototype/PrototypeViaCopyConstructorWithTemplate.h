// #include<iostream>
// #include<string>
// 
// template<typename T> 
// struct Cloneable {
// 	virtual T clone() = 0;
// };
// 
// class Address {
// public:
// 	std::string street, city;
// 	int suite;
// 	Address(const std::string& street, const std::string& city, int suite);
// 	~Address(){};
// };
// 
// class Contact: public Cloneable<Contact> {
// public:
// 	std::string name;
// 	Address* address;
// 	Contact(std::string name, Address* addr);
// 	Contact(const Contact& other);
// 	Contact clone() override {
// 		return Contact(*this);		
// 	};
// 	~Contact(){
// 		delete address;
// 	};
// };
// 
// 
// // copy const
// Address::Address(const std::string& street, const std::string& city, int suite):street{street}, city{city}, suite{suite}{};
// 
// std::ostream& operator<<(std::ostream& os,const Address& addr){
// 	os << "Live street: " << addr.street << " In the city: " << addr.city << " Suite: " << addr.suite << std::endl;
// 	return os;	
// };
// 
// 
// Contact::Contact(std::string name, Address* addr):name{name}, address{addr}{};
// 
// // copy constructor
// // can use address{new Address{*other.address}} bc of the copy const of Address
// Contact::Contact(const Contact& other):name{other.name}, address{new Address{*other.address}}{
// 	// address = new Address(other.address->street, other.address->city, other.address->suite);
// };
// 
// std::ostream& operator<<(std::ostream& os, const Contact ctt){
// 	os << "My Name is: " << ctt.name << " My address is: " << *ctt.address << std::endl;
// 	return os;
// };
// 
// 
