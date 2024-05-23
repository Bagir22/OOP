#include <iostream>
#include "CMyStack.h"
#include "iostream"

const std::string IntStackExample = "Integer stack example";
const std::string StringStackExample = "String stack example";

const std::string InitStack = "Init stack: Is emtpy(result): ";
const std::string PushOne = "After stack push one element: ";
const std::string PushTwo = "After stack push two elements: ";
const std::string Pop = "After stack pop one element: ";
const std::string Clear = "After stack clear: ";

const std::string IsEmpty = "\tIs emtpy(result): ";
const std::string Top = "\tStack top: ";


int main()
{
    std::cout << IntStackExample << std::endl;
    CMyStack<int> intStack;
    std::cout << InitStack << intStack.IsEmpty() << std::endl;
    intStack.Push(1);
    std::cout << PushOne << IsEmpty
        << intStack.IsEmpty() << Top << intStack.Top() << std::endl;
    intStack.Push(2);
    std::cout << PushTwo << IsEmpty
        << intStack.IsEmpty() << Top << intStack.Top() << std::endl;
    intStack.Pop();
    std::cout << Pop << IsEmpty
        << intStack.IsEmpty() << Top << intStack.Top() << std::endl;
    intStack.Clear();
    std::cout << Clear << IsEmpty << intStack.IsEmpty() << std::endl;

    std::cout << std::endl << StringStackExample << std::endl;
    CMyStack<std::string> stringStack;
    std::cout << InitStack << intStack.IsEmpty() << std::endl;
    stringStack.Push("abc");
    std::cout << PushOne << IsEmpty
        << stringStack.IsEmpty() << Top << stringStack.Top() << std::endl;
    stringStack.Push("def");
    std::cout << PushTwo << IsEmpty
        << stringStack.IsEmpty() << Top << stringStack.Top() << std::endl;
    stringStack.Pop();
    std::cout << Pop << IsEmpty
        << stringStack.IsEmpty() << Top << stringStack.Top() << std::endl;
    stringStack.Clear();
    std::cout << Clear << IsEmpty << stringStack.IsEmpty() << std::endl;
}

