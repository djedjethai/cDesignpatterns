#include<string>

struct Person{
	std::string name;

	void greet();

	Person();
	~Person();

	class PersonImpl;
	PersonImpl* impl; // good place for gsl::owner<T>
};

