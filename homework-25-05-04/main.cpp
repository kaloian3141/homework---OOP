#include<iostream>
#include<string>
#include<cmath>
#include<cstring>
using namespace std;
void readLine(string& input, string &str1, string &str2);

class Operation
{
    string name;
    string symbol;

    public:

    Operation(const string &name, const string &symbol)
    {
        if(name == "")
        {
            throw invalid_argument("name must not be empty");
        }
        if(symbol == "")
        {
            throw invalid_argument("symbol must not be empty");
        }
        this->name = name;
        this->symbol = symbol;
    }
    Operation(const Operation &other)
    {
        this->name = other.name;
        this->symbol = other.symbol;
    }
    Operation &operator=(const Operation& other)
    {
        if(this != &other)
        {
            this->name = other.name;
            this->symbol = other.symbol;
        }
        return *this;
    }

    virtual double execute(const double a, const double b) const = 0;

    string getName() const
    {
        return this->name;
    }

    string getSymbol() const
    {
        return this->symbol;
    }

    void setName(const string& name) 
    {
        if(name == "")
        {
            throw invalid_argument("name must not be empty");
        }
        this->name = name;
    }

    void setSymbol(const string& symbol)
    {
        if(symbol == "")
        {
            throw invalid_argument("symbol must not be empty");
        }
        this->symbol = symbol;
    }

    virtual Operation * getOperation() const = 0;

    
};

class AddOperation: public Operation
{
    public:
    AddOperation(const string &name, const string &symbol) 
    :Operation(name, symbol)
    {

    }

    AddOperation(const AddOperation& other)
    :Operation(other)
    {

    }

    AddOperation& operator=(const AddOperation& other)
    {
        if(this != &other)
        {
            Operation::operator=(other);
        }
        return *this;
    }

    double execute(const double a, const double b) const override
    {
        return a+b;
    }

    Operation * getOperation() const override
    {
        return new AddOperation(*this);
    }
};

class SubstractOperation: public Operation
{
    public:
    SubstractOperation(const string &name, const string &symbol) 
    :Operation(name, symbol)
    {

    }

    SubstractOperation(const SubstractOperation& other)
    :Operation(other)
    {

    }

    SubstractOperation& operator=(const SubstractOperation& other)
    {
        if(this != &other)
        {
            Operation::operator=(other);
        }
        return *this;
    }

    double execute(const double a, const double b) const override
    {
        return a-b;
    }

    Operation * getOperation() const override
    {
        return new SubstractOperation(*this);
    }
};

class MultiplyOperation: public Operation
{
    public:
    MultiplyOperation(const string &name, const string &symbol) 
    :Operation(name, symbol)
    {

    }

    MultiplyOperation(const MultiplyOperation& other)
    :Operation(other)
    {

    }

    MultiplyOperation& operator=(const MultiplyOperation& other)
    {
        if(this != &other)
        {
            Operation::operator=(other);
        }
        return *this;
    }

    double execute(const double a, const double b) const override
    {
        return a*b;
    }

    Operation * getOperation() const override
    {
        return new MultiplyOperation(*this);
    }
};

class DivideOperation: public Operation
{
    public:
    DivideOperation(const string &name, const string &symbol) 
    :Operation(name, symbol)
    {

    }

    DivideOperation(const DivideOperation& other)
    :Operation(other)
    {

    }

    DivideOperation& operator=(const DivideOperation& other)
    {
        if(this != &other)
        {
            Operation::operator=(other);
        }
        return *this;
    }

    double execute(const double a, const double b) const override
    {
        if(b == 0)
        {
            throw invalid_argument("you cannot divide by 0");
        }
        return a/b;
    }
    
    Operation * getOperation() const override
    {
        return new DivideOperation(*this);
    }
};

class PowerOperation: public Operation
{
    public:
    PowerOperation(const string &name, const string &symbol) 
    :Operation(name, symbol)
    {

    }

    PowerOperation(const PowerOperation& other)
    :Operation(other)
    {

    }

    PowerOperation& operator=(const PowerOperation& other)
    {
        if(this != &other)
        {
            Operation::operator=(other);
        }
        return *this;
    }

    double execute(const double a, const double b) const override
    {
        if(a == 0 && b <= 0)
        {
            throw invalid_argument("you can't raise 0 to the 0th power or negative power");
        }
        int b1 = b;
        return pow(a, b1);
        
    }
    
    Operation * getOperation() const override
    {
        return new PowerOperation(*this);
    }
};

class RootOperation: public Operation
{
    public:
    RootOperation(const string &name, const string &symbol) 
    :Operation(name, symbol)
    {

    }

    RootOperation(const RootOperation& other)
    :Operation(other)
    {

    }

    RootOperation& operator=(const RootOperation& other)
    {
        if(this != &other)
        {
            Operation::operator=(other);
        }
        return *this;
    }

    double execute(const double a, const double b) const override
    {
        int b1 = b;
        if(a < 0 && b1 % 2 == 0)
        {
            throw invalid_argument("the radicand cant be negative number when the root index is even number");
        } 
        if(b <= 0)
        {
            throw invalid_argument("the index of the root cant be 0 or negative");
        }
        if(a < 0 && b1 % 2 != 0)
        {
            return pow(-1*a, 1.0/b) *-1;
        }
        return pow(a, 1.0/b);
    }
    
    Operation * getOperation() const override
    {
        return new RootOperation(*this);
    }
};

class Calculator
{
    const char * name;
    size_t numberOfSupportedOperations;
    size_t capacityForOperations;
    Operation ** operations;
    static double numberOfSuccessfullCalculations;

    public:

    Calculator()
    :name(new char[1])
    {
        this->numberOfSupportedOperations = 0;
        this->capacityForOperations = 2;
        this->operations = new Operation*[capacityForOperations];
         
    }

    Calculator(const char* name, size_t n, Operation** ops)
    {
        if(!strcmp(name, "") || name == nullptr)
        {
            throw invalid_argument("name must not be empty or null pointer");
        }
        this->name = strdup(name);
        this->numberOfSupportedOperations = n;
        this->capacityForOperations = n*2;
        this->operations = new Operation *[capacityForOperations];
        for(int i = 0; i<this->numberOfSupportedOperations; i++)
        {
            this->operations[i] = ops[i]->getOperation();
        }
    }

    Calculator(const Calculator& other)
    {
        this->name = strdup(other.name);
        this->capacityForOperations = other.capacityForOperations;
        this->numberOfSupportedOperations = other.numberOfSupportedOperations;
        this->operations = new Operation *[capacityForOperations];
        for(int i = 0; i < this->numberOfSupportedOperations; i++)
        {
            this->operations[i] = other.operations[i]->getOperation();
        }
        this->numberOfSuccessfullCalculations = other.numberOfSuccessfullCalculations;
    }

    const Calculator& operator=(const Calculator& other)
    {
        if(this != &other)
        {
            delete []this->name;    
            for(int i = 0; i <this->capacityForOperations; i++)
            {
                delete this->operations[i];
            }
            delete []this->operations;
            this->name = strdup(other.name);
            this->capacityForOperations = other.capacityForOperations;
            this->numberOfSupportedOperations = other.numberOfSupportedOperations;
            this->operations = new Operation *[capacityForOperations];
            for(int i = 0; i < this->numberOfSupportedOperations; i++)
            {
                this->operations[i] = other.operations[i]->getOperation();
            }
            
        }
        return *this;
    }

    ~Calculator()
    {
        delete []this->name;
        for(int i = 0; i <this->numberOfSupportedOperations; i++)
        {
            delete this->operations[i];
        }
        delete []this->operations;
    }

    double getNumberOfSuccessfullCalculations() const
    {
        return this->numberOfSuccessfullCalculations;
    }

    void SupportedOperations() const
    {
        for(int i = 0; i<this->numberOfSupportedOperations; i++)
        {
            cout << "<" << this->operations[i]->getSymbol() << "> - <" << this->operations[i]->getName() << ">" << endl;    
        }
    }

    size_t getNumberOfSupportedOperations() const
    {
        return this->numberOfSupportedOperations;
    }

    size_t getCapacityForOperations() const
    {
        return this->capacityForOperations;
    }

    const char * getCalculatorName() const
    {
        return this->name;
    }

    Calculator& AddOperation(const Operation* op)
    {
        for(int i = 0; i<this->numberOfSupportedOperations;i++)
        {
            if(this->operations[i]->getName() == op->getName())
            {
                throw invalid_argument("this operation name already exist");
            }
            if(this->operations[i]->getSymbol() == op->getSymbol())
            {
                throw invalid_argument("this operation symbol already exist");
            }
        }
        if(this->capacityForOperations == this->numberOfSupportedOperations)
        {
            this->capacityForOperations *= 2;
            Operation ** tempt = new Operation*[this->capacityForOperations];
            for(int i = 0; i<numberOfSupportedOperations;i++)
            {
                tempt[i] = this->operations[i];
            }
            delete[] this->operations;
            tempt[this->numberOfSupportedOperations] = op->getOperation();
            this->operations = tempt;
            this->numberOfSupportedOperations++;
        }
        else
        {
            this->operations[this->numberOfSupportedOperations] = op->getOperation();
            this->numberOfSupportedOperations++;
        }

        
        return *this;
    }

    void listInputFormat()
    {
        cout << "<num1> <symbol> <num2> ... <numN> =" << endl;
    }

    void startCalculation()
    {

    string input;
    getline(cin, input);

    int pos = 0;
    string first, rest;
    readLine(input, first, rest);  

    double result;
    try 
    {
        result = stod(first);  
    } 
    catch (exception& e) 
    {
        cout << "Invalid number" << endl;         
        cin.ignore();
        return;
    }

    while(true)
    {
        if(rest.empty())
        {
            cout << "Missing = at the end" << endl;
            cin.ignore();
            return;
        }

        string symbol, remaining;
        readLine(rest, symbol, remaining);  

        if (symbol == "=")
        {
            cout << result << endl;             
            cin.ignore();
            return;
        }

        string nStr, newRest;
        readLine(remaining, nStr, newRest);  

        double n;
        try 
        {
            n = stod(nStr);
        } 
        catch (exception& e) 
        {
            cout << "Invalid number" << endl;           
            cin.ignore();
            return;
        }

        Operation* currentOperation = nullptr;
        for(size_t i = 0; i < numberOfSupportedOperations; ++i)
        {
            if (operations[i]->getSymbol() == symbol)
            {
                currentOperation = operations[i];
                break;
            }
        }

        if(!currentOperation)
        {
            cout << "this operation is not supported <" << symbol << ">" << endl;            
            cin.ignore();
            return;
        }

        try 
        {
            result = currentOperation->execute(result, n);
            numberOfSuccessfullCalculations++;
        } 
        catch(exception& e) 
        {
            cout << e.what() << endl;          
            cin.ignore();
            return;
        }

        rest = newRest;
    }

    }
};

double Calculator::numberOfSuccessfullCalculations = 0;

void readLine(string& input, string &str1, string &str2)
{
    int i = 0;

    while(i < input.length() && input[i] != ' ')
    {
        str1 += input[i];
        i++;
    }

    while(i < input.length() && (input[i] == ' '))
    {
        i++;
    }

    while(i < input.length())
    {
        str2 += input[i];
        i++;
    }

}

int main()
{
    char * calculatorName = new char[100];
    int numOperations;
    cout << "Enter Calculators name: ";
    cin >> calculatorName;
    cin.ignore();
    do
    {
        cout << endl << "Enter number of supported operations: "; 
        cin >> numOperations;
        if(numOperations <= 0)
            cout << "Number of operations must be positive number" << endl;
        else if(numOperations > 6)
            cout << "Number of operations cant be more than 6" << endl;
    } 
    while(numOperations <= 0 || numOperations > 6);
    cin.ignore();
    cout << "Enter operations: " << endl << "<operation symbol> <operation name>" << endl;
    Operation ** operations = new Operation*[numOperations];
    Calculator * calculator = new Calculator(calculatorName, 0, operations);
    for(int i = 0; i < numOperations; i++)
    {
        string input;
        getline(cin, input);
        string symbol, name;
        readLine(input, symbol, name);
        if(symbol == "+")
        {
            try
            {
                calculator->AddOperation(new AddOperation(name, symbol));
            }
            catch(exception& e)
            {
                cout << e.what() << endl;
                i--;
            }
        }
        else if(symbol == "-")
        {
            try
            {
                calculator->AddOperation(new SubstractOperation(name, symbol));
            }
            catch(exception& e)
            {
                cout << e.what() << endl;
                i--;
            }
        }
        else if(symbol == "*")
        {
            try
            {
                calculator->AddOperation(new MultiplyOperation(name, symbol));
            }
            catch(exception& e)
            {
                cout << e.what() << endl;
                i--;
            }
        }
        
        else if(symbol == "/")
        {
            try
            {
                calculator->AddOperation(new DivideOperation(name, symbol));
            }
            catch(exception& e)
            {
                cout << e.what() << endl;
                i--;
            }
        }
        
        else if(symbol == "^" || symbol == "**")
        {
            try
            {
                calculator->AddOperation(new PowerOperation(name, symbol));
            }
            catch(exception& e)
            {
                cout << e.what() << endl;
                i--;
            }
        }
        else if(symbol == "V")
        {
           try
            {
                calculator->AddOperation(new RootOperation(name, symbol));
            }
            catch(exception& e)
            {
                cout << e.what() << endl;
                i--;
            }
        }
        else 
        {
            cout<<"this operation is not supported" << endl;
            i--;
        }
        
        
    } 
    while(1)
    {
        int choice;
            
        cout << "1. List supported Operations" << endl;
        cout << "2. List input format" << endl;
        cout << "3. Start calculation" << endl;
        cout << "4. Exit" << endl;
        cin >> choice;
        cin.ignore();
        if(choice == 1)
        {
            calculator->SupportedOperations();
        }
        else if(choice == 2)
        {
            calculator->listInputFormat();
        }
        else if(choice == 3)
        {
            calculator->startCalculation();
        }
        else if(choice == 4)
        {
            break;
        }
        else
        {
            cout << "Invalid choice" << endl;
        }
    } 
    delete calculator;
    delete[] operations;
    delete[] calculatorName;
    return 0;

}

          