
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include "defs.h"

using namespace std;


class Array {

	public:
		//constructor
		Array();
				
		//destructor
		~Array();
		
		//other
		void add(int);
		void remove(int);
		int get(int index);
		int size();
		bool isFull();
	
	private:
		int numElements;
		int* elements;
	
};

Array::Array(){
	elements = new int[MAX_ARRAY];
	numElements = 0;
}

Array::~Array(){
	delete [] elements;
}

void Array::add(int t){
	if (numElements >= MAX_ARRAY)   return;
  	elements[numElements++] = t;
}

void Array::remove(int t){
	int index = 0;
	while (index < numElements){
		if (t == elements[index]){
			--numElements;
			break;
		}
		++index;
	}

	while (index < numElements){
		elements[index] = elements[index + 1];
		++index;
	}
}

int Array::size(){
	return numElements;
}

bool Array::isFull(){
	return numElements >= MAX_ARRAY;
}

int Array::get(int index){
	if (index < 0 || index >= numElements) {
		cerr<<"Array index out of bounds"<<endl;
		exit(1);
	}
	return elements[index];
}

#endif
