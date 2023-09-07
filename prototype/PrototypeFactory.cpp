// #include<iostream>
// #include<string>
// #include<memory>
// 
// #include"PrototypeFactory.h"
// 
// // Define the static variables outside the struct
// Contact EmployeeFactory::main;
// Contact EmployeeFactory::aux;
// 
// 	
// std::unique_ptr<Contact> EmployeeFactory::NewMainOfficeEmployee(std::string name, int suite){
// 	return NewEmployee(name, suite, main);
// };
// 
// std::unique_ptr<Contact> EmployeeFactory::NewAuxOfficeEmployee(std::string name, int suite){
// 	return NewEmployee(name, suite, aux);
// };
// 
// 
// std::unique_ptr<Contact> EmployeeFactory::NewEmployee(std::string name, int suite, Contact& proto){
// 	auto result = std::make_unique<Contact>(proto);
// 	result->name = name;
// 	result->address->suite = suite;
//        	return result;	       
// };
// 
