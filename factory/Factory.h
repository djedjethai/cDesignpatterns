#include<iostream>

// Inner Factory, originaly that is used by languages like java 
// which does not have "friend" class available
// in c++ better use implementation with friend method
class Point{
private:
	Point(const float x, const float y):x{x}, y{y}{};

	class PointFactory{
	private:
		PointFactory(){};
	public:
 		static Point NewCartesien(const float x, const float y);
 		static Point NewPolar(const float r, const float theta);
	};
public:
	float x, y;
	static PointFactory Factory; // when initialyse it have acces to PointFactory
 	void print();
};



// // Factory OK
// class Point{
// public:
// 	float x, y;
// 	friend class PointFactory;
// 
// 	void print() {
// 		std::cout << "The x: " << x << " and the y: " << y << std::endl;
// 	}
// 
// private:
// 	Point(const float x, const float y):x{x}, y{y}{};
// 	
// };
// 
// // set as struct for fun, a class would have been as good
// struct PointFactory{
// 
// 	static Point NewCartesien(const float x, const float y){
// 		return Point(x, y);
// 	};
// 
// 	static Point NewPolar(const float r, const float theta){
// 		float cr = static_cast<float>(r * cos(theta));
// 		float sr = static_cast<float>(r * sin(theta));
// 		return Point(cr, sr);
// 	};	
// };

// // basic idea, make it better
// struct Point{
// protected:
// 	float x, y;
// 	Point(const float x, const float y):x{x}, y{y}{};
// public:
// 	static Point NewCartesien(const float x, const float y){
// 		return {x, y};
// 	};
// 
// 	static Point NewPolar(const float r, const float theta){
// 		float cr = static_cast<float>(r * cos(theta));
// 		float sr = static_cast<float>(r * sin(theta));
// 		return {cr, sr};
// 	};
// 
// 	void print() {
// 		std::cout << "The x: " << x << " and the y: " << y << std::endl;
// 	}
// };
