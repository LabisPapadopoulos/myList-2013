/* 
 * File:   ArrayList.cpp
 * Author: labis
 * 
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <assert.h>
#include "ArrayList.h"

using namespace std;

ArrayList::ArrayList(int size) {
    this->size = size;
    item = new double[size];
    
    srand((unsigned)time(NULL));
    
    for(int i = 0; i < size; i++) {
        //item[i] = fmod((double)rand(), 100);
        item[i] = i;
    }
    
//    for(int i = 0; i < size; i++) {
//        printf("item[%d] = %lf\n", i, item[i]);
//    }
    
}

ArrayList::~ArrayList() {
    delete item;
}

//epistrofh twn stoixeiwn tis listas san pinaka apo double.
double* ArrayList::getArrayList() {
    return item;
}

//eisagwgh enos arithmou stin thesh x tis listas
bool ArrayList::insertNumber(double num, int x) {
    int thesh = x - 1;
    int lastPosition = MAX_LENGTH - 1;
    
    if((thesh >= 0) && (thesh < MAX_LENGTH)) {
        for(;lastPosition >= thesh; lastPosition--) {
            //metakinish twn upoloipwn stoixeiwn
            item[lastPosition + 1] = item[lastPosition];
        }
        
        item[thesh] = num;
        return true;
    }
    else
        return false;
}

//prosthikh arithmou se ola ta stoixeia meta tin thesh x
void ArrayList::addNumber(double num, int x) {
    for(int i = x; i < MAX_LENGTH; i++) {
        item[i] += num;
    }
}

void ArrayList::printArray(double *array) {
    
    cout << "======================" << endl;
    
    for(int i = 0; i < MAX_LENGTH; i++) {
        printf("item[%d] = %lf\n", i + 1, array[i]);
    }
}

int main (int argc, char **argv) {
    ArrayList *arrayList;
    assert(arrayList = new ArrayList(MAX_LENGTH));
    
    double *list;
    assert(list = arrayList->getArrayList());
    arrayList->printArray(list);
//    for(int i = 0; i < MAX_LENGTH; i++) {
//        printf("item[%d] = %lf\n", i, list[i]);
//    }
    
    if(arrayList->insertNumber(111, 3))
        cout << "H eisagwgh egine me epituxeia" << endl;
    else
        cout << "H eisagwgh tou stoixeiou apetuxe" << endl;
    
    assert(list = arrayList->getArrayList());
    arrayList->printArray(list);
//    for(int i = 0; i < MAX_LENGTH; i++) {
//        printf("item[%d] = %lf\n", i, list[i]);
//    }
    
    arrayList->addNumber(100, 50);
    assert(list = arrayList->getArrayList());
    arrayList->printArray(list);
}

