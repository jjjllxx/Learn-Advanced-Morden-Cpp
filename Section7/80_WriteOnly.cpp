#include <algorithm>
#include <iostream>
#include <vector>

class Square
{
private:
    int n { 0 };

public:
    int operator()()
    {
        ++n;
        return n * n;
    }
};

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
    std::vector<int> vec(10);
    printVec(vec);

    std::generate(std::begin(vec), std::end(vec), Square());
    printVec(vec);
}