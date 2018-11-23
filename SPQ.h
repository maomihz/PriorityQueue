#pragma once
#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <stdexcept>
#include <iostream>
using namespace std;

template <class Type>
class PriorityQueue {
private:
	Type* arrayPointer;

	int capacity;
	int arraySize;
	int head;
public:

	PriorityQueue(int cap)
		: capacity(cap), 
		  arraySize(0), 
		  head(0)
	{
		arrayPointer = new Type[capacity];
	}

	~PriorityQueue() {
		delete [] arrayPointer;
	}

	bool empty() {
		return arraySize == 0;
	}
	int size() {
		return arraySize;
	}

	void print(ostream& os) {
		for (int i = head; i < head + arraySize; i++) {
			os << at(i) << ", ";
		}
		os << endl;
	}

	Type& at(int index) {
		if (index >= capacity) {
			return arrayPointer[index - capacity];
		}
		return arrayPointer[index];
	}

	void insert(Type data) {
		if (arraySize >= capacity) {
			throw std::runtime_error("Over Capacity!!!");
		}
		int i = head + arraySize - 1;
		while (i >= head && at(i) > data) {
			at(i + 1) = at(i);
			i--;
		}

		at(i + 1) = data;
		arraySize ++;
	}


	Type removeMin() {
		if (arraySize == 0) {
			throw std::runtime_error("Cannot remove element from empty queue");
		}
		Type m = at(head);
		head ++;
		arraySize --;
		if (head >= capacity) {
			head = 0;
		}

		return m;
	}
	Type minValue(void) {
		if(arraySize == 0){
        	throw std::runtime_error("No min for empty queue");
		}
		return at(head);
	}

    string describe() {
        return "Sorted Priority Queue";
    }
};
#endif