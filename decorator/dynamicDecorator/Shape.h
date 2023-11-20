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

struct ColoredShape: Shape{
	std::string color;
	Shape& shape;

	explicit ColoredShape(Shape&& sh, std::string clr): shape{sh}, color{clr}{};

	std::string str() override{
		std::ostringstream oss;
		oss << shape.str() << " As color: " << color;
		return oss.str();
	};	
};

struct TransparentShape: Shape {
	uint8_t opacity;
	Shape& shape;

	explicit TransparentShape(Shape&& sh,const uint8_t op): shape{sh}, opacity{op}{};

	std::string str() override{
		std::ostringstream oss;
		oss << shape.str() << " Opacity: " << static_cast<float>(opacity) / 255.f*100.f;
		return oss.str();
	};	
};

#endif
