#include<iostream>
#include<string>
#include<sstream>
#include <iomanip>

#include"User.h"

boost::bimap<key, std::string> User::names;
key User::seed = 0;

int main(){

	while (true) {
        	std::string fullname;
        	std::cout << "Enter a name: ";
        	std::getline(std::cin, fullname);

        	if (fullname == "exit") {
        		break; // Exit the loop if "exit" is entered
        	}

		std::istringstream iss(fullname);
		std::string firstname, lastname;

		iss >> firstname >> lastname;
		
		// using User implementation
		User user(firstname, lastname);
		std::cout << user;

		// using User2 implementation
		User2 john_doe{ "John", "Doe" };
		User2 jane_doe{ "Jane", "Doe" };
		std::cout << std::boolalpha <<(&jane_doe.last_name.get() == &john_doe.last_name.get());
 	} 

	return 0;
}
