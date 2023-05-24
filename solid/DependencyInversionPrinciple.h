#include<iostream>
#include<ostream>
#include<memory>

using namespace std;

struct ILogger {
	virtual ~ILogger(){};
	virtual void Log(const string& s) = 0;
};

struct Engine{
	float volume = 5;
	int horse_power = 400;

	friend ostream& operator<<(ostream& os, const Engine& obj){
		return os << "Volume: " << obj.volume << " - horse_power: " << obj.horse_power <<endl;
	};
};

struct ConsoleLogger: ILogger {
	
	ConsoleLogger(){};

	void Log(const string& s) override {
		cout << "LOG: " << s.c_str() << endl;
	};
};

struct Car{
	unique_ptr<Engine> engine;
	shared_ptr<ILogger> logger;

	Car(unique_ptr<Engine> engine, const shared_ptr<ILogger>& logger):engine{std::move(engine)}, logger{logger} {
		logger->Log("Making a car"); 
	};

	friend ostream& operator<<(ostream& os, const Car& obj){
		return os << "Car with engine: " << *obj.engine << endl;
	};
};


