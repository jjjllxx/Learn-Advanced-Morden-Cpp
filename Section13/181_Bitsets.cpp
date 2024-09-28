#include <bitset>
#include <iostream>

int main()
{
    std::bitset<8> b1 { "10101110" };
    std::cout << "b1: " << b1 << std::endl;

    std::bitset<8> b2 { 0xae };
    std::cout << "b2: " << b2 << std::endl;

    std::bitset<8> b3 { 0b1010'1110 };
    std::cout << "b3: " << b3 << std::endl;

    std::cout << "~b1: " << ~b1 << std::endl;
    std::cout << "b1 | b2: " << (b1 | b2) << std::endl;
    std::cout << "b1 << 1: " << (b1 << 1) << std::endl;
}