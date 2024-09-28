#include <iostream>
#include <string>
#include <algorithm> 

int main()
{
    std::string hello{"Hello World"};

    auto res = std::find(std::cbegin(hello), std::cend(hello), 'l');

    if (res != std::cend(hello))
    {
        std::cout << "index: " << std::distance(hello.cbegin(), res) << std::endl;
    }
}