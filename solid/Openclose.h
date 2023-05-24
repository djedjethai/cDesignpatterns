#include <vector>
#include <string>

using namespace std;

enum class Color { Red, Green, Blue };
enum class Size { Small, Medium, Large };


struct Product{
	string name;
	Color color;
	Size size;
};

template<typename T> 
struct Specification{
	virtual bool is_satisfied(T* item) = 0;
};

template <typename T> 
struct Filter{
	virtual vector<Product*> filter(vector<T*> items, Specification<T>& spec) = 0;
};

// class implementation
template <typename T> 
class AndSpecification : public Specification<T> {
public:
	Specification<T>& first;
	Specification<T>& second;

	AndSpecification(Specification<T>& first, Specification<T>& second):first{first}, second{second}{};

	bool is_satisfied(T* item) override {
		return first.is_satisfied(item) && second.is_satisfied(item);
	};
};

template <typename T>
class BetterFilter : public Filter<Product> {
public:	
	virtual vector<Product*> filter(vector<Product*> items, Specification<Product>& spec) override{
		vector<Product*> result;
		for(auto& i:items){
			if(spec.is_satisfied(i))
				result.push_back(i);
		};
		return result;
	};
};

class ColorSpecification : public Specification<Product> {
public:
	Color color;

	explicit ColorSpecification(const Color color) : color{color}{}

	bool is_satisfied(Product* item) override { 
		return item->color == color;
	};
};

class SizeSpecification : public Specification<Product> {
public:
	Size size;

	explicit SizeSpecification(const Size size) : size{size}{}

	bool is_satisfied(Product* item) override { 
		return item->size == size;
	};
};



// struct implementation 
// template <typename T>
// struct AndSpecification : Specification<T> {
// 	Specification<T>& first;
// 	Specification<T>& second;
// 
// 	AndSpecification(Specification<T>& first, Specification<T>& second):first{first}, second{second}{};
// 
// 	bool is_satisfied(T* item) override {
// 		return first.is_satisfied(item) && second.is_satisfied(item);
// 	};
// };
// 
// template <typename T>
// struct BetterFilter: Filter<Product> {
// 	vector<Product*> filter(vector<Product*> items, Specification<Product>& spec) override {
// 		vector<Product*> result;
// 		for(auto& p:items){
// 			if(spec.is_satisfied(p)){
// 				result.push_back(p);
// 			};
// 		};
// 		return result;
// 		
// 	};	
// };
// 
// struct ColorSpecification : Specification<Product>{
// 	Color color;
// 	
// 	explicit ColorSpecification(const Color color) : color{color} {};
// 	
// 	bool is_satisfied(Product* item) override {
// 		return item->color == color;
// 	};	
// };
// 
// struct SizeSpecification : Specification<Product>{
// 	Size size;
// 
// 	explicit SizeSpecification(const Size size): size{size} {};
// 
// 	bool is_satisfied(Product* item) override {
// 		return item->size == size;
// 	};
// };


