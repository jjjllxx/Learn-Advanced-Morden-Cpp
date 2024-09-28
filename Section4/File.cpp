#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <iterator>

void readTxt(std::ifstream& ifile)
{
    if (ifile)
    {
        std::string text{""};
        while (ifile >> text)
        {
            std::cout << text << ", ";
        }

        std::cout << std::endl;

        ifile.close();
    }
}

void writeTxt(std::ofstream& ofile)
{
    if (ofile.is_open() == true)
    {
        std::vector<std::string> words = {"The", "quick", "brown", "fox", "jump", "over", "the", "lazy", "dog"};
        for (const std::string& word : words)
        {
            ofile << word << ", ";
        }   

        ofile.close();
    }
}

void getAndPut()
{
    std::cout << "Enter some text:" << std::endl;

    char c;

    while (std::cin.get(c))
    {
        std::cout.put(c);
    }

}

void appendFile()
{
    std::ofstream ofile;
    ofile.open("important.txt", std::fstream::app);

    if (!ofile)
    {
        std::cout << "Could not open the file\n";
    }

    ofile << "some more data";
    ofile.close();
}

void enterANumber()
{
    int x{0};

    std::cout << "Please enter a number" << std::endl;
    std::cin >> x; 

    if (std::cin.good())
    {
        std::cout << "Number " << x << std::endl;
    }
    else if (std::cin.fail())
    {
        std::cout << "Please try again to enter a number." << std::endl;
    }
    else if (std::cin.bad())
    {
        std::cout << "Seriously wrong" << std::endl;
    }
}

template<typename T>
std::string toString(const T& t)
{
    std::ostringstream os;
    os << t;
    return os.str();
}

void useIter()
{
    std::cout << "Please enter a num: " << std::endl;

    std::istream_iterator<int> ii(std::cin);

    int x = *ii;

    std::cout << "You entered " << x << std::endl;
}

int main()
{
    // std::ifstream ifile{"text.txt"};
    // readTxt(ifile);

    // std::ofstream ofile{"text_out.txt"};
    // writeTxt(ofile);

    // getAndPut();
    // appendFile();

    // enterANumber();

    useIter();

    return 0;
}