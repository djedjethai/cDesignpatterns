#include<iostream>
#include"Factory.h"
#include"FactoryAbstract.h"

int main(){

	// functional factory
	auto drk = DrinkWithVolumeFactory().makeDrink("coffee");
	drk->serve();

	// // abstract factory
	// DrinkFactory df;
	// auto coffee = df.makeDrink("coffee");
	// coffee->serve();


	// Point c = Point::Factory.NewCartesien(2, 3);
	// c.print();

	// auto p = Point::Factory.NewPolar(2, 5);
	// p.print();

	// Point c = PointFactory::NewCartesien(2, 3);
	// c.print();

	// auto p = PointFactory::NewPolar(2, 5);
	// p.print();
}
