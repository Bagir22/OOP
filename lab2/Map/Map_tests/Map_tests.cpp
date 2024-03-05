#define CATCH_CONFIG_MAIN
#include <iostream>
#include <sstream>
#include "../../../Catch2/catch.hpp"
#include "../Map/MapProcessor.h"

SCENARIO("Test ReadWords function")
{
    WHEN("Input is empty")
    {
        std::istringstream input("");
        THEN("Map is also empty")
        {
            std::map<std::string, int> words = ReadWords(input);
            CHECK(words.size() == 0);
        }
    }

    WHEN("Input has 1 word")
    {
        std::istringstream input("word");
        THEN("Map has one word")
        {
            std::map<std::string, int> words = ReadWords(input);
            CHECK(words.size() == 1);
            CHECK(words["word"] == 1);
        }
    }

    WHEN("Input has multiple words")
    {
        std::istringstream input("word other\nword слово");
        THEN("Map have multiple words")
        {
            std::map<std::string, int> words = ReadWords(input);
            CHECK(words.size() == 3);
            CHECK(words["word"] == 2);
            CHECK(words["other"] == 1);
            CHECK(words["слово"] == 1);
        }
    }
}

SCENARIO("Test PrintWorda function")
{
    WHEN("Map is empty")
    {
        std::map<std::string, int> emptyWords;
        std::ostringstream output;
        THEN("Output is also empty")
        {
            PrintWords(output, emptyWords);
            CHECK(output.str() == "");
        }
    }

    WHEN("Map has 1 value")
    {
        std::map<std::string, int> mapWithOneValue;
        mapWithOneValue["word"] = 1;
        std::ostringstream output;
        THEN("Output print one value from map")
        {
            PrintWords(output, mapWithOneValue);
            CHECK(output.str() == "word->1\n");
        }
    }

    WHEN("Map has more than one value")
    {
        std::map<std::string, int> multipleMap;
        multipleMap["word"] = 2;
        multipleMap["other"] = 1;
        multipleMap["слово"] = 1;
        std::ostringstream output;
        THEN("Output also has many values")
        {
            PrintWords(output, multipleMap);
            CHECK(output.str() == "other->1\nword->2\nслово->1\n");
        }
    }
}

