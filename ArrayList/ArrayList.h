/* 
 * File:   ArrayList.h
 * Author: labis
 *
 */

#ifndef ARRAYLIST_H
#define	ARRAYLIST_H

#define MAX_LENGTH      100

class ArrayList {
public:
    ArrayList(int size);
    virtual ~ArrayList();
    double *getArrayList();
    bool insertNumber(double num, int x);
    void addNumber(double num, int x);
    void printArray(double *array);
    
    int  addinPositionNumber(double ari);
    int SubFoundNumber(double ari, int i);
private:
    int size;
    double *item;
};

#endif	/* ARRAYLIST_H */

