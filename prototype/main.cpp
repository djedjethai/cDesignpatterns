#include<iostream>
// #include"Prototype.h"
// #include"PrototypeViaCopyConstructor.h"
#include"PrototypeViaCopyConstructor.h"
// #include"Serialization.h"



int main() {

	auto john = EmployeeFactory::NewMainOfficeEmployee("john", 10);
	auto alice = EmployeeFactory::NewAuxOfficeEmployee("alice", 56);

	std::cout << *john;
	std::cout << *alice;

	
	// Contact worker = Contact("", new Address("kkumvit", "bkk", 34));
	// Contact paul{worker};
	// paul.name = "paul";

	// Contact aline{worker};
	// // aline.name = "aline";

	// paul.address->city = "Paris";

	// std::cout << aline;

	// std::cout << paul;


	// // prototype via serialization
	// Contact worker{"", new Address{"skumvit", "Bkk", 12}};
	// 
	// Contact john = sclone(worker);
	// john.name = "john";
	// 
	// Contact alice = sclone(worker);
	// alice.name = "alice";

	// john.address->city = "Paris";

	// std::cout << john;
	// std::cout << alice;
	
	
	// // PrototypeViaCopyConstructor 
	// Contact worker{"", new Address{"123 East Dr", "London", 0}};
	// // with PrototypeViaCopyConstructor.
	// // Contact john{worker}; // or: Contact john = worker;	
	// Contact john = worker.clone();
	// john.name = "John";
	// 
	// // with PrototypeViaCopyConstructor.
	// // Contact alice{worker};
	// Contact alice = worker.clone();
	// alice.name ="alice";

	// john.address->suite = 10;
	// john.address->city = "Bangkok";


	// std::cout << john;
	// std::cout << alice;



	// // basic prototype implementation
	// Contact worker{"", Address{"123 EstDr", "London", 22}};
	// Contact john = worker;
	// john.name = "john";
	// john.address.suite = 98;


	// std::cout << john << std::endl;

	// std::cout << "C++ version: " << __cplusplus << std::endl;

	return 0;
};
