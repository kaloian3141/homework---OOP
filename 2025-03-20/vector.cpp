#include <iostream>
#include <exception>
using namespace std;

class Vector
{
    int *data;
    size_t size;
    size_t capacity;
    const int id;

    void resize()
    {
        this->capacity *= 2;
        int * new_data = new int[this->capacity];
        for(int i = 0; i < this->size;i++)
        {
            new_data[i] = this->data[i];
        }
        delete[] this->data;
        this->data = new_data;

    }

public:
    Vector(int id, int capacity)
    :id(id)
    {
        if(capacity <= 0)
        {
            throw invalid_argument("capacity must be positive integer");
            return;
        }
        if(id <= 0)
        {
            throw invalid_argument("id must be positive integer");
            return;
        }
        this->capacity = capacity;
        this->data = new int[capacity];
        this->size = 0;
    }

    ~Vector()
    {
        delete[] data;
    }

    size_t getSize() const
    {
        return this->size;
    }

    size_t getCapacity() const
    {
        return this->capacity;
    }

    int getId() const
    {
        return this->id;
    }

    void pushBack(int number)
    {
        if(size == capacity)
        {
            this->resize();
        }
        
        this->data[size] = number;
        this->size++;
    }

    int at(int index) const
    {
        if(index < 0 || index >= size)
        {
            throw out_of_range("index out of range");
            return -1;
        }
        return this->data[index];

    }

    int insert(int index, int value)
    {
        if(index < 0 || index > size)
        {
            throw out_of_range("index out of range");
            return -1;
        }
        if(size == capacity)
        {
            this->resize();
        }
        for(int i = this->size; i > index; i--) 
        {
            this->data[i] = this->data[i-1];
        }
        this->data[index] = value;
        this->size++;
        return 0;   
    }

    int remove(int index)
    {
        if(this->size == 0)
        {
            throw invalid_argument("you cant remove from empty vector");
            return -1;
        }
        if(index < 0 || index >= size)
        {
            throw out_of_range("index out of range");
            return -1;
        }
        int deleted_element = this->data[index];
        for(int i = index; i<this->size-1; i++)
        {
            this->data[i] = this->data[i+1];

        }
        this->size--;
        return deleted_element;
    }

    int pop()
    {
        if(this->size == 0)
        {
            throw out_of_range("you cant pop from empty vector");
            return -1;
        }
        int deleted_element = this->data[size-1];
        this->size--;
        return deleted_element;
    }
};