#include "iostream"


template<typename T>
struct Property{
	T value;
	Property(const T initial_value){
		*this = initial_value;
	};
	operator T(){
		// perform some getter action
		return value;
	}

	T operator = (const T& new_value){
		// perform sone setter action
		return value = new_value;
	}
};

struct Creature{
	Property<int> strenght{10};
	Property<int> agility{5};
};

int main(){

	Creature creature;

	creature.agility = 20;
	auto x = creature.strenght;

	std::cout<< "euhhhh: " << x << std::endl;


	return 0;
}
