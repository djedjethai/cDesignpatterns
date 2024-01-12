#include<iostream>

#include"FormattedText.h"



int main(){
	BetterFormattedText bfg("This is brave new world");

	bfg.get_range(4, 10).capitalize = true;

	std::cout << bfg << std::endl;


	return 0;
}
