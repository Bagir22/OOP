#define CATCH_CONFIG_MAIN
#include <iostream>
#include <sstream>
#include "../../../Catch2/catch.hpp"
#include "../TrimBlanks/StringProcessor.h"

SCENARIO("Test ReadString function")
{
    WHEN("Input is empty")
    {
        std::istringstream input("");
        THEN("String is also empty")
        {
            std::string inputString = ReadString(input);
            CHECK(inputString == "");
        }
    }

    WHEN("Input without spaces")
    {
        std::string result = "withoutSpaces";
        std::istringstream input("withoutSpaces");
        THEN("Result has the same value as in input")
        {
            std::string inputString = ReadString(input);
            CHECK(inputString == result);
        }
    }

    WHEN("Input has string with spaces")
    {
        std::string result = "    string with spaces    ";
        std::istringstream input("    string with spaces    ");
        THEN("Result has the same string as input")
        {
            std::string inputString = ReadString(input);
            CHECK(inputString == result);
        }
    }
}

SCENARIO("Test TrimBlanks function")
{
    WHEN("Input is empty")
    {
        std::istringstream input("");
        THEN("Input string is also empty")
        {
            std::string inputString = ReadString(input);
            std::string trimedString = TrimBlanks(inputString);
            CHECK(trimedString == "");
        }
    }

    WHEN("Input is string without spaces")
    {
        std::istringstream input("withoutSpaces");
        std::string result = "withoutSpaces";
        THEN("TrimBlanks return same string")
        {
            std::string inputString = ReadString(input);
            std::string trimedString = TrimBlanks(inputString);
            CHECK(trimedString == result);
        }
    }

    WHEN("Input is string with spaces only")
    {
        std::string result = "";
        std::istringstream input("       ");
        THEN("TrimBlanks return string without extra spaces")
        {
            std::string inputString = ReadString(input);
            std::string trimedString = TrimBlanks(inputString);
            CHECK(trimedString == result);
        }
    }

    WHEN("Input is string with spaces")
    {
        std::string result = "string with  spaces";
        std::istringstream input("    string with  spaces    ");
        THEN("TrimBlanks return string without extra spaces")
        {
            std::string inputString = ReadString(input);
            std::string trimedString = TrimBlanks(inputString);
            CHECK(trimedString == result);
        }
    }
}

SCENARIO("PrintString function")
{
    WHEN("String is empty")
    {
        std::string emptyString;
        std::ostringstream output;
        THEN("Output is also empty")
        {
            PrintString(output, emptyString);
            CHECK(output.str() == "\n");
        }
    }

    WHEN("String without spaces")
    {
        std::string stringWithoutSpaces = "withoutSpaces";
        std::ostringstream output;
        THEN("Output also has string without spaces")
        {
            PrintString(output, stringWithoutSpaces);
            CHECK(output.str() == "withoutSpaces\n");
        }
    }

    WHEN("String have some spaces")
    {
        std::string stringWithSpaces = "string with  spaces";
        std::ostringstream output;
        THEN("Output also has many values")
        {
            PrintString(output, stringWithSpaces);
            CHECK(output.str() == "string with  spaces\n");
        }
    }
}
