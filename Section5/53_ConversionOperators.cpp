#include <iostream>
#include <string>

class Test {
    int i;
    std::string str;
public:
    Test():
        i(1),
        str("")
    {
    }

    explicit operator int() const 
    {
        return i;    
    }

    explicit operator bool() const
    {
        return i;
    }
};

int main()
{
    Test test;
    std::cout << static_cast<int>(test) + 5 << std::endl;

    if (test)
    {
        std::cout << "This is allowed!" << std::endl;
    }
}