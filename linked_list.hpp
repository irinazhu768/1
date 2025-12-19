#pragma once
#include "ilist.hpp"
#include <iostream>

template<typename t>
class linked_list : public ilist<t> {
    struct node {
        t value;
        node* next;
        node(const t& v) : value(v), next(nullptr) {}
    };

    node* head = nullptr;
    node* tail = nullptr;
    int count = 0;

public:
    ~linked_list() override {
        while (!empty()) pop_front();
    }

    void push_front(const t& value) override {
        node* n = new node(value);
        n->next = head;
        head = n;
        if (!tail) tail = n;
        ++count;
    }

    void push_back(const t& value) override {
        node* n = new node(value);
        if (tail) tail->next = n;
        else head = n;
        tail = n;
        ++count;
    }

    void pop_front() override {
        if (!head) return;
        node* tmp = head;
        head = head->next;
        delete tmp;
        if (!head) tail = nullptr;
        --count;
    }

    void pop_back() override {
        if (!head) return;
        if (head == tail) {
            delete head;
            head = tail = nullptr;
            count = 0;
            return;
        }
        node* cur = head;
        while (cur->next != tail) cur = cur->next;
        delete tail;
        tail = cur;
        tail->next = nullptr;
        --count;
    }

    bool empty() const override {
        return count == 0;
    }

    int size() const override {
        return count;
    }

    void print() const override {
        node* cur = head;
        while (cur) {
            std::cout << cur->value << " ";
            cur = cur->next;
        }
        std::cout << "\n";
    }
};
