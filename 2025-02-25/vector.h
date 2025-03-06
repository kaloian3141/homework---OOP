#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

using namespace std;

extern int ERROR_1;

struct Vector
{
    int *data;
    size_t size;
    size_t capacity;
};

Vector* initVector();
void pushBack(Vector* v, int val);
void print(Vector* v);
int pop(Vector* v);
int at(Vector* v, int index);
void destroy(Vector* v);
void pushFront(Vector* v, int val);
int insert(Vector* v, int index, int val);
int popFront(Vector* v);
int remove(Vector* v, int index);

#endif 