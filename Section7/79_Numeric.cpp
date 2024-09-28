#include <numeric>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec = {3, 1, 4, 1, 5, 9, 2, 6};

    int sum = std::accumulate(std::cbegin(vec), std::cend(vec), 0);
    int newSum = std::accumulate(std::cbegin(vec), std::cend(vec), 0, [](const int sum, const int n)
                              {
                                  return n % 2 == 1
                                             ? sum + n
                                             : sum;
                              });

    std::cout << "sum: " << sum
              << " new sum: " << newSum << std::endl;

    // std::reduce() : same result but support parallel computing, more efficient
}