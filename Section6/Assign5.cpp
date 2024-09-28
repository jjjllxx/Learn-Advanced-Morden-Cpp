#include <iostream>
#include <vector>
#include <algorithm>

void printVec(const std::vector<int>& vec)
{
    for (const int i : vec)
    {
        std::cout << i << " ";
    }

    std::cout << std::endl;
}

int main()
{
    std::vector<int> vec = {3, 1, 4, 1, 5, 9, 2, 6};

    std::cout << " Vector before sort: ";
    printVec(vec);

    std::sort(std::begin(vec), std::end(vec), [](const int a, const int b)
              {
                  return a > b;
              });

    std::cout << " Vector after sort: ";
    printVec(vec);
}