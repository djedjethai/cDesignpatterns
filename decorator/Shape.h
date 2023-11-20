#ifndef SHAPE_H
#define SHAPE_H

#include<string>
#include<iostream>
#include<sstream>

struct Shape{
	virtual std::string str() = 0;
};

struct Cicle: Shape{
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


#endif
