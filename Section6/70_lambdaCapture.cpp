#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<std::string> names = { "Dilbert", "PHB", "Dogbert", "Asok", "Ted", "Alice", "Wally" };

    const std::size_t n { 5 };

    if (auto res = std::find_if(std::cbegin(names), std::cend(names), [n](const std::string& str)
                                {
                                    return str.size() < n;
                                });
        res != std::end(names)) // Lambda captures local variable n
    {
        std::cout << *res << std::endl;
    }

    if (auto res = std::find_if_not(std::cbegin(names), std::cend(names), [n](const std::string& str)
                                    {
                                        return str.size() < n;
                                    });
        res != std::end(names))
    {
        std::cout << *res << std::endl;
    }

    int index{-1};
    if (auto res = std::find_if(std::cbegin(names), std::cend(names), [n, &index](const std::string& str) mutable
                                {
                                    ++index;
                                    return str.size() < n;
                                });
        res != std::end(names)) // If want local variable to be revised, should add keyword mutable and pass by reference
    {
        std::cout << *res << std::endl;
    }

    std::cout << index << std::endl;
}