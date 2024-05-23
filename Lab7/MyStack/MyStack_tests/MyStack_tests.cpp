#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../../Catch2/catch.hpp"
#include "../MyStack/CMyStack.h"

TEST_CASE("Push and Top") {
    std::cout << "Test 1: push and top\n";
    CMyStack<int> stack;
    stack.Push(10);
    stack.Push(20);
    REQUIRE(stack.Top() == 20);
    stack.Push(30);
    REQUIRE(stack.Top() == 30);
    std::cout << "Test 1: push and top\n";
}

TEST_CASE("Pop") {
    std::cout << "Test 2: pop\n";

    CMyStack<int> stack;
    stack.Push(10);
    stack.Push(20);
    stack.Pop();
    REQUIRE(stack.Top() == 10);
    stack.Pop();
    REQUIRE_THROWS_AS(stack.Top(), std::out_of_range);

    std::cout << "Test 2: passed\n";
}

TEST_CASE("IsEmpty") {
    std::cout << "Test 3: IsEmpty\n";

    CMyStack<int> stack;
    REQUIRE(stack.IsEmpty());
    stack.Push(10);
    REQUIRE_FALSE(stack.IsEmpty());
    stack.Pop();
    REQUIRE(stack.IsEmpty());

    std::cout << "Test 3: passed\n";
}

TEST_CASE("Clear") {
    std::cout << "Test 4: Clear\n";

    CMyStack<int> stack;
    stack.Push(10);
    stack.Push(20);
    stack.Clear();
    REQUIRE(stack.IsEmpty());
    REQUIRE_THROWS_AS(stack.Top(), std::out_of_range);

    std::cout << "Test 4: passed\n";
}

TEST_CASE("Copy Constructor") {
    std::cout << "Test 5: Copy constructor\n";

    CMyStack<int> stack1;
    stack1.Push(10);
    stack1.Push(20);
    CMyStack<int> stack2(stack1);
    REQUIRE(stack2.Top() == 20);
    stack2.Pop();
    REQUIRE(stack2.Top() == 10);

    std::cout << "Test 5: passed\n";
}

TEST_CASE("Copy Assignment") {
    std::cout << "Test 6: Copy Assignment\n";

    CMyStack<int> stack1;
    stack1.Push(10);
    stack1.Push(20);
    CMyStack<int> stack2;
    stack2 = stack1;
    REQUIRE(stack2.Top() == 20);
    stack2.Pop();
    REQUIRE(stack2.Top() == 10);

    std::cout << "Test 6: passed\n";
}

TEST_CASE("Move Constructor") {
    std::cout << "Test 7: Move Constructor\n";

    CMyStack<int> stack1;
    stack1.Push(10);
    stack1.Push(20);
    CMyStack<int> stack2(std::move(stack1));
    REQUIRE(stack2.Top() == 20);
    stack2.Pop();
    REQUIRE(stack2.Top() == 10);
    REQUIRE(stack1.IsEmpty());

    std::cout << "Test 7: passed\n";
}

TEST_CASE("Move Assignment") {
    std::cout << "Test 8: Move Assignment\n";

    CMyStack<int> stack1;
    stack1.Push(10);
    stack1.Push(20);
    CMyStack<int> stack2;
    stack2 = std::move(stack1);
    REQUIRE(stack2.Top() == 20);
    stack2.Pop();
    REQUIRE(stack2.Top() == 10);
    REQUIRE(stack1.IsEmpty());

    std::cout << "Test 8: passed\n";
}

TEST_CASE("String Stack") {
    std::cout << "Test 9: String stack\n";

    CMyStack<std::string> stack;
    stack.Push("Some");
    stack.Push("String");
    REQUIRE(stack.Top() == "String");
    stack.Pop();
    REQUIRE(stack.Top() == "Some");
    stack.Pop();
    REQUIRE(stack.IsEmpty());

    std::cout << "Test 9: passed\n";
}