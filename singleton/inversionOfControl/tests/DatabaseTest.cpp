#include"gtest/gtest.h"
#include"iostream"
#include"../src/Database.h"
#include<boostdi/di.hpp>

namespace di = boost::di;


TEST(ConfigurableRecordFinderTests, SingletonTotalPopulationTest){
	

	DummyDatabase dummyDB;

	ConfigurableRecordFinder crf{dummyDB};
	std::vector<std::string> entries{"alpha", "beta"};
	
	int total = crf.totalPopulation(entries);

	EXPECT_EQ(11 + 22, total);
};


// good test as it does not refere directly to the Database singleton
// there is the power of the "depency inversion" via inversionOfControl
TEST(RecordFinderTests, SingletonTotalPopulationTest){

	std::cout << "tests are running" << std::endl;

	// SingletonRecordFinder srf;
	std::map<std::string, int> populations{
		{"th", 1},
        	{"fr", 2},
        	{"en", 3},
        	{"gr", 4},
        	{"us", 5},
	};


	auto injector = di::make_injector(
		di::bind<IDatabase>().to<Database>().in(di::singleton)		
	);

	auto crd = injector.create<ConfigurableRecordFinder>();

	crd.setUpPopulations(populations);

	// Database::GetDatabase().setUpPopulations(populations);
	std::vector<std::string> names{"gr", "us"};

	int tp = crd.totalPopulation(names);
	// int tp = srf.totalPopulation(names);

	EXPECT_EQ(4 + 5, tp);
}

