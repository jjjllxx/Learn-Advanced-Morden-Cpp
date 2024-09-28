#include <iostream>

class Base
{
public:
    Base(const int i) :
        i { i }
    {
    }
    virtual void print() const
    {
        std::cout << "Name of class: Base." << std::endl;
    }

protected:
    int i;
};

class Child : public Base
{
public:
    Child(const int i) :
        Base(i)
    {
    }
    void print() const override
    {
        std::cout << "Name of class: Child." << std::endl;
    }
};

class Grandchild : public Child
{
public:
    Grandchild(const int i) :
        Child(i)
    {
    }
    void print() const override
    {
        std::cout << "Name of class: Grandchild." << std::endl;
    }
};

void printClass(const Base base)
{
    base.print();
}

void printFunc(const Base& base)
{
    base.print();
}

int main()
{
    Base       base { 1 };
    Child      child { 1 };
    Grandchild grandchild { 1 };

    std::cout << "Pass by value: " << std::endl;
    printClass(base);
    printClass(child);
    printClass(grandchild);

    std::cout << "Pass by reference: " << std::endl;
    printFunc(base);
    printFunc(child);
    printFunc(grandchild);
    return 0;
}