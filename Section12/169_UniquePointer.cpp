#include <iostream>
#include <memory>

void func(std::unique_ptr<int> up)
{
    std::cout << *up << std::endl;
}

int main()
{
    auto ptr { std::make_unique<int>(3) };
    func(std::move(ptr));
    std::cout << *ptr << std::endl;
}