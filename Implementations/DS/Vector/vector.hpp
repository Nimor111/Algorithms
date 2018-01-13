#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include <iostream>

class Vector
{
public:
    /**** Big four ****/
    Vector();
    Vector(Vector const &);
    Vector& operator=(Vector const &);
    ~Vector();
    /**** Big four ****/

    void insert(int index, int value);
    void add(int value);
    void print() const;
    int get(int index) const;
    void remove(int index);
    int pop();
    int size() const;
    int capacity() const;

private:
    int * array;
    int _capacity;
    int currentSize;
    bool checkCapacity() const;
    void addCapacity();
};

#endif
