#include "list_impl.hpp"
#include <iostream>

int main() {
    mylist<int> lst;

    std::cout << "чи список пустий? " << (lst.empty() ? "так" : "ні") << std::endl;

    lst.push_back(10);
    lst.push_front(5);
    lst.push_back(15);
    lst.print(); // 5 10 15

    std::cout << "розмір списку: " << lst.size() << std::endl;

    lst.pop_front();
    lst.print(); // 10 15

    lst.pop_back();
    lst.print(); // 10

    std::cout << "ітерування: ";
    lst.iterate(); // [10]

    return 0;
}
