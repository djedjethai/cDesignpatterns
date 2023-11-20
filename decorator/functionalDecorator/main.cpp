#include"Logger.h"

#include<iostream>


int main(){

	// Logger([](){std::cout<< "ouahhh" << std::endl;}, "theFunc")();

	// LoggerCopy([](){std::cout<< "ouahhh" << std::endl;}, "copyFunc")();

	// auto call = make_loggerCopy([](){std::cout<< "what the fuck..." << std::endl;}, "make_copyFunc");
	// call();


	auto logAdd = MakeLoggerAdd(add, "Add");
	auto result = logAdd(2, 6);

	std::cout << "The result is: " << result<< "\n";
	// res(3, 4);

	return 0;
};
