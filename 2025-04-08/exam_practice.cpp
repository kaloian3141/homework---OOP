#include <iostream>
#include <cstring>
using namespace std;
class Device
{
    double memorySize, screenSize, price;
    char * brand;
    char * constantSerial;
    static int counter;
public:
    Device(double memorySize, double screenSize, double price, const char *brand, const char *constantSerial)
    {
        if(memorySize <= 0)
        {
            throw invalid_argument("memory size must be positive number");
            return;
        }
        if(screenSize <= 0)
        {
            throw invalid_argument("screen size must be positive number");
            return;
        }
        if(price <= 0)
        {
            throw invalid_argument("price must be positive number");
            return;
        }
        if(brand == "" && brand == nullptr)
        {
            throw invalid_argument("brand must not be empty name");
            return;
        }
        if(constantSerial == "" && constantSerial == nullptr)
        {
            throw invalid_argument("Serial must not be empty name");
            return;
        }
        this->memorySize = memorySize;
        this->screenSize = screenSize;
        this->price = price;
        this->brand = strdup(brand);
        this->constantSerial = strdup(constantSerial);
        this->counter++;
    }

    Device(const Device &other)
    {
        this->memorySize = other.memorySize;
        this->screenSize = other.screenSize;
        this->price = other.price;
        this->brand = strdup(other.brand);
        this->constantSerial = strdup(other.constantSerial);
        this->counter++;
    }

    Device &operator=(const Device &other)
    {
        if(this != &other)
        {
            delete[] this->brand;
            delete[] this->constantSerial;
            this->memorySize = other.memorySize;
            this->screenSize = other.screenSize;
            this->price = other.price;
            this->brand = strdup(other.brand);
            this->constantSerial = strdup(other.constantSerial);
        }
        return *this;
    }

    ~Device()
    {
        delete[] this->brand;
        delete[] this->constantSerial;
        counter--;
    }
    bool isWorthBuying() const
    {
        if((this->memorySize * this->screenSize) / this->price > 0.1)
        {
            return true;
        }
        return false;
    }

    double getMemorySize() const
    {
        return this->memorySize;
    }

    double getScreenSize() const
    {
        return this->screenSize;
    }

    double getPrice() const
    {
        return this->price;
    }

    char * getBrand() const
    {
        return this->brand;
    }

    char * getConstantSerial() const
    {
        return this->constantSerial;
    }

    static int getCounter()
    {
        return counter;
    }

    void setMemorySize(double memorySize)
    {
        if(memorySize <= 0)
        {
            throw invalid_argument("memory size must be positive number");
            return;
        }
        this->memorySize = memorySize;
 
    } 

    void setScreenSize(double screenSize)
    {
        if(screenSize <= 0)
        {
            throw invalid_argument("screen size must be positive number");
            return;
        }
        this->screenSize = screenSize;
       
    }

    void setPrice(double price)
    {
        if(price = 0)
        {
            throw invalid_argument("price must be positive number");
            return;
        }
        this->price = price;
    }

    void setBrand(const char * brand)
    {
        if(brand == "" && brand == nullptr)
        {
            throw invalid_argument("brand must not be empty name");
            return;

        }
        delete[] this->brand;
        this->brand = strdup(brand);
    }

    void setConstantSerial(const char * constantSerial)
    {
        if(constantSerial == "" && constantSerial == nullptr)
        {
            throw invalid_argument("Serial must not be empty name");
            return;
        }
        delete[] this->constantSerial;
        this->constantSerial = strdup(constantSerial);
    }

};

class Phone : public Device
{
    int cameraParameters;

public:
    Phone(double memorySize, double screenSize, double price, const char *brand, const char *constantSerial, int cameraParameters)
    :Device(memorySize, screenSize, price, brand, constantSerial)
    {
        if(cameraParameters <= 0)
        {
            throw invalid_argument("Camera parameters must be positive integer");
            return;
        }
        this->cameraParameters = cameraParameters;
    }

    Phone(const Phone &other)
    :Device(other)
    {
        this->cameraParameters = other.cameraParameters;
    }

    Phone &operator=(const Phone &other)
    {
        Device::operator=(other);
        if(this != &other)
        {
            this->cameraParameters = other.cameraParameters;
        }
        return *this;
    }

    bool isWorthBuying() const
    {
        if(((this->getMemorySize()*this->getScreenSize()) + (this->getMemorySize()*this->cameraParameters)) / this->getPrice() > 0.1)
            return true;
        else
            return false;
    }
    int getCameraParameters() const
    {
        return this->cameraParameters;
    }
    
    void setCameraParameters(int cameraParameters)
    {
        if(cameraParameters <= 0)
        {
            throw invalid_argument("Camera parameters must be positive integer");
            return;
        }
        this->cameraParameters = cameraParameters;
        
    }
};
