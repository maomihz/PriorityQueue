#pragma once
#ifndef UNPRIORITY_QUEUE_H
#define UNPRIORITY_QUEUE_H

#include <stdexcept>
#include <iostream>
using namespace std;

template <class Type>
class UnsortedPriorityQueue {
private:
    Type* arrayPointer;

    int capacity;
    int arraySize;
public:

    UnsortedPriorityQueue(int _cap)
        : capacity(_cap),
        arraySize(0)
    {
        arrayPointer = new Type[capacity];
    }
    ~UnsortedPriorityQueue(void) {
        delete [] arrayPointer;
    }
    bool empty(void) {
        return arraySize == 0;
    }
    int size(void) {
        return arraySize;
    }

    void insert(Type data) {
        if (arraySize >= capacity) {
            throw std::runtime_error("Over Capacity!!!");
        }
        arrayPointer[arraySize] = data;
        arraySize ++;
    }

    Type removeMin(void) {
        int minIndex;
        Type min = minValue(minIndex);

        arrayPointer[minIndex] = arrayPointer[arraySize - 1];
        arraySize --;

        return min;
    }

    Type minValue() {
        int minIndex;
        return minValue(minIndex);
    }

    Type minValue(int& minIndex) {
        if (arraySize == 0) {
            throw std::runtime_error("Nothing in the queue!!!");
        }

        minIndex = 0;
        Type min = arrayPointer[0];

        for(int i = 1; i < arraySize; i++){
            if (arrayPointer[i] < min){
                min = arrayPointer[i];
                minIndex = i;
            }
        }

        return min;
    }

    string describe() {
        return "Unsorted Priority Queue";
    }
};
#endif