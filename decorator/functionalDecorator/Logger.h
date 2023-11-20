#ifndef LOGGER_H
#define LOGGER_H

#include<functional>
#include<string>
#include<iostream>

double add(double a, double b){
	std::cout << a << "+" << b << "=" << (a + b) << std::endl;
	return a + b;
};

// need partial specialization for this to work
template <typename> struct LoggerAdd;

template<typename R, typename... Args >
struct LoggerAdd<R(Args...)>{
	std::function<R(Args ...)> func;
	std::string name;

	LoggerAdd(std::function<R(Args ...)> f, const std::string& n):func{f}, name{n}{};

	R operator()(Args ...args){
		std::cout << "Entering " << name << std::endl;
		R result = func(args...);
		std::cout << "Exiting " << name << std::endl;
		return result;
	};
};

// MakeLoggerAdd function template is a utility function that simplifies the creation of instances of the LoggerAdd template. 
template<typename R, typename... Args>
auto MakeLoggerAdd(R (*func)(Args...), const std::string& n){
	return LoggerAdd<R(Args...) >(std::function<R(Args...)>(func), n);
}

struct Logger{
	// declares a template func that can hold and invoke functions taking no arguments and returning void
	std::function<void()> func;
	std::string name;
	
	Logger(const std::function<void()>& f, const std::string& n):func{f}, name{n}{} 

	void operator()() const {
		std::cout << "Entering " << name << std::endl;
		func();
		std::cout << "Exiting " << name << std::endl;
	};

};


template<typename Func>
struct LoggerCopy{
	Func func;
	std::string name;
	
	LoggerCopy(const Func& f, const std::string& n):func{f}, name{n}{};

	void operator()() const {
		std::cout << "Entering LoggerCopy" << name << std::endl;
		func();
		std::cout << "Exiting LoggerCopy" << name << std::endl;
	};	
	
};

template<typename Func>
auto make_loggerCopy(Func func, const std::string& name){
	return LoggerCopy<Func>{func, name};
};





#endif
