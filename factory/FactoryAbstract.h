#include<iostream>
#include<memory>
#include<map>
#include<functional>

// abstract factory
struct HotDrink {
	virtual void prepare(int volume) = 0;
	virtual void serve()= 0;
};

struct Tea : HotDrink {
	void prepare(int volume) override {
		std::cout << "Take tea bag, boil water, pour: " << volume << std::endl;
	};

	void serve() override {
		std::cout << "See there is your Tea" << std::endl;
	};
};

struct Coffee : HotDrink {
	void prepare(int volume) override {
		std::cout << "Take coffee bag, boil water, pour: " << volume << std::endl;
	};

	void serve() override {
		std::cout << "See there is your Coffee" << std::endl;
	};
};

struct HotDrinkFactory {
	virtual std::unique_ptr<HotDrink> make() const = 0; 
};

struct TeaFactory : HotDrinkFactory {
	std::unique_ptr<HotDrink> make() const override {
		return std::make_unique<Tea>();
	};
};

struct CoffeeFactory : HotDrinkFactory {
	std::unique_ptr<HotDrink> make() const override {
		return std::make_unique<Coffee>();
	};
};

class DrinkFactory {
	std::map<std::string, std::unique_ptr<HotDrinkFactory>> hotFactories;
public:
	DrinkFactory(){
		hotFactories["tea"] = std::make_unique<TeaFactory>();
		hotFactories["coffee"] = std::make_unique<CoffeeFactory>();
	};

	std::unique_ptr<HotDrink> makeDrink(const std::string& name){
		auto drink = hotFactories[name]->make();
		drink->prepare(200);
		return drink;
	};
};

// functional factory
class DrinkWithVolumeFactory {
	std::map<std::string, std::function<std::unique_ptr<HotDrink>()>> factories;
public:
	DrinkWithVolumeFactory(){
		factories["tea"] = []{
			auto tea = std::make_unique<Tea>();
			tea->prepare(200);
			return tea;
		};
		factories["coffee"] = []{
			auto coffee = std::make_unique<Coffee>();
			coffee->prepare(200);
			return coffee;
		};
	};

	std::unique_ptr<HotDrink> makeDrink(const std::string& name);;
};

inline std::unique_ptr<HotDrink> DrinkWithVolumeFactory::makeDrink(const std::string& name){
	return factories[name]();	
};
