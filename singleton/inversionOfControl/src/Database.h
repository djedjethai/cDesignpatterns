#pragma once

#include<iostream>
#include<map>
#include<memory>
#include<vector>
#include<boost/atomic.hpp>
#include<boost/thread/mutex.hpp>
#include<boost/memory_order.hpp>

class IDatabase{
public:
	// virtual ~IDatabase(){};
	virtual int getPopulation(const std::string& name) = 0;
	virtual void setUpPopulations(std::map<std::string, int>&) = 0;
};

class Database: public IDatabase{
protected:
	// Database();
	std::map<std::string, int> populations;
public:
	// static Database& GetDatabase();
	Database();

	 // Deleted copy constructor and copy assignment operator
	Database(Database const&) = delete;
	Database& operator=(Database const&) = delete;
	
	// Deleted move constructor and move assignment operator
	Database(Database&&) = delete;
	Database& operator=(Database&&) = delete;

	int getPopulation(const std::string& name) override;
	void setUpPopulations(std::map<std::string, int>& nm) override;
};

struct ConfigurableRecordFinder {
	IDatabase& db;
	explicit ConfigurableRecordFinder(IDatabase& db): db{db} {};

	int totalPopulation(std::vector<std::string> names);

	void setUpPopulations(std::map<std::string, int>& nm);
};

// struct SingletonRecordFinder{
// 	int totalPopulation(std::vector<std::string> names);
// };

class DummyDatabase: public Database{
	std::map<std::string, int>capitals;
public:
	DummyDatabase();
	int getPopulation(const std::string& name) override;
	void setUpPopulations(std::map<std::string, int>& nm) override;
};

// // As I’ve already mentioned, initialization of a singleton in the manner listed
// // previously is thread safe since C++11, meaning that if two threads were
// // to simultaneously call get(), we wouldn’t run into a situation where the
// // database would be created twice.
// // Prior to C++11, you would construct the singleton using an approach
// // called double-checked locking. A typical implementation would look like this:
// struct Database{
// 	static Database& GetDatabase();
// private:
// 	static boost::atomic<Database*> instance;
// 	static boost::mutex mtx;
// };
// 
// 
// // Definition of the static member variable outside the class
// inline Database& Database::GetDatabase(){
// 	// initialise
// 	static boost::atomic<Database*> instance = nullptr;
//      static boost::mutex mtx;
// 
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



// // same but allocate the Database on the heap
// // static Database* database = new Database();: This line creates a Database object on the heap using the new operator. The database pointer is a static variable, meaning it will persist across function calls, and its lifetime extends throughout the program execution.
// 
// // return *database;: In this line, the function is returning a reference to the Database object stored on the heap. The * operator dereferences the database pointer, giving access to the actual Database object it points to.
// 
// // So, the function get() indeed returns a reference to the Database object, not its memory address. The object itself resides on the heap, but when you return a reference to it, you are allowing direct access to that object.
// struct Database{
// protected:
// 	Database(){std::cout << "Create a database " << std::endl;};
// public:
// 	static Database& GetDatabase(){
// 		// threat save from C++ 11
// 		static Database* database = new Database();
// 		return *database;
// 	};
// 	Database(Database const&) = delete;
// 	Database(Database&&) = delete;
// 	Database& operator=(Database const&) = delete;
// 	Database& operator=(Database&&) = delete;
// };

// struct Database{
// protected:
// 	Database(){std::cout << "Create a database " << std::endl;};
// public:
// 	static Database& GetDatabase(){
// 		// threat save from C++ 11
// 		static Database database;
// 		return database;
// 	};
// 	Database(Database const&) = delete;
// 	Database(Database&&) = delete;
// 	Database& operator=(Database const&) = delete;
// 	Database& operator=(Database&&) = delete;
// };


