#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

extern "C"
{
#include "array.h"
}

int main()
{
    std::map<int, int> mp { { 1, 2 }, { 2, 4 }, { 4, 8 } };
    std::vector<int>   keys;
    std::vector<int>   values;

    for (const auto el : mp)
    {
        keys.push_back(el.first);
        values.push_back(el.second);
    }

    std::cout << "Calling C function to print keys: ";
    printArray(keys.data(), keys.size());
    std::cout << "Calling C function to print values: ";
    printArray(values.data(), values.size());
}