// #include<iostream>
// #include<string>
// #include<sstream>
// #include<boost/serialization/access.hpp>
// #include <boost/archive/text_oarchive.hpp>
// #include <boost/archive/text_iarchive.hpp>
// #include<boost/archive/archive_exception.hpp>
// 
// 
// // Unlike other programming languages, unfortunately, C++ does not
// // offer us any free lunch when it comes to serialization. We cannot, for
// // example, take a complicated object graph and serialize the entire graph to
// // a file. Why not? Well, in other programming languages, compiled binaries
// // include not just executable code but plenty of metadata, and serialization
// // is possible through a feature called reflection—so far unavailable in C++.
// // If we want serialization then, just like with explicit copying operations,
// // we need to implement it ourselves. Luckily, rather than fiddling bits and
// // thinking up ways of serializing an std::string, we can use a ready-made
// // library called Boost.Serialization to take care of some of this for us. Here’s
// // an example of how we would add serialization support to an Address type:
// struct Address{
// 	std::string street, city;
// 	int suite;
// 
// 	// Default constructor
// 	// The Boost Serialization library requires a default constructor for the deserialization process.
//     	Address() = default;
// 
// 	Address(const std::string& street, const std::string& city, const int suite):street{street}, city{city}, suite{suite}{};
// private:
// 	friend class boost::serialization::access;
// 	template<class Ar> 
// 	void serialize(Ar& ar, const unsigned int version){
// 		ar& street;
// 	        ar& city;
// 		ar& suite;	
// 	};
// };
// 
// std::ostream& operator<<(std::ostream& os, const Address ad){
// 	os << "Address: " << ad.city << " - " << ad.street << " - " << ad.suite << std::endl;
// 	return os;
// };
// 
// 
// 
// // The structure of the preceding serialize() function is more or less the
// // same, but notice one interesting thing: instead of accessing the address as
// // ar & *address, we still serialize it as ar & address, without dereferencing
// // the pointer. Boost is smart enough to figure out what’s going on, and will
// // serialize/deserialize things just fine even if address is set to nullptr.
// struct Contact{
// 	std::string name;
// 	Address* address = nullptr;
// 	
// 	// Default constructor
// 	// The Boost Serialization library requires a default constructor for the deserialization process.
//     	Contact() = default;
// 
// 	Contact(std::string name, Address& addr):name{name} {
// 		address = new Address{addr};
// 	};
// 	Contact(std::string name, Address* addr):name{name}, address{addr}{};
// 	~Contact(){
// 		delete address;
// 	};
// private:
// 	friend class boost::serialization::access;
// 	template<class Ar> 
// 	void serialize(Ar& ar, const unsigned int version){
// 		ar& name;
// 		ar& address; // no *
// 	};
// };
// 
// std::ostream& operator<<(std::ostream& os, const Contact& c){
// 	os << c.name << " / " << *c.address << std::endl;
// 	return os;
// };
// 
// 
// 
// auto sclone = [](const Contact& c ){
// 	// 1. Serialize the contact
// 	std::ostringstream oss;
// 	boost::archive::text_oarchive oa(oss);
// 	oa << c;
// 	std::string s = oss.str();	
// 
// 	// 2. Deserialize the contact
// 	std::istringstream iss(oss.str());
// 	boost::archive::text_iarchive ia(iss);
// 	Contact result;
// 	ia >> result;
// 	return result;
// };
