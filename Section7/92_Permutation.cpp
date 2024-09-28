#include <algorithm>
#include <iostream>
#include <string>

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
    std::string str { "abc" };
    std::vector<char> vec = {'a', 'b', 'c'};

    std::cout << "The permutation of " << str << " are: " << std::endl;

    do
    {
        std::cout << str << std::endl;
    } while (std::next_permutation(std::begin(str), std::end(str)));

    do
    {
        printVec(vec);
    } while (std::next_permutation(std::begin(vec), std::end(vec)));
}