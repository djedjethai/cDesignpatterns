#include<iostream>
#include<memory>
#include"Vector.h"



int main() {

	std::vector<std::shared_ptr<VectorObject>> vectorObjects{
		std::make_shared<VectorRectangle>(10, 10, 100, 100),
		std::make_shared<VectorRectangle>(30, 30, 60, 60),	
	};

	for(auto& obj: vectorObjects){
		for(auto& line: *obj){
			LineToPointCachingAdapter lpo{line};
			DrawPoints(lpo.begin(), lpo.end());
			
		};
	};

	return 0;
}
