#include <iostream>
#include <vector>
#include <algorithm>

bool isShorter(const std::string& lhs,
               const std::string& rhs)
{
    return lhs.size() < rhs.size();
}

bool longerThan5(const std::string& str)
{
    return str.size() > 5;
}

class LongerThanN
{
private:
    const std::size_t n;
public:
    LongerThanN(const std::size_t n) :
        n(n) {};

    bool operator()(const std::string& str)
    {
        return str.size() > this->n;
    }
};


int main()
{
    std::vector<std::string> names = { "Dilbert", "PHB", "Dogbert", "Asok", "Ted", "Alice", "Wally" };

    std::sort(std::begin(names), std::end(names), isShorter);

    for (const std::string& str : names)
    {
        std::cout << str << " ";
    }

    std::cout << std::endl;

    if (auto res = std::find_if(std::cbegin(names), std::cend(names), longerThan5);
        res != std::end(names))
    {
        std::cout << *res << std::endl;
    }

    if (auto res = std::find_if_not(std::cbegin(names), std::cend(names), LongerThanN(4));
        res != std::end(names))
    {
        std::cout << *res << std::endl;
    }
}