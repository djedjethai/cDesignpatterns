#include "Shape.h"

#include<iostream>


int main(){
	// ColoredShape<TransparentShape<Square>> square{"blue"};
	// square.side = 2;
	// square.opacity = 0.5;

	// std::cout << square.str();	
	
	ColoredShape<Circle> green_circle{ "green", 5 };	
	std::cout << green_circle.str() << std::endl;	

	TransparentShape<Square> red{ 6, 34 };
	std::cout << red.str() << std::endl;	

	return 0;
}
