#include <algorithm>
#include <iostream>
#include <list>
#include <string>

class URL
{
    std::string protocol;
    std::string resource;

public:
    URL(const std::string& prot,
        const std::string& res);
    void print() const;
    bool operator==(const URL& url) const;
};

URL::URL(const std::string& prot,
         const std::string& res)
{
    protocol = prot;
    resource = res;
}

void URL::print() const
{
    std::cout << protocol << "://" << resource << "\n";
}

bool URL::operator==(const URL& url) const
{
    return protocol == url.protocol && resource == url.resource;
}

class URLHistory
{
    std::list<URL> history;

public:
    URLHistory() = default;
    void updateHistory(const URL& url);
    void printHistory() const;
};

void URLHistory::updateHistory(const URL& url)
{
    if (auto it = std::find(history.begin(), history.end(), url);
        it != history.end())
    {
        history.erase(it);
    }

    history.push_front(url);
}

void URLHistory::printHistory() const
{
    std::cout << "Current has " << history.size() << " lists of histroy: " << std::endl;

    for (const URL& url : history)
    {
        url.print();
    }

    std::cout << std::endl;
}

int main()
{
    URLHistory urlHistory;

    URL url1 { "https", "1.com" };
    URL url2 { "https", "2.com" };
    URL url3 { "https", "3.com" };
    URL url4 { "https", "4.com" };

    urlHistory.updateHistory(url1);
    urlHistory.updateHistory(url2);
    urlHistory.updateHistory(url3);
    urlHistory.printHistory();

    urlHistory.updateHistory(url2);
    urlHistory.printHistory();

    urlHistory.updateHistory(url3);
    urlHistory.printHistory();

    urlHistory.updateHistory(url4);
    urlHistory.printHistory();
}