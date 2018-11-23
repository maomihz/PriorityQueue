#ifndef HeapPRIORITY_QUEUE_H
#define HeapPRIORITY_QUEUE_H

#include <climits>
using namespace std;


template <class Type>
class HeapPriorityQueue
{
private:

    Type *h;
    int hsize;
    int capacity;
public:

    HeapPriorityQueue(int _cap)
        : capacity(_cap) {
        hsize = 0;
        h = new Type[capacity];
    }

    ~HeapPriorityQueue(void) {
        delete [] h;
    }

    bool empty(void) {
        return hsize == 0;
    }

    int size(void) {
        return hsize;
    }

    void insert(Type data) {
        if (hsize == capacity)
        {
            return;
        }
        hsize++;
        int i = hsize - 1;
        h[i] = data;
        while (i != 0 && h[(i-1)/2] > h[i])
        {
            swap(&h[i], &h[(i-1)/2]);
            i =(i-1)/2;
        }
    }
    Type removeMin(void) {
        if (hsize == 0) {
            throw std::runtime_error("Cannot remove element from empty queue");
        }
        if (hsize <= 0)
            return INT_MAX;
        if (hsize == 1)
        {
            hsize--;
            return h[0];
        }
        Type root = h[0];
        h[0] = h[hsize-1];
        hsize--;
        MinHeapify(0);
        return root;
    }

    Type minValue(void) {
        if (hsize == 0) {
            throw std::runtime_error("Cannot remove element from empty queue");
        }
        return h[0];

    }

    void swap(Type *x, Type *y)
    {
        Type temp = *x;
        *x = *y;
        *y = temp;
    }

    void MinHeapify(Type i)
    {
        Type left = (2*i + 1);
        Type right = (2*i + 2);
        Type smallest = i;
        if (left < hsize && h[left] < h[i])
            smallest = left;
        if (right < hsize && h[right] < h[smallest])
            smallest = right;
        if (smallest != i)
        {
            swap(&h[i], &h[smallest]);
            MinHeapify(smallest);
        }
    }

    string describe() {
        return "Heap Priority Queue";
    }


};

#endif
