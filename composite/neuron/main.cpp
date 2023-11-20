#include"Neuron.h"
#include<iostream>

using namespace std;


int main(){

	Neuron n1, n2;
	n1.connect_to(n2);

	cout << n1 << n2 << endl;

	NeuronLayer l1{5};
	Neuron n3;
	l1.connect_to(n3);

	cout << "Neuron " << n3.id << endl << n3 << endl;
  	cout << "Layer " << endl << l1 << endl;
	
	NeuronLayer l2{2}, l3{3};
		
	l2.connect_to(l3);

	cout << "Layer l2" << endl << l2;
  	cout << "Layer l3" << endl << l3;
		
	return 0;
};

