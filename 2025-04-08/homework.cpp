#include <iostream>
#include <string>

using namespace std;

class Animal
{
private:
    string name;
    int age; 
    double weight;
    bool isHungry;

public:
    Animal(const string &name, int age, double weight)
    {
        if(name != "")
        {
            this->name = name;
        }
        else
        {
            throw invalid_argument("name must not be empty");
            return;
        }
        if(age >= 0)
        {
            this->age = age;
        }
        else
        {
            throw invalid_argument("age must not be negative number");
            return;
        }
        if(weight >= 0)
        {
            this->weight = weight;
        }
        else
        {
            throw invalid_argument("weight must not be negative number");
            return;
        }
        this->isHungry = false; 

    }

    string getName() const
    {
        return this->name;
    }

    int getAge() const
    {
        return this->age;
    }

    double getWeight() const
    {
        return this->weight;
    }

    bool getHungerStatus() const
    {
        return this->isHungry;
    }

    void setName(const string &name)
    {
        if(name != "")
        {
            this->name = name;
        }
        else
        {
            throw invalid_argument("name must not be empty");
            return;
        }
    }

    void setAge(int age)
    {
        if(age >= 0)
        {
            this->age = age;
        }
        else
        {
            throw invalid_argument("age must not be negative number");
            return;
        }
    }

    void setWeight(double weight)
    {
        if(weight >= 0)
        {
            this->weight = weight;
        }
        else
        {
            throw invalid_argument("weight must not be negative number");
            return;
        }
    }

    void feed()
    {
        this->isHungry = false;
    }

    void sleep()
    {
        this->isHungry = true;
    }
};

class Dog : public Animal
{
private:

    string breed;
    bool isGoodBoy;

public:
    Dog(const string &name, int age, double weight, const string &breed)
    :Animal(name, age, weight)
    {
        if(breed != "")
        {
            this->breed = breed;
        }
        else
        {
            throw invalid_argument("name of the breed must not be empty");
            return;
        }
    }

    void bark() const
    {
        cout <<"Woof!"<<endl;
    }

    void wagTail() const
    {
        cout<<"Dog is wagging its tail!"<<endl;
    }

    string getBreed() const
    {
        return this->breed;
    }

    void setBreed(const string &breed)
    {
        if(breed != "")
        {
            this->breed = breed;
        }
        else
        {
            throw invalid_argument("name of the breed must not be empty");
            return;
        }
    }
};

class Cat : public Animal
{
private:

    bool isIndoor;
    int livesLeft = 9;

public:

    Cat(const string &name, int age, double weight, bool isIndoor)
    :Animal(name, age, weight)
    {
        this->isIndoor = isIndoor;
    }

    void meow()
    {
        cout <<"Meow!"<<endl;
    }

    void purr()
    {
        cout<<"Cat is purring..."<<endl;
    }

    bool getIsIndoor()
    {
        return this->isIndoor;
    }

    void setIsIndoor(bool isIndoor)
    {
        this->isIndoor = isIndoor;
    }

    int getLivesLeft()
    {
        return this->livesLeft;
    }
};