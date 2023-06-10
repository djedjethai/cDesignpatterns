#include<iostream>
#include<vector>
#include<sstream>
#include<memory>
#include<utility>

using namespace std;

struct Builder;


// It is simply an alternative means of object construction.
struct Tag{
	string name;
	string text;
	vector<Tag> elements;
	vector<std::pair<string, string>> attributes;
	// const size_t indentSize = 2;

	friend std::ostream& operator<<(std::ostream& os, const Tag& tag) {
  		os << "<" << tag.name << ">";

  		if (!tag.text.empty()) {
  		  os << tag.text;
  		}

  		for (const auto& element : tag.elements) {
  		  os << element;
  		}

  		os << "</" << tag.name << ">";

  		return os;
	}

	
	// doing like so the HtmlElement() can only be call from Builder(as builder is friend)
	// protected:
	Tag(const string& n, const string& t) :name{n}, text{t}{};
	Tag(const string& n, const vector<Tag>& children) :name{n}, elements{children}{};

};

struct P : Tag {
	explicit P(const string& text):Tag{"p", text}{};

	P(std::initializer_list<Tag> children):Tag{"p", children}{};
};

struct IMG : Tag {
	explicit IMG(const string& url):Tag{"img",""}{
		attributes.emplace_back(std::make_pair("src", url));
	};
};

// // Fluent interface builder
// struct Builder{
// 
// 	// It allows the Builder class to be implicitly converted to an HtmlElement object when needed.
// 	operator HtmlElement() const {
// 		return elmBase;
// 	}
// 
// 	HtmlElement elmBase;
// 
// 	Builder(string elmBaseName) {elmBase.name = elmBaseName; };
// 	Builder(string elmBaseName, string elmBaseText) {
// 		elmBase.name = elmBaseName; 
// 		elmBase.text = elmBaseText; 
// 	};
// 
// 	Builder& addChild(string childName, string childText){
// 		HtmlElement elm(childName, childText);
// 		elmBase.elements.emplace_back(elm); 
// 		return *this;
// 	};
// 
// 	void str(){
// 		elmBase.str(0);
// 	}
// 
// };
// 
// 
// // for the static HtmlElement::build() this method need to be declare, that we do
// // that is needed only for Commuting intent returning an HtmlElement
// Builder HtmlElement::build(const string& elementBase) {
//     return Builder(elementBase);
// }


// struct Builder;
// 
// 
// // Communicating intent, force a user to use our builder class
// struct HtmlElement{
// 	string name;
// 	string text;
// 	vector<HtmlElement> elements;
// 	const size_t indentSize = 2;
// 
// 	friend struct Builder;
// 
// 	// For Commuting intent returning an HtmlElement
// 	static Builder build(const string& elementBase);
// 
// 	// NOTE is going for Commuting intent
// 	// static unique_ptr<Builder> build(const string& elementBase){
// 	// 	return make_unique<Builder>(elementBase);
// 	// };
// 
// 	void str(int indent = 0) const {
// 		if(name.length() > 0){
// 			ostringstream oss;
// 			for (int i = 0; i < indent; ++i)
//    				 oss << ' ';  // Append a space to the stream for each iteration
// 			oss << "<" << name << ">";
// 			oss << text;
// 			oss << "<" << name << ">";
// 			oss << '\n';
// 			printf("%s", oss.str().c_str());
// 		}	
// 
// 		for(auto elm: elements){
// 			elm.str(indent + 1);
// 		};
// 	};
// 
// 	// doing like so the HtmlElement() can only be call from Builder(as builder is friend)
// 	protected:
// 	HtmlElement(){};
// 	HtmlElement(const string& n, const string& t) :name{n}, text{t}{};
// 
// };
// 
// // Fluent interface builder
// struct Builder{
// 
// 	// It allows the Builder class to be implicitly converted to an HtmlElement object when needed.
// 	operator HtmlElement() const {
// 		return elmBase;
// 	}
// 
// 	HtmlElement elmBase;
// 
// 	Builder(string elmBaseName) {elmBase.name = elmBaseName; };
// 	Builder(string elmBaseName, string elmBaseText) {
// 		elmBase.name = elmBaseName; 
// 		elmBase.text = elmBaseText; 
// 	};
// 
// 	Builder& addChild(string childName, string childText){
// 		HtmlElement elm(childName, childText);
// 		elmBase.elements.emplace_back(elm); 
// 		return *this;
// 	};
// 
// 	void str(){
// 		elmBase.str(0);
// 	}
// 
// };
// 
// 
// // for the static HtmlElement::build() this method need to be declare, that we do
// // that is needed only for Commuting intent returning an HtmlElement
// Builder HtmlElement::build(const string& elementBase) {
//     return Builder(elementBase);
// }

// struct HtmlElement{
// 	string name;
// 	string text;
// 	vector<HtmlElement> elements;
// 
// 	HtmlElement(){};
// 	HtmlElement(const string& n, const string& t) :name{n}, text{t}{};
// 
// 	void str(int indent = 0) const {
// 		if(name.length() > 0){
// 			ostringstream oss;
// 			for (int i = 0; i < indent; ++i)
//    				 oss << ' ';  // Append a space to the stream for each iteration
// 			oss << "<" << name << ">";
// 			oss << text;
// 			oss << "<" << name << ">";
// 			oss << '\n';
// 			printf("%s", oss.str().c_str());
// 		}	
// 
// 		for(auto elm: elements){
// 			elm.str(indent + 1);
// 		};
// 	};
// };
// 
// // Fluent interface builder
// struct Builder{
// 	HtmlElement elmBase;
// 
// 	Builder(string elmBaseName) {elmBase.name = elmBaseName; };
// 	Builder(string elmBaseName, string elmBaseText) {
// 		elmBase.name = elmBaseName; 
// 		elmBase.text = elmBaseText; 
// 	};
// 
// 	Builder& addChild(string childName, string childText){
// 		HtmlElement elm(childName, childText);
// 		elmBase.elements.emplace_back(elm); 
// 		return *this;
// 	};
// 
// };


// simpleBuilder
// struct Builder{
// 	HtmlElement elmBase;
// 
// 	Builder(string elmBaseName) {elmBase.name = elmBaseName; };
// 	Builder(string elmBaseName, string elmBaseText) {
// 		elmBase.name = elmBaseName; 
// 		elmBase.text = elmBaseText; 
// 	};
// 
// 	void addChild(string childName, string childText){
// 		HtmlElement elm(childName, childText);
// 		elmBase.elements.emplace_back(elm); 
// 		
// 	};
// 
// };
// 
// 
