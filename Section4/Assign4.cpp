#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct Language
{
    std::string lang;
    std::string designer;
    int         date;
};

Language packAsLanguage(const std::vector<std::string>& vec)
{
    Language lang;
    lang.lang = vec.front();
    lang.date = std::stoi(vec.back());

    // designer will include from the second element to the second to last element.
    auto designerStart = vec.begin() + 1;
    auto designerEnd = vec.end() - 1;

    for (auto it = designerStart; it < designerEnd; ++it)
    {
        lang.designer += *it;
        lang.designer += ' ';
    }

    lang.designer.pop_back(); // remove the last whitespace.

    return lang;
}

std::vector<Language> readLang(std::ifstream& inFile)
{
    if (inFile.is_open() == false)
    {
        std::cout << "Could not open file to read" << std::endl;

        return {};
    }

    std::string           line;
    std::vector<Language> langs;

    while (std::getline(inFile, line))
    {
        std::istringstream       is(line);
        std::vector<std::string> temp;
        std::string val;

        while (is >> val)
        {
            temp.push_back(val);
        }

        langs.push_back(packAsLanguage(temp));
    }

    inFile.close();

    return langs;
}

std::string toOutputFormat(const Language& lang)
{
    std::string outLang { lang.lang };
 
    outLang += ", ";
    outLang += lang.designer;
    outLang += ", ";
    outLang += std::to_string(lang.date);

    return outLang;
}

void writeLang(const std::vector<Language>& langs,
               std::ofstream&               outFile)
{
    if (outFile.is_open() == false)
    {
        std::cout << "Could not open file to write" << std::endl;

        return;
    }

    for (const Language& lang : langs)
    {
        outFile << toOutputFormat(lang) << std::endl;
    }

    outFile.close();
}

int main()
{
    std::ifstream               ifile { "languages2.txt" };
    const std::vector<Language> langs = readLang(ifile);

    std::ofstream ofile { "lang_out.txt" };
    writeLang(langs, ofile);

    return 0;
}