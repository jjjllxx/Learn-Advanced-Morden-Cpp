#include <iostream>

int main()
{
    int  y = 1;

    auto lam = [y = y + 1](int x)
    {
        return x + y;
    };

    std::cout << "Result: " << lam(5) << std::endl;
    std::cout << "y = " << y << std::endl;
}