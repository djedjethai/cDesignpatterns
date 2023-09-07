#include"gtest/gtest.h"
#include"iostream"
#include"../src/Database.h"



TEST(ConfigurableRecordFinderTests, SingletonTotalPopulationTest){
	

	DummyDatabase dummyDB;

	ConfigurableRecordFinder crf{dummyDB};
	std::vector<std::string> entries{"alpha", "beta"};
	
	int total = crf.totalPopulation(entries);

	EXPECT_EQ(11 + 22, total);
};


// bad test as it refere directly to the Database singleton
TEST(RecordFinderTests, SingletonTotalPopulationTest){

	std::cout << "tests are running" << std::endl;

	SingletonRecordFinder srf;
	std::map<std::string, int> populations{
		{"th", 850},
        	{"fr", 400},
        	{"en", 270},
        	{"gr", 170},
        	{"us", 570},
	};

	Database::GetDatabase().setUpPopulations(populations);
	std::vector<std::string> names{"gr", "us"};

	int tp = srf.totalPopulation(names);

	EXPECT_EQ(170 + 570, tp);
}

