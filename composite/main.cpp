#include"./Creature.h"
#include"./GraphicObject.h"

#include <algorithm>
#include <any>
#include<memory>

int main(){

	Objects o("Group1");
	std::shared_ptr<Rectangle> r = std::make_shared<Rectangle>();
	std::shared_ptr<Rectangle> r1 = std::make_shared<Rectangle>();
	o.addObject(r);
	o.addObject(r1);

	Objects s("Sub");
	std::shared_ptr<Circle> c1 = std::make_shared<Circle>();
	std::shared_ptr<Circle> c2 = std::make_shared<Circle>();
	s.addObject(c1);
	s.addObject(c2);
	
	std::shared_ptr<Objects> so = std::make_shared<Objects>(s);
	o.addObject(so);
	
	o.draw();

	return 0;
};
