#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <random>
#include <vector>

std::vector<int> fillVecWithRandom(const int         lowerBound,
                                   const int         upperBound,
                                   const std::size_t vecSize)
{
    std::mt19937     mt;
    std::vector<int> vec(vecSize);

    std::uniform_int_distribution<int> idist(lowerBound, upperBound);

    std::generate(vec.begin(), vec.end(), [&mt, &idist]()
                  {
                      return idist(mt);
                  });

    return vec;
}

template<typename T>
void printVec(const std::vector<T>& vec)
{
    std::ostream_iterator<T> oi(std::cout, ", ");
    std::copy(vec.cbegin(), vec.cend(), oi);
    std::cout << std::endl;
}

template<typename T>
T findMaxElement(const std::vector<T>& vec)
{
    return *std::max_element(vec.cbegin(), vec.cend());
}

template<typename T>
std::size_t findMaxElementIdx(const std::vector<T>& vec)
{
    return std::distance(vec.cbegin(), std::max_element(vec.cbegin(), vec.cend()));
}

template<typename T>
T sumElements(const std::vector<T>& vec)
{
    return std::accumulate(vec.cbegin(), vec.cend(), 0);
}

std::size_t countOdd(const std::vector<int>& vec)
{
    return std::count_if(vec.cbegin(), vec.cend(), [](const int t)
                         {
                             return t & 1;
                         });
}

template<typename T>
std::vector<double> normaliseVec(const std::vector<T>& vec)
{
    const T             maxElement = findMaxElement(vec);
    std::vector<double> normalisedVec;

    std::transform(vec.cbegin(), vec.cend(), std::back_inserter(normalisedVec), [&maxElement](const T& t)
                   {
                       return 1.0 * t / maxElement;
                   });

    return normalisedVec;
}

template<typename T>
std::vector<T> sortVec(const std::vector<T>& vec)
{
    std::vector<T> sortedVec;
    std::copy(vec.cbegin(), vec.cend(), std::back_inserter(sortedVec));
    std::sort(sortedVec.begin(), sortedVec.end());

    return sortedVec;
}

template<typename T>
std::vector<T> sortVecInDesc(const std::vector<T>& vec)
{
    std::vector<T> sortedVec;
    std::copy(vec.cbegin(), vec.cend(), std::back_inserter(sortedVec));
    std::sort(sortedVec.begin(), sortedVec.end(), std::greater<T>());

    return sortedVec;
}

template<typename T>
T findFirstGreaterThan(const T&              threshold,
                       const std::vector<T>& sortedVec)
{
    if (auto it = std::upper_bound(sortedVec.cbegin(), sortedVec.cend(), threshold);
        it != sortedVec.end())
    {
        return *it;
    }
    else
    {
        std::cout << "vector does not have element greater than threshold" << std::endl;
        return -1;
    }
}

std::vector<double> copyOdd(const std::vector<int>& vec)
{
    std::vector<double> oddVec;

    std::copy_if(vec.cbegin(), vec.cend(), std::back_inserter(oddVec), [](const int t)
                 {
                     return t & 1;
                 });

    return oddVec;
}

template<typename T>
std::vector<T> shuffleVec(const std::size_t     fromIdx,
                          const std::size_t     toIdx,
                          const std::vector<T>& vec)
{
    std::mt19937 mt;

    std::vector<T> shuffledVec;
    std::copy(vec.cbegin(), vec.cend(), std::back_inserter(shuffledVec));

    const auto startIt = shuffledVec.begin() + fromIdx;
    const auto endIt   = shuffledVec.end() + toIdx - shuffledVec.size() + 1;
    std::shuffle(startIt, endIt, mt);

    return shuffledVec;
}

std::vector<int> removeOdd(const std::vector<int>& vec)
{
    std::vector<int> evenVec;
    std::copy_if(vec.cbegin(), vec.cend(), std::back_inserter(evenVec), [](const int t)
                 {
                     return !(t & 1);
                 });

    return evenVec;
}

template<typename T>
void writeToFile(std::ofstream&        ofile,
                 const std::vector<T>& vec)
{
    if (ofile.is_open() == true)
    {
        std::count_if(vec.cbegin(), vec.cend() - 1, [&ofile](const T& t)
                      {
                          ofile << t << ", ";
                          return true;
                      });

        ofile << vec.back();

        ofile.close();
    }

    std::cout << "13. Please check file even.txt" << std::endl;
}

bool hasAlpha(const std::string& str)
{
    return std::any_of(str.cbegin(), str.cend(), isalpha);
}

std::string ignorePunctAndCaps(const std::string& str)
{
    std::string newStr;
    std::copy_if(str.cbegin(), str.cend(), std::back_inserter(newStr), [](char c)
                 {
                     return !std::ispunct(c);
                 });

    std::transform(newStr.begin(), newStr.end(), newStr.begin(), [](char c)
                   {
                       return std::tolower(c);
                   });

    return newStr;
}

std::vector<std::string> extractWords(std::ifstream& ifile)
{
    const std::istream_iterator<std::string> begin { ifile };
    const std::istream_iterator<std::string> end;

    std::vector<std::string> words;
    // ignore words which do not have letters
    std::copy_if(begin, end, std::back_inserter(words), hasAlpha);
    std::transform(words.begin(), words.end(), words.begin(), ignorePunctAndCaps);

    return words;
}

void readWordsFromFile(std::ifstream& ifile)
{
    if (ifile)
    {
        const std::vector<std::string> words = extractWords(ifile);

        std::cout << "14. Words from file: ";
        std::ostream_iterator<std::string> oi(std::cout, " ");
        std::copy(words.cbegin(), words.cend(), oi);
        std::cout << std::endl;

        ifile.close();

        return;
    }

    std::cout << "14. cannot open file" << std::endl;
}

std::size_t countWordsNum(std::ifstream& ifile)
{
    if (ifile)
    {
        const std::istream_iterator<std::string> begin { ifile };
        const std::istream_iterator<std::string> end;

        std::vector<std::string> words;
        std::copy_if(begin, end, std::back_inserter(words), hasAlpha);

        std::cout << "15. Totol number of words in file: " << words.size() << std::endl;

        ifile.close();

        return words.size();
    }

    std::cout << "15. cannot open file" << std::endl;

    return 0;
}

std::size_t countLinesNum(std::ifstream& ifile)
{
    if (ifile)
    {
        const std::istreambuf_iterator<char> begin { ifile };
        const std::istreambuf_iterator<char> end;

        if (begin == end)
        {
            return 0;
        }

        const std::size_t lineNum = std::count_if(begin, end, [](const char c)
                                                  {
                                                      return c == '\n';
                                                  });

        std::cout << "16. Totol lines of file: " << lineNum + 1 << std::endl;

        ifile.close();

        return lineNum + 1;
    }

    std::cout << "16. cannot open file" << std::endl;

    return 0;
}

std::size_t countCharNum(std::ifstream& ifile)
{
    if (ifile)
    {
        const std::istreambuf_iterator<char> begin { ifile };
        const std::istreambuf_iterator<char> end;

        const std::size_t charNum = std::count_if(begin, end, [](const char c)
                                                  {
                                                      return c != '\n';
                                                  });

        std::cout << "17. Totol lines of file: " << charNum << std::endl;

        ifile.close();

        return charNum;
    }

    std::cout << "17. cannot open file" << std::endl;

    return 0;
}

void displayCommonWords(std::ifstream& ifile1,
                        std::ifstream& ifile2)
{
    if (ifile1 && ifile2)
    {
        std::vector<std::string> words1 = extractWords(ifile1);
        std::vector<std::string> words2 = extractWords(ifile2);

        std::sort(words1.begin(), words1.end());
        std::sort(words2.begin(), words2.end());

        std::vector<std::string> sharedWords;
        std::set_intersection(words1.cbegin(), words1.cend(), words2.cbegin(), words2.cend(), std::back_inserter(sharedWords));

        std::cout << "18. Common words of two files: ";
        printVec(sharedWords);

        ifile1.close();
        ifile2.close();

        return;
    }

    std::cout << "18. cannot open file" << std::endl;
}

long long calcFactorial(const int n)
{
    std::vector<int> vec(n + 1, 1);

    std::generate(vec.begin() + 1, vec.end(), [val = 1, index = 1]() mutable
                  {
                      val *= index++;
                      return val;
                  });

    return vec.back();
}

int main()
{
    // 1. Fill a vector with 10 random integers between 0 and 1000
    const std::vector<int> vec = fillVecWithRandom(0, 1000, 10);

    // 2. Print out the vector elements
    std::cout << "2. Vector elements: ";
    printVec(vec);

    // 3. Find the maximum element in this vector
    const int maxElement = findMaxElement(vec);
    std::cout << "3. Maximum element = " << maxElement << std::endl;

    // 4. Find the index of this maximum element
    const std::size_t maxElementIdx = findMaxElementIdx(vec);
    std::cout << "4. Maximum element index = " << maxElementIdx << std::endl;

    // 5. Sum the elements of the vector
    const int sum = sumElements(vec);
    std::cout << "5. Sum of elements = " << sum << std::endl;

    // 6. Count the number of odd numbers in the vector
    const std::size_t oddNum = countOdd(vec);
    std::cout << "6. Number of odd numbers = " << oddNum << std::endl;

    // 7. Normalize the vector (divide all the elements by the largest) and put the normalized elements into a vector of doubles, without setting the size of the output vector first
    const std::vector<double> normalisedVec = normaliseVec(vec);
    std::cout << "7. Normalised vector: ";
    printVec(normalisedVec);

    // 8. Make a sorted copy of the vector. Without using a functor or a lambda(or equivalent), find the first element greater than 455 and the number of elements > 455
    const std::vector<int> sortedVec = sortVec(vec);
    std::cout << "8. Sorted vector: ";
    printVec(sortedVec);
    const int firstElem = findFirstGreaterThan(455, sortedVec);
    std::cout << "8. First element greater than 455 is " << firstElem << std::endl;

    // 9. Copy all the odd numbers to a vector of doubles, without setting the size of the output vector first
    const std::vector<double> oddVec = copyOdd(vec);
    std::cout << "9. Odd vector: ";
    printVec(oddVec);

    // 10. Sort the vector in descending order
    const std::vector<int> sortedDescVec = sortVecInDesc(vec);
    std::cout << "10. Sorted descending vector: ";
    printVec(sortedDescVec);

    // 11. Randomly shuffle all but the first and the last element of the vector
    const std::vector<int> shuffledVec = shuffleVec(1, vec.size() - 2, vec);
    std::cout << "11. Shuffled vector: ";
    printVec(shuffledVec);

    // 12. Remove all the odd numbers from the vector
    const std::vector<int> evenVec = removeOdd(vec);
    std::cout << "12. Vector after odd number removed: ";
    printVec(evenVec);

    // 13. Write the remaining elements to a text file on a single line as a comma separated list, without a trailing comma
    std::ofstream ofile { "even.txt" };
    writeToFile(ofile, evenVec);

    // 14. Read a file of words and display each word once. Ignore punctuation and capitalization
    std::ifstream ifile1 { "words1.txt" };
    readWordsFromFile(ifile1);

    // 15. Count the total number of words in the file
    std::ifstream ifile2 { "words2.txt" };
    countWordsNum(ifile2);

    // 16. Count the number of lines in the file
    std::ifstream ifile3 { "words2.txt" };
    countLinesNum(ifile3);

    // 17. Count the number of characters in the file
    std::ifstream ifile4 { "words2.txt" };
    countCharNum(ifile4);

    // 18. Read two files of words and display the words which are common to both files
    std::ifstream ifile5 { "words1.txt" };
    std::ifstream ifile6 { "words2.txt" };
    displayCommonWords(ifile5, ifile6);

    // 19. Calculate the factorial of 6 (6 x 5 x 4 x ... x 1)
    std::cout << "19. factorial of 6 is " << calcFactorial(6) << std::endl;
}