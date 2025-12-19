#include <iostream>
#include <stdexcept>
#include "linked_list.hpp"

void check(bool cond, const char* msg) {
    if (!cond) throw std::runtime_error(msg);
}

// 1
void test_empty() {
    linked_list<int> l;
    check(l.empty(), "List should be empty");
}

// 2
void test_push_front() {
    linked_list<int> l;
    l.push_front(1);
    check(l.size() == 1, "Size should be 1");
}

// 3
void test_push_back() {
    linked_list<int> l;
    l.push_back(5);
    check(l.size() == 1, "Size should be 1");
}

// 4
void test_pop_front() {
    linked_list<int> l;
    l.push_front(1);
    l.pop_front();
    check(l.empty(), "List should be empty");
}

// 5
void test_pop_back() {
    linked_list<int> l;
    l.push_back(1);
    l.pop_back();
    check(l.empty(), "List should be empty");
}

// 6
void test_multiple_push() {
    linked_list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    check(l.size() == 3, "Size should be 3");
}

// 7
void test_mixed_push() {
    linked_list<int> l;
    l.push_front(1);
    l.push_back(2);
    check(l.size() == 2, "Size should be 2");
}

// 8
void test_pop_middle() {
    linked_list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.pop_back();
    check(l.size() == 1, "Size should be 1");
}

// 9
void test_clear_like() {
    linked_list<int> l;
    l.push_back(1);
    l.pop_front();
    check(l.empty(), "List should be empty");
}

// 10
void test_many_ops() {
    linked_list<int> l;
    for (int i = 0; i < 10; ++i) l.push_back(i);
    for (int i = 0; i < 5; ++i) l.pop_front();
    check(l.size() == 5, "Size should be 5");
}

int main() {
    try {
        test_empty();
        test_push_front();
        test_push_back();
        test_pop_front();
        test_pop_back();
        test_multiple_push();
        test_mixed_push();
        test_pop_middle();
        test_clear_like();
        test_many_ops();

        std::cout << "ALL TESTS PASSED\n";
    } catch (const std::exception& e) {
        std::cout << "TEST FAILED: " << e.what() << "\n";
    }
}
