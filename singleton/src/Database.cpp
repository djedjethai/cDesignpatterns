#include"Database.h"

Database::Database(){
	std::cout << "Create a database" << std::endl;
};

Database& Database::GetDatabase(){
	static Database database;
	return database;
};

int Database::getPopulation(const std::string& name) {
	return populations[name];
};

void Database::setUpPopulations(std::map<std::string, int>& nm){
	populations = nm;
}

int SingletonRecordFinder::totalPopulation(std::vector<std::string> names){
	int pop{0};

	for(auto& name:names){
		pop += Database::GetDatabase().getPopulation(name);
	};
	return pop;
};

int ConfigurableRecordFinder::totalPopulation(std::vector<std::string> names) {
	int tot{0};
	for(auto n:names){
		tot += db.getPopulation(n);
	};
	return tot;
};

DummyDatabase::DummyDatabase(){
	capitals["alpha"] = 11;
	capitals["beta"] = 22;
	capitals["gamma"] = 33;
};

int DummyDatabase::getPopulation(const std::string& name) {
	return capitals[name];
}


// #include"Database.h"
// // #include<boost/memory_order.hpp>
// 
// 
// Database& Database::GetDatabase(){
// 	Database* db = instance.load(boost::memory_order_consume);
// 	if(!db){
// 		boost::mutex::scoped_lock lock(mtx);
// 		db = instance.load(boost::memory_order_consume);
// 		if(!db){
// 			std::cout << "Create a static Database object" << std::endl;
// 			db = new Database();
// 			instance.store(db, boost::memory_order_release);
// 		};
// 	};
// 	return *db;
// };



