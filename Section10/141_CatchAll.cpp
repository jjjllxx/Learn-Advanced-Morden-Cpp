#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec;
    // std::cout << vec[2] <<std::endl;
    try
    {
        std::cout << vec.at(2) << std::endl;
    }
    catch (...)
    {
        std::cout << "Caught" << '\n';
    }
}  