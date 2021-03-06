/* 
 * File:   ArrayList.h
 * Author: labis
 *
 */

#ifndef ARRAYLIST_H
#define	ARRAYLIST_H

#define MAX_LENGTH      100

struct set_n
{
    double num ;
    int pos ;
}

class ArrayList {
public:
    ArrayList(int size);
    virtual ~ArrayList();
    double *getArrayList();
    bool insertNumber(double num, int x);
    void addNumber(double num, int x);
    void printArray(double *array);
    double *listReverse();
    
    int  addinPositionNumber(double ari);
    int SubFoundNumber(double ari, int i);
    
    void ArrayList::DecreaseByX(int position, double x) ;
    set_n ArrayList::RemoveRandom() ;

private:
    int size;
    double *item;
};

#endif	/* ARRAYLIST_H */

