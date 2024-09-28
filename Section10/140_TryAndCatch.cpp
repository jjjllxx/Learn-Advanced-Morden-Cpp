#include <iostream>
#include <vector>

int main()
{
    // std::cout << vec[2] <<std::endl;
    try
    {
        std::vector<int> vec;
        std::cout << vec.at(2) << std::endl;
    }
    catch (const std::out_of_range& e)
    {
        std::cout << "out_of_range" << '\n';
    }
    catch (const std::exception& e)
    {
        std::cout << "exception" << '\n';
    }
}