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

//Labis
ArrayList::ArrayList(int size) {
    this->size = size;
    item = new double[size];
    
    srand((unsigned)time(NULL));
    
    for(int i = 0; i < size; i++) {
        //item[i] = fmod((double)rand(), 100);
        item[i] = i;
    }
}

//Labis
ArrayList::~ArrayList() {
    delete item;
}

//Maniac
//epistrofh twn stoixeiwn tis listas san pinaka apo double.
double* ArrayList::getArrayList() {
    return item;
}

//Labis
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

//Labis
//prosthikh arithmou se ola ta stoixeia meta tin thesh x
void ArrayList::addNumber(double num, int x) {
    for(int i = x; i < MAX_LENGTH; i++) {
        item[i] += num;
    }
}

//Labis
void ArrayList::printArray(double *array) {
    
    cout << "======================" << endl;
    
    for(int i = 0; i < MAX_LENGTH; i++) {
        printf("item[%d] = %lf\n", i + 1, array[i]);
    }
}

//Nasos
//Prosthetei ena arithmo se kapoio shmeio ths listas kai epistrefei to shmeio
int ArrayList::addinPositionNumber(double ari)
{
  int position;

  srand((int)time(NULL));
  position=rand() % MAX_LENGTH -1;
  
  item[position] += ari;

  return position;
}

//Nasos
// Ean o arithmos yparxei sti thesi i ton afairei metakinontas ta upoloipa stoixeia 
int ArrayList::SubFoundNumber(double ari, int i)
{
  int k, yparxei=-1;
  

  if(ari==item[i]) {
    for(k=i;k<MAX_LENGTH-1;k++) item[k]=item[k+1];
    item[MAX_LENGTH-1]=0; 
    yparxei=0;
  }

  return yparxei;
}

//===========================M A I N ============================

int main (int argc, char **argv) {
    ArrayList *arrayList;
    assert(arrayList = new ArrayList(MAX_LENGTH));
    
    double *list;
    int thesi;

    assert(list = arrayList->getArrayList());
    arrayList->printArray(list);
    
    if(arrayList->insertNumber(111, 3))
        cout << "H eisagwgh egine me epituxeia" << endl;
    else
        cout << "H eisagwgh tou stoixeiou apetuxe" << endl;
    
    
    thesi=arrayList->addinPositionNumber(123);
    cout << "H prosthesi egine me epituxeia sti thesi  " << thesi << endl;
   
    
    if(arrayList->SubFoundNumber(12, 10)==0)
        cout << "O arithmos 12  yparxei sti thesi 10  " << endl;
    else
        cout << "O arithmos 12 den  yparxei sti thesi 10  " << endl;

    assert(list = arrayList->getArrayList());
    arrayList->printArray(list);
    
    arrayList->addNumber(100, 50);
    assert(list = arrayList->getArrayList());
    arrayList->printArray(list);

    return 0;
}

