#include <string>
#include <iostream>

class MyString
{
    char* data;
    std::size_t size;

public:
    MyString(const std::string& s) :
        size(s.size())
    {
        std::cout << "Calling constructor" << std::endl;

        this->data = new char[this->size];
        for (int i = 0; i < this->size; ++i)
        {
            this->data[i] = s[i];
        }
    }

    MyString(const MyString& myStr) :
        size(myStr.length())
    {
        std::cout << "Calling copy constructor" << std::endl;
    
        this->data = new char[this->size];
        for (int i = 0; i < this->size; ++i)
        {
            this->data[i] = myStr.data[i];
        }
        
    }

    MyString& operator=(const MyString& myStr)
    {
        std::cout << "Calling assignment operator" << std::endl;

        if (&myStr != this) // Check for self-assignment
        {
            delete[] this->data;
            this->data = new char[myStr.length()];
            this->size = myStr.length();

            for (int i = 0; i < this->size; ++i)
            {
                this->data[i] = myStr.data[i];
            }
        }

        return *this;
    }

    ~MyString()
    {
        std::cout << "Calling destructor" << std::endl;
        delete [] this->data;
    }

    std::size_t length() const
    {
        return this->size;
    }
};


int main()
{
    MyString str("1");
    MyString str2("Two");
    MyString str3(str2);

    std::cout << "Str2 size: " << str2.length() << std::endl;
    std::cout << "Str3 size: " << str3.length() << std::endl;
    std::cout << "Str size: " << str.length() << std::endl;

    str2 = str3;
    std::cout << "Str2 size: " << str2.length() << std::endl;
}

