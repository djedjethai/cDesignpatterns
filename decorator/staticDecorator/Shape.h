#ifndef SHAPE_H
#define SHAPE_H

#include<string>
#include<iostream>
#include<sstream>
#include <cstdint>

struct Shape{
	virtual std::string str() = 0;
};

struct Circle: Shape{
	float radius;

	explicit Circle(const float r): radius{r}{};

	void resize(const float f){radius *= f;};

	std::string str() override {
		std::ostringstream oss;
		oss << "A Circle of radius: " << radius;
		return oss.str();
	};
};

struct Square: Shape{
	float side;

	explicit Square(const float s): side{s}{};

	void resize(const float f){side *= f;};

	std::string str() override {
		std::ostringstream oss;
		oss << "A Square of side: " << side;
		return oss.str();
	};
};

template<typename T> 
struct ColoredShape: T{
	std::string color;
	// Shape& shape;

	static_assert(std::is_base_of<Shape, T>::value, "Template argument must be Shape");
	// explicit ColoredShape(Shape&& sh, std::string clr): shape{sh}, color{clr}{};
	template <typename ...Args>
  	ColoredShape(const std::string& color, Args ...args)
	: T(std::forward<Args>(args)...), color{color}
    		// you cannot call base class ctor here
    		// b/c you have no idea what it is
  	{}

	std::string str() override{
		std::ostringstream oss;
		oss << T::str() << " As color: " << color;
		return oss.str();
	};	
};

template<typename T>
struct TransparentShape: T {
	uint8_t opacity;
	// Shape& shape;

	static_assert(std::is_base_of<Shape, T>::value, "Template argument must be Shape");
	// explicit TransparentShape(Shape&& sh,const uint8_t op): shape{sh}, opacity{op}{};
	template<typename ...Args>
  	TransparentShape(const uint8_t opacity, Args ...args)
    	: T(std::forward<Args>(args)...), opacity{opacity}
  	{}

	std::string str() override{
		std::ostringstream oss;
		oss << T::str() << " Opacity: " << static_cast<float>(opacity) / 255.f*100.f;
		return oss.str();
	};	
};

#endif
