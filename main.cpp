#include"UPQ.h"
#include "SPQ.h"
#include "heap.h"
#include <iostream>
#include <fstream>
#include <time.h>
#include <string>
#include <sys/time.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

#define CAP 5000

long timediff(timeval& a, timeval& b) {
    return a.tv_sec * 1e6 + a.tv_usec
            - b.tv_sec * 1e6 - b.tv_usec;
}
int main() {
    struct timeval tvalBefore, tvalAfter, insert;

    Queue<int> queue(CAP);


    int temparr[CAP];
    // Fill array
    for (int i = 0; i < CAP; i++){
        temparr[i] = rand() % 1000 + 1;
    }

    cout << queue.describe() << endl;
    cout << "*******************" << endl;
    
    printf("%10s %10s %10s %10s\n", "Data Size", "Insert", "Remove", "Total");
    for (int size = 1000; size <= CAP; size += 100) {
        gettimeofday(&tvalBefore,NULL);
        for(int i = 0; i < size; i++){
            queue.insert(temparr[i]);
        }

        gettimeofday(&insert,NULL);
        for(int i = 0; i < size; i++){
            queue.removeMin();
        }

        gettimeofday(&tvalAfter, NULL);
       
        printf("%10d %10ld %10ld %10ld\n",
            size,
            timediff(insert, tvalBefore),
            timediff(tvalAfter, insert),
            timediff(tvalAfter, tvalBefore))
            ;
    }


}