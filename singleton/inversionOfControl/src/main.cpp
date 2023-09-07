#include<iostream>
#include<vector>
#include<memory>
#include<boostdi/di.hpp>
#include"Database.h"

namespace di = boost::di;

int main(){
	// SingletonRecordFinder srf;

	std::map<std::string, int> populations{
		{"th", 850},
        	{"fr", 400},
        	{"en", 270},
        	{"gr", 170},
        	{"us", 570},
	};

	std::vector<std::string> countries{"th", "fr", "en"};

	auto injector = di::make_injector(
		// di::bind<IDatabase>().to<Database>()
		di::bind<IDatabase>().to<Database>().in(di::singleton)
	);

	auto crd = injector.create<ConfigurableRecordFinder>();

	crd.setUpPopulations(populations);

	int popTot = crd.totalPopulation(countries);

	// Database::GetDatabase().setUpPopulations(populations);

	// int popTot = srf.totalPopulation(countries);

	std::cout << "the total pop is: " << popTot << std::endl;

	// this is the only way to call/create a Database
	 // Database::GetDatabase();
	 
	 
	 // can not as the copy construct has been delete
	 // Database db = Database::GetDatabase();


	return 0;
};
