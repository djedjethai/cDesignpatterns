#ifndef PONG_H
#define PONG_H

#include "iostream"
#include "string"


class Pingable{
public:
	virtual std::wstring ping(const std::wstring& message) = 0;
	virtual ~Pingable() = default;
};

class Pong: public Pingable {
public:		
	std::wstring ping(const std::wstring& message) override {
		return message + L" pong";	
	};

	virtual ~Pong() = default;
	
};

inline void tryIT(Pingable& pp) {
	std::wcout << pp.ping(L"ping") << "\n";	
}









#endif
