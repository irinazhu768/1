#include <iostream>
#include <stdexcept>
#include "list.hpp"

int passed = 0;
int failed = 0;

void check(bool cond, const char* msg) {
    if (!cond) throw std::runtime_error(msg);
}

// 1
void test_empty_list() {
    List list;
    check(list.empty(), "List should be empty");
}

// 2
void test_push_front() {
    List list;
    list.push_front(1);
    check(!list.empty(), "List not empty");
}

// 3
void test_push_back() {
    List list;
    list.push_back(2);
    check(!list.empty(), "List not empty");
}

// 4
void test_pop_front() {
    List list;
    list.push_front(1);
    list.pop_front();
    check(list.empty(), "List empty after pop");
}

// 5
void test_clear() {
    List list;
    list.push_back(1);
    list.push_back(2);
    list.clear();
    check(list.empty(), "List cleared");
}

// 6
void test_size() {
    List list;
    list.push_back(1);
    list.push_back(2);
    check(list.size() == 2, "Size is 2");
}

// 7
void test_front() {
    List list;
    list.push_front(5);
    check(list.front() == 5, "Front is 5");
}

// 8
void test_back() {
    List list;
    list.push_back(7);
    check(list.back() == 7, "Back is 7");
}

// 9
void test_multiple_push() {
    List list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    check(list.size() == 3, "Three elements");
}

// 10
void test_pop_back() {
    List list;
    list.push_back(1);
    list.pop_back();
    check(list.empty(), "Empty after pop_back");
}

int main() {
    try { test_empty_list(); passed++; } catch(...) { failed++; }
    try { test_push_front(); passed++; } catch(...) { failed++; }
    try { test_push_back(); passed++; } catch(...) { failed++; }
    try { test_pop_front(); passed++; } catch(...) { failed++; }
    try { test_clear(); passed++; } catch(...) { failed++; }
    try { test_size(); passed++; } catch(...) { failed++; }
    try { test_front(); passed++; } catch(...) { failed++; }
    try { test_back(); passed++; } catch(...) { failed++; }
    try { test_multiple_push(); passed++; } catch(...) { failed++; }
    try { test_pop_back(); passed++; } catch(...) { failed++; }

    std::cout << "Passed: " << passed << "\n";
    std::cout << "Failed: " << failed << "\n";
    return 0;
}
