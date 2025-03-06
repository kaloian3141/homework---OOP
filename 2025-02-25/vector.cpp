#include<iostream>
#include "vector.h"
int ERROR_1 = 2147483647;

/*
int main()
{
    Vector * v = initVector();
    int a = popFront(v);
    cout << a << endl;
    pushBack(v, 1);
    pushBack(v, 2);
    pushBack(v, 3);
    pushBack(v, 4);
    pushBack(v, 5);
    pushBack(v, 6);
    pushBack(v, 7);
    pushBack(v, 8);
    pushBack(v, 9);
    int b = pop(v);
    cout << at(v, 7) << endl;
    cout << b << endl;
    cout << remove(v, 1) <<endl;
    cout << insert(v, 76, 7) <<endl;
    pushFront(v, 4);
    popFront(v);
    print(v);
    destroy(v);
    print(v);
    cout << remove(v, 1) << endl;
    return 0;
}
*/

Vector* initVector()
{
    Vector * v = new Vector();
    v->capacity = 2;
    v->size = 0;
    v->data = new int[v->capacity];
    return v;
}
void pushBack(Vector * v, int val)
{
    if(v->size == v->capacity)
    {
        v->capacity *= 2;
        v->data = (int*)realloc(v->data, v->capacity*sizeof(int));

    }
    v->data[v->size] = val;
    v->size++;
    return;
    
}

void print(Vector *v)
{
    cout << "Vector's size: " << v->size << endl;
    cout << "Vector's capacity: " << v->capacity << endl;
    cout << "Vector's data: [";

    if (v->size > 0)
        cout << v->data[0];
    for (size_t i = 1; i < v->size; i++)
    {
        cout << " " << v->data[i];
    }
    cout << "]" << endl;
}

int pop(Vector * v)
{
    if(v->size == 0)
    {
        cout << "Empty vector" << endl;
        return ERROR_1;
    }
    int deleted_element = v->data[v->size-1];
    v->size--;
    return deleted_element;
}

int at(Vector * v, int index)
{
    if(index >= 0 && index < v->size)
    {
        return v->data[index];
    }
    else
    {
        cout << "Index out of range" << endl;
        return ERROR_1;
    }
}

void destroy(Vector * v)
{
    delete []v->data;
    v->size = 0;
    v->capacity = 2;
}

void pushFront(Vector * v, int val)
{
    if(v->size == 0)
    {
        pushBack(v, val);
    }

    if(v->size == v->capacity)
    {
        v->capacity *= 2;
        v->data = (int*)realloc(v->data, v->capacity*sizeof(int));

    }
    
    for(int i = v->size; i > 0; i--)
    {
        v->data[i] = v->data[i-1];
    }
    v->data[0] = val;
    v->size++;
}

int insert(Vector* v, int index, int val)
{
    if(index < 0 || index >v->size)
    {
        cout <<"Index out of range" << endl;
        return ERROR_1;
    }
    if(v->size == v->capacity)
    {
        v->capacity *= 2;
        v->data = (int*)realloc(v->data, v->capacity*sizeof(int));

    }
    
    for(int i = v->size; i > index; i--) 
    {
        v->data[i] = v->data[i-1];
    }
    v->data[index] = val;
    v->size++;
    return 0;   
}

int popFront(Vector * v)
{   
    if(v->size  == 0)
    {
        cout << "Empty vector" << endl;
        return ERROR_1;
    }
    int deleted_element = v->data[0];
    for(int i = 0; i<v->size-1; i++)
    {
        v->data[i] = v->data[i+1];

    }
    v->size--;
    return deleted_element;

}

int remove(Vector *v, int index)
{
    if(v->size == 0)
    {
        cout << "Empty vector" << endl;
        return ERROR_1;
    }
    if(index < 0 || index >= v->size)
    {
        cout <<"Index out of range" << endl;
        return ERROR_1;
    }
    int deleted_element = v->data[index];
    for(int i = index; i<v->size-1; i++)
    {
        v->data[i] = v->data[i+1];

    }
    v->size--;
    return deleted_element;
}