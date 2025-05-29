#pragma once
#include "list.hpp"
#include <iostream>

template<typename t>
class mylist : public ilist<t> {
private:
    struct node {
        t data;
        node* next;
        node* prev;
        node(const t& val) : data(val), next(nullptr), prev(nullptr) {}
    };

    node* head;
    node* tail;
    int count;

public:
    mylist() : head(nullptr), tail(nullptr), count(0) {}
    ~mylist() {
        while (!empty()) {
            pop_front();
        }
    }

    void push_front(const t& value) override {
        node* new_node = new node(value);
        new_node->next = head;
        if (head != nullptr) {
            head->prev = new_node;
        }
        head = new_node;
        if (tail == nullptr) {
            tail = new_node;
        }
        count++;
    }

    void push_back(const t& value) override {
        node* new_node = new node(value);
        new_node->prev = tail;
        if (tail != nullptr) {
            tail->next = new_node;
        }
        tail = new_node;
        if (head == nullptr) {
            head = new_node;
        }
        count++;
    }

    void pop_front() override {
        if (head == nullptr) return;
        node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
        count--;
    }

    void pop_back() override {
        if (tail == nullptr) return;
        node* temp = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        delete temp;
        count--;
    }

    bool empty() const override {
        return count == 0;
    }

    int size() const override {
        return count;
    }

    void print() const override {
        node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void iterate() const {
        node* current = head;
        while (current != nullptr) {
            std::cout << "[" << current->data << "] ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};
