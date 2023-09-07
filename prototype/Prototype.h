// #include<iostream>
// #include<ostream>
// #include<string>
// 
// 
// // basic approach
// struct Address;
// struct Contact;
// 
// 
// 
// struct Address{
// 	std::string street, city;
//        	int suite;	
// };
// 
// struct Contact {
// 	std::string name;
// 	Address address;
// };
// 
// std::ostream& operator<<(std::ostream& os,const Address& addr){
// 	os << "Live street: " << addr.street << " In the city: " << addr.city << " Suite: " << addr.suite << std::endl;
// 	return os;	
// };
// 
// std::ostream& operator<<(std::ostream& os, const Contact ctt){
// 	os << "My Name is: " << ctt.name << " My address is: " << ctt.address << std::endl;
// 	return os;
// };
// 
// 
// 
// 
// 
