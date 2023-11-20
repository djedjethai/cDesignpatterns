#include "Shape.h"

#include<iostream>


int main(){
	// // ok
	// Circle circle(23);
	// Square square(45.6);

	// ColoredShape redCircle(circle, "red");
	// std::cout << redCircle.str() << std::endl;;

	// TransparentShape tShape(redCircle, 0.7);
	// std::cout << tShape.str() << std::endl;
	// // end of ok
	
	// or
	// TODO debug that !!!!!
	// in this case the code need to be adapt as the args are rvalues, like so
	// TransparentShape(Shape&& sh,const uint8_t op)
	TransparentShape myCircle{
		ColoredShape{
			Circle{23}, "green"
		}, 64
	};
	std::cout << myCircle.str();

	return 0;
}
