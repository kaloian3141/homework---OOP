#include <iostream>

using namespace std;

class String
{
    char *data;
    size_t size;

public:
    String()
    {
        size = 0;
        data = new char[1];
        data[0] = '\0';
    }

    String(const char *str)
    {
        size = 0;
        while (str[size] != '\0')
        {
            size++;
        }

        data = new char[size + 1];
        for (size_t i = 0; i <= size; i++)
        {
            data[i] = str[i];
        }
    }

    
    String(const String &other)
    {
        this->size = other.size;
        this->data = new char[this->size+1];
        for(int i = 0; i <size+1; i++)
        {
            this->data[i] = other.data[i];
        }
    }

    String &operator=(const String &other)
    {
        if(this != &other)
        {
            delete[] this->data;
            this->size = other.size;
            this->data = new char[this->size+1];
            for(int i = 0; i <size+1; i++)
            {
                this->data[i] = other.data[i];
            }
        }
        return *this;
    }


    String &insert(size_t index, char c)
    {
        if(index > this->size || index < 0)
            return *this;
        this->data = (char*)realloc(data, sizeof(char)*this->size+2);
        for(int i = this->size+1; i>index; i--)
        {
            this->data[i] = this->data[i-1];
        }
        this->data[index] = c;
        this->size++;
        return *this;
    }


    String &replace(size_t index, char c)
    {
        if(index > this->size || index < 0)
            return *this;
        this->data[index] = c;
        return *this;
    }


    int findFirstOf(char c) const
    {
        for(int i = 0; i<this->size; i++)
        {
            if(this->data[i] == c)
                return i;
        }
        return -1;
    }

    ~String()
    {
        delete[] data;
    }


    char *toCString() const
    {
        return data;
    }


    size_t length() const
    {
        return size;
    }


    void append(char ch)
    {
        char *newData = new char[size + 2];

        for (size_t i = 0; i < size; i++)
        {
            newData[i] = data[i];
        }

        newData[size] = ch;
        newData[size + 1] = '\0';

        delete[] data;
        data = newData;
        size++;
    }


    void concat(const char *str)
    {
        size_t strLen = 0;
        while (str[strLen] != '\0')
        {
            strLen++;
        }

        char *newData = new char[size + strLen + 1];

        for (size_t i = 0; i < size; i++)
        {
            newData[i] = data[i];
        }

        for (size_t i = 0; i <= strLen; i++)
        {
            newData[size + i] = str[i];
        }

        delete[] data;
        data = newData;
        size += strLen;
    }


    int compare(const String &other) const
    {
        size_t minLen = size < other.size ? size : other.size;

        for (size_t i = 0; i < minLen; i++)
        {
            if (data[i] < other.data[i])
                return -1;
            if (data[i] > other.data[i])
                return 1;
        }

        if (size < other.size)
            return -1;
        if (size > other.size)
            return 1;
        return 0;
    }
};