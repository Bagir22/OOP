#define CATCH_CONFIG_MAIN
#include <iostream>
#include <sstream>
#include "../../../Catch2/catch.hpp"
#include "../vector/VectorProcessor.h"

SCENARIO("Test ParseVector function")
{
    WHEN("Input is empty")
    {
        std::istringstream input("");
        THEN("Vector is also empty")
        {
            std::vector<double> vector = ParseVector(input);
            CHECK(vector.empty());
        }
    }

    WHEN("Input has 1 value")
    {
        std::vector<double> numbers;
        std::vector<double> result = { 12.00 };
        std::istringstream input("12");
        THEN("Vector has the same value as in input")
        {
            std::vector<double> vector = ParseVector(input);
            CHECK(vector == result);
        }
    }

    WHEN("Input has text value")
    {
        std::vector<double> vector;
        std::vector<double> result = { 12.00, 3.85, -1.00 };
        std::istringstream input("12 3.85 -1 abc 43");
        THEN("Vector has the same values as input until text value")
        {
            std::vector<double> vector = ParseVector(input);
            CHECK(vector == result);
        }
    }
}


SCENARIO("Test MultiplyVector function")
{
    WHEN("Input is empty")
    {
        std::istringstream input("");
        THEN("Vector is also empty")
        {
            std::vector<double> vector = ParseVector(input);
            MultiplyVector(vector);
            CHECK(vector.empty());
        }
    }

    WHEN("Input is has positive values")
    {
        std::istringstream input("12.5 8 2 3");
        std::vector<double> result = { 25.00, 16.00, 4.00, 6.00 };
        THEN("All values in vector multiply by 2")
        {
            std::vector<double> vector = ParseVector(input);
            MultiplyVector(vector);
            CHECK(vector == result);
        }
    }

    WHEN("Input is has negative values")
    {
        std::istringstream input("12.5 8 -2 3");
        std::vector<double> result = { -25.00, -16.00, 4.00, -6.00 };
        THEN("All values in vector multiply by 2")
        {
            std::vector<double> vector = ParseVector(input);
            MultiplyVector(vector);
            CHECK(vector == result);
        }
    }
}

SCENARIO("PrintVector function")
{
    WHEN("Vector is empty")
    {
        std::vector<double> vector;
        std::ostringstream output;
        THEN("Output is also empty")
        {
            PrintVector(output, vector);
            CHECK(output.str() == "\n");
        }
    }

    WHEN("Vector has 1 value")
    {
        std::vector<double> vector = { 12 };
        std::ostringstream output;
        THEN("Output also has 1 value")
        {
            PrintVector(output, vector);
            CHECK(output.str() == "12.00 \n");
        }
    }

    WHEN("Vector has many values")
    {
        std::vector<double> vector = { 12.5, 8, -2, 3 };
        std::ostringstream output;
        THEN("Output also has many values")
        {
            PrintVector(output, vector);
            CHECK(output.str() == "12.50 8.00 -2.00 3.00 \n");
        }
    }
}