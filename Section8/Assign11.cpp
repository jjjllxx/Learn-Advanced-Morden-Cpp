#include <iostream>
#include <map>
#include <string>
#include <vector>

int main()
{
    std::string word;

    std::map<std::string, int> mp;

    std::vector<std::pair<std::string, int>> vec;

    while (std::getline(std::cin, word))
    {
        if (word.empty() == true)
        {
            break;
        }

        vec.emplace_back(word, word.size());
        mp.insert(std::make_pair(word, word.size()));
    }

    std::cout << "elements from vector: " << std::endl;
    for (const auto& v : vec)
    {
        std::cout << v.first << ' ' << v.second << std::endl;
    }

    std::cout << "elements from map: " << std::endl;
    for (const auto& [w, s] : mp)
    {
        std::cout << w << ' ' << s << std::endl;
    }

    return 0;
}