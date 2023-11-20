#ifndef GRAPHICOBJECT_H
#define GRAPHICOBJECT_H

#include<iostream>
#include <memory>
#include<vector>

class GraphicObject {
public:
	virtual void draw() = 0;
};



class Objects: public GraphicObject {
public:	
	Objects(const std::string n):name{n}{};
	
	void addObject(std::shared_ptr<GraphicObject> go){
		objs.push_back(go);		
	};

	void draw(){
		std::cout << "Object: " << name << std::endl;
		for(auto o: objs){
			o->draw();
		}
	};

	void getName() {
		std::cout << "Name: " << name << std::endl;
	};

private:
	std::string name;
	std::vector<std::shared_ptr<GraphicObject>> objs;
};


class Rectangle: public GraphicObject {
	void draw(){
		std::cout << "Rectangle" << std::endl;
	};
};

class Circle: public GraphicObject {
	void draw(){
		std::cout << "Circle" << std::endl;
	};
};








#endif
