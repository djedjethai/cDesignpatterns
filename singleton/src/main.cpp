#include<iostream>
#include<vector>

#include"../src/Database.h"


int main(){

	std::vector<std::string> countries{"th", "fr", "en"};

	SingletonRecordFinder srf;

	std::map<std::string, int> populations{
		{"th", 850},
        	{"fr", 400},
        	{"en", 270},
        	{"gr", 170},
        	{"us", 570},
	};

	Database::GetDatabase().setUpPopulations(populations);

	int popTot = srf.totalPopulation(countries);

	std::cout << "the total pop is: " << popTot << std::endl;
	std::cout << "the total pop2 is: " << popTot << std::endl;

	// this is the only way to call/create a Database
	 // Database::GetDatabase();
	 
	 
	 // can not as the copy construct has been delete
	 // Database db = Database::GetDatabase();


	return 0;
};
