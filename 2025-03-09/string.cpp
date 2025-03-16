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
        while(str[size] != '\0')
        {
            size++;
        }
        data = new char[size+1];
        for(int i = 0; i<size; i++)
        {
            data[i] = str[i];
        }
        data[size] = '\0';
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
        data = (char *)realloc(data, (size+2)*sizeof(char));
        data[size] = ch;
        data[size+1] = '\0';
        size++;
    }

  
    void concat(const char *str)
    {
        int strsize = 0;
        while(str[strsize] != '\0')
        {
            strsize++;
        }
        data = (char *)realloc(data, (size+strsize+1)*sizeof(char));
        for(int i = 0; i < strsize; i++)
        {
            data[size+i] = str[i];
        }
        size += strsize;
        data[size] = '\0';
    }


    int compare(const String &other) const
    {
        int i = 0;
        while(this->data[i] != '\0' && other.data[i] != '\0')
        {
            if (this->data[i] < other.data[i])
                return -1;
            if (this->data[i] > other.data[i])
                return 1;
            i++;
        }
        if(this->size == other.size)
            return 0;
        else if(this->size > other.size)
            return 1;
        else
            return -1;
    }
};
