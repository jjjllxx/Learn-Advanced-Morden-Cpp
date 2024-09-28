#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

template<typename T>
void printVec(const std::vector<T>& vec)
{
    for (const T& i : vec)
    {
        std::cout << i << " ";
    }

    std::cout << std::endl;
}

int main()
{
    std::vector<std::string> names = { "Dilbert", "PHB", "Dogbert", "Asok", "Ted", "Alice", "Wally" };

    printVec(names);

    std::sort(std::begin(names), std::end(names), std::greater<std::string>());

    printVec(names);

    std::sort(std::begin(names), std::end(names), std::less<std::string>());

    printVec(names);
}