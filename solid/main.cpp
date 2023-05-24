#include "Openclose.h"
#include "InterfaceSegregationPrinciple.h"
#include "DependencyInversionPrinciple.h"
#include<iostream>
// #include <boost/di.hpp>
#include <boost/filesystem.hpp>

using namespace std;

int main(){

	// auto injector = di::make_injector(di::bind<ILogger>().to<ConsoleLogger>);

	// auto car = injector.create<shared_ptr<Car>>();


	Document d1 = Document("doc1");
	Document d2 = Document("doc2");
	
	vector<Document*> listDoc{&d1, &d2};	

	Printer printer;
        Scanner scanner;	

	MyPrintScan mps(printer, scanner);

	mps.print(listDoc);
	mps.scan(listDoc);


	// // this same logic works with class and with struct
	// Product apple{ "Apple", Color::Green, Size::Small };
	// Product tree{ "Tree", Color::Green, Size::Large };
	// Product house{ "House", Color::Blue, Size::Large };

	// vector<Product*> all{ &apple, &tree, &house };

	// BetterFilter<Product> bf;

	// ColorSpecification green(Color::Green);
	// SizeSpecification small(Size::Small);

	// AndSpecification<Product> greenAndSmall{green, small};

	// auto green_things = bf.filter(all, green);

	// for(auto& x : green_things)
	// 	cout << x->name << " is green" << endl;


	// auto green_and_small = bf.filter(all, greenAndSmall);

	// for(auto& x : green_and_small)
	// 	cout << x->name << " is green and small" << endl;

	return 0;

};
