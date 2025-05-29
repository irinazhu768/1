#pragma once

template<typename t>
class ilist {
public:
    virtual ~ilist() = default;

    virtual void push_front(const t& value) = 0;
    virtual void push_back(const t& value) = 0;

    virtual void pop_front() = 0;
    virtual void pop_back() = 0;

    virtual bool empty() const = 0;
    virtual int size() const = 0;

    virtual void print() const = 0;
};
