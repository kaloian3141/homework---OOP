#include<iostream>
// Работа на Калоян Влахов 14 номер и Йордан Цонев 13 номер
using namespace std;

typedef enum Card
{
    DSK, 
    UNICREDIT
}Card;

class Shop
{
    double cashBal;
    double bankBal;
    public:
    Shop()
    {
        this->bankBal = 0;
        this->cashBal = 0;
    }

    void setCashBal(double amount)
    {
        this->cashBal = amount;
    }
    double getCashBal() const
    {
        return this->cashBal;
    }
    void setBankBal(double amount)
    {
        this->bankBal = amount;
    }
    double getBankBal() const
    {
        return this->bankBal;
    }

    virtual void payCash(double amount) 
    {
        this->cashBal += amount;
    }

    virtual void payCard(double amount, Card type)
    {
        this->bankBal += amount;
    }
};


class Laptop: public Shop
{
    public:
    Laptop()
    {
        setBankBal(0);
        setCashBal(0);
    }

    void payCash(double amount) override
    {
        setCashBal(this->getCashBal() + (amount * 90 / 100));
    }

    void payCard(double amount, Card type) override
    {
        if(type == DSK)
        {
            setBankBal(amount);
        }
        else
        {
            throw invalid_argument("Card type must be DSK");
        }
    }
};

class Phone: public Shop
{
    public:
    Phone()
    {
        setBankBal(0);
        setCashBal(0);
    }

    void payCash(double amount) override
    {
        setCashBal(this->getCashBal() + (amount * 85 / 100));
    }

    void payCard(double amount, Card type) override
    {
        if(type == UNICREDIT)
        {
            setBankBal(amount);
        }
        else
        {
            throw invalid_argument("Card type must be UNICREDIT");
        }
    }
};

class Grocery: public Shop
{
    public:
    Grocery()
    {
        setBankBal(0);
        setCashBal(0);
    }

    void payCash(double amount) override
    {
        setCashBal(this->getCashBal() + amount);
    }

    void payCard(double amount, Card type) override
    {
        throw invalid_argument("You cant pay with card");
    }
};