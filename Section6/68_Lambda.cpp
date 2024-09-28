#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<std::int32_t> vec{3, 1, 4, 5, 9, 2 ,6};

    auto oddIt = std::find_if(std::cbegin(vec), std::cend(vec), [](const std::int32_t n){return (n % 2 == 1); });

    if (auto oddIt = std::find_if(std::cbegin(vec), std::cend(vec), [](const std::int32_t n)
                                  {
                                      return n % 2 == 1;
                                  });
                                  oddIt != std::cend(vec))
    {
        std::cout << *oddIt <<std::endl;
    }
}