#include<iostream>
#include"SimpleBuilder.h"
#include"Person.h"

int main(){


	Person pp = Person::create().lives().at("sukhumvit").in("bkk").works().asA("dentist").at("company").earning(345);

	pp.getPersonalData();


	// Tag tag("body", "");
    	// tag.elements.emplace_back(P("what"));
    	// tag.elements.back().elements.emplace_back(IMG("http://pokemon.com/pikachu.png"));

    	// std::cout << tag << std::endl;


	// HtmlElement he = HtmlElement("<p>", "see the try");
	// he.str();
	
	// Builder blder("body");

	// simple builder
	// blder.addChild("p", "first element");
	// blder.addChild("p", "second element");

	// fluent builder
	// blder.addChild("p", "first element").addChild("p", "second element");
	
	// Commuting intent(without the operator on the builder)
	// auto builder = HtmlElement::build("body");
	// builder->addChild("p", "first element");
	// builder->str();

	// Commuting intent returning an HtmlElement
	// HtmlElement he = HtmlElement::build("body").addChild("p", "first element");
	// he.str(0);



	return 0;
}
