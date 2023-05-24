#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Document{
public:
	string name;
	Document(string n):name{n}{};
};

struct IPrinter {
	virtual void print(vector<Document*> docs) = 0;
};

struct IScanner {
	virtual void scan(vector<Document*> docs) = 0;
};

struct IPrintScan : IPrinter, IScanner {	
	virtual void print(vector<Document*> docs) = 0;
	virtual void scan(vector<Document*> docs) = 0;
};

// class implementation
class Printer : public IPrinter {
public:
	void print(vector<Document*> docs) override {
		for(auto d:docs)
			cout << "printing: " << d->name << endl;
	};
};

class Scanner : public IScanner {
public:
	void scan(vector<Document*> docs) override {
		for(auto d:docs)
			cout << "scanning: " << d->name << endl;
	};
};

class MyPrintScan : public IPrintScan {
public:
	IPrinter&  printer;
	IScanner& scanner;

	MyPrintScan(IPrinter& pr, IScanner& sc): printer{pr}, scanner{sc} {};
		
	void print(vector<Document*> docs) override {
		printer.print(docs);
	};

	void scan(vector<Document*> docs) override {
		scanner.scan(docs);
	};
};

// struct implementation
// struct Printer : IPrinter {
// 	void print(vector<Document*> docs) override {
// 		for(auto d:docs)
// 			cout << "printing: " << d->name << endl;
// 	};
// };
// 
// struct Scanner : IScanner {
// 	void scan(vector<Document*> docs) override {
// 		for(auto d:docs)
// 			cout << "scanning: " << d->name << endl;
// 	};
// };
// 
// struct MyPrintScan : IPrintScan {
// 	IPrinter&  printer;
// 	IScanner& scanner;
// 
// 	MyPrintScan(IPrinter& pr, IScanner& sc): printer{pr}, scanner{sc} {};
// 		
// 	void print(vector<Document*> docs) override {
// 		printer.print(docs);
// 	};
// 
// 	void scan(vector<Document*> docs) override {
// 		scanner.scan(docs);
// 	};
// };
