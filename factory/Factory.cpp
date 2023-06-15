#include<iostream>
#include<cmath>
#include"Factory.h"

Point Point::PointFactory::NewCartesien(const float x, const float y){
	return {x, y};
};

Point Point::PointFactory::NewPolar(const float r, const float theta){
	float cr = static_cast<float>(r * cos(theta));
 	float sr = static_cast<float>(r * sin(theta));
 	return {cr, sr};
};

void Point::print(){
	std::cout << "The x: " << x << " and the y: " << y << std::endl;
};
