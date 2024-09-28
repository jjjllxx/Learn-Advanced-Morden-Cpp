#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <string>
#include <vector>

template<typename T>
void printVec(const std::vector<T>& vec)
{
    std::cout << "Vector elements: ";
    for (const T& v : vec)
    {
        std::cout << v << ", ";
    }

    std::cout << std::endl;
}

template<typename T>
void printList(const std::list<T>& list)
{
    std::cout << "List   elements: ";
    for (const T& v : list)
    {
        std::cout << v << ", ";
    }

    std::cout << std::endl;
}

template<typename T>
void printDeque(const std::deque<T>& deque)
{
    std::cout << "Deque  elements: ";
    for (const T& v : deque)
    {
        std::cout << v << ", ";
    }

    std::cout << std::endl;
}

int main()
{
    std::vector<std::string> vec;
    std::list<std::string>   list;
    std::deque<std::string>  deque;

    std::string input;

    while (std::getline(std::cin, input))
    {
        if (input.empty() == true)
        {
            break;
        }

        vec.push_back(input);
        list.push_back(input);
        deque.push_back(input);
    }

    printVec(vec);
    printList(list);
    printDeque(deque);

    // reverse 
    list.reverse();
    std::reverse(deque.begin(), deque.end());

    printList(list);
    printDeque(deque);

    return 0;
}