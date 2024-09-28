#include <iostream>

// x = 42, y = 99, z = 145

int main()
{
    int x { 42 }, y { 99 }, z { 0 };

    auto lam = [=, &z]() mutable
    {
        ++x;
        ++y;
        z = x + y;
    };

    lam();

    std::cout << "x = " << x
              << ", y = " << y
              << ", z = " << z
              << std::endl;

    lam();

    std::cout << "x = " << x
              << ", y = " << y
              << ", z = " << z
              << std::endl;

    x = 5;
    y = 6;

    lam();

    std::cout << "x = " << x
              << ", y = " << y
              << ", z = " << z
              << std::endl;
}