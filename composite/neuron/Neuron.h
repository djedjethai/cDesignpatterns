#ifndef NEURON_H
#define NEURON_H

#include <ostream>
#include<vector>
#include<iostream>

struct Neuron;

template<typename Self>
struct SomeNeurons{
	template<typename T> 
	void connect_to(T& other){
		for(Neuron& from: *static_cast<Self*>(this)){
			for(Neuron& to: other){
				from.out.push_back(&to);
				to.in.push_back(&from);
			};
		};
	};
};


struct Neuron: public SomeNeurons<Neuron>{
	std::vector<Neuron*> in, out;

	unsigned int id;

	Neuron(){
		static int id = 1;
		this->id++;
	};

	// template<> 
	// void connect_to<Neuron>(Neuron& other)
	// {
	// 	out.push_back(&other);
	// 	other.in.push_back(this);
	// };
	
	Neuron* begin() {return this;};
	Neuron* end() { return this + 1; };

	friend std::ostream& operator<<(std::ostream& os, const Neuron& obj){
		for(Neuron* n: obj.in)
			os << n->id << "\t-->\t[" << obj.id << "]" << std::endl;

		for(Neuron* n: obj.out)
			os << "[" << obj.id << "]\t-->\t" << n->id << std::endl;

		return os;
	}
};

struct NeuronLayer: std::vector<Neuron>, SomeNeurons<NeuronLayer>{
	NeuronLayer(int count){
		// count-- while > 0
		while(count-->0)
			emplace_back(Neuron{});
	};

	friend std::ostream& operator<<(std::ostream& os, const NeuronLayer& obj){
		for(auto& n: obj) os << n;
		return os;
	};
};

#endif
