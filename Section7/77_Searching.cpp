#include <algorithm>
#include <iostream>
#include <string>

int main()
{
    std::string str{"Hello world"};
    std::string vowels{"aeiou"};

    auto firstVowel = std::find_first_of(std::cbegin(str), std::cend(str), std::cbegin(vowels), std::cend(vowels));

    if (firstVowel != std::cend(str))
    {
        std::cout << "First vowel is " << *firstVowel << " at index " << std::distance(std::cbegin(str), firstVowel) <<std::endl;
    }

    if (auto secondVowel = std::find_first_of(std::next(firstVowel), std::cend(str), std::cbegin(vowels), std::cend(vowels));
        secondVowel != std::cend(str))
    {
        std::cout << "Second vowel is " << *secondVowel << " at index " << std::distance(std::cbegin(str), secondVowel) << std::endl;
    }

    // std::adjacent_find()
    // std::search_n()
    // std::search()
}