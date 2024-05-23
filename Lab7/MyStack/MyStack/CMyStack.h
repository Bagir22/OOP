#include <iostream>
#include <stdexcept>
#include <vector>
#include <utility>

template <typename T>
class CMyStack {
public:
    CMyStack() = default;

    CMyStack(const CMyStack& other) : stack(other.stack) {}

    CMyStack& operator = (const CMyStack& other) 
    {
        if (this != &other) {
            CMyStack temp(other);
            std::swap(stack, temp.stack);
        }
        return *this;
    }

    CMyStack(CMyStack&& other) noexcept : stack(std::move(other.stack)) {}

    CMyStack& operator=(CMyStack&& other) noexcept 
    {
        if (this != &other) 
        {
            stack = std::move(other.stack);
        }
        return *this;
    }


    ~CMyStack() noexcept
    {
        stack.clear();
    }

    void Push(const T& element) 
    {
        stack.push_back(element);
    }

    void Pop() 
    {
        if (stack.empty()) 
        {
            throw std::out_of_range("Stack is empty");
        }
        stack.pop_back();
    }

    T& Top() 
    {
        if (stack.empty()) 
        {
            throw std::out_of_range("Stack is empty");
        }
        return stack.back();
    }

    bool IsEmpty() const noexcept
    {
        return stack.empty();
    }

    void Clear() noexcept 
    {
        stack.clear();
    }

private:
    std::vector<T> stack;
};
