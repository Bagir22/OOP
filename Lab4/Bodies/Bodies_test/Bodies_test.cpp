#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../../Catch2/catch.hpp"
#include "../Bodies/CBody.h"
#include "../Bodies/CBodyHandler.h"
#include <sstream>
#include <memory>

TEST_CASE("Add Sphere")
{
	std::cout << "Test 1: add sphere\n";
	std::vector<std::shared_ptr<CBody>> bodies;
	CBodyHandler handler(std::cin, std::cout, bodies);
	std::string userInput = "1 800.5 1.5\n";
	std::istringstream iss(userInput);
	std::streambuf* cin = std::cin.rdbuf(iss.rdbuf());
	handler.Operate();
	std::cin.rdbuf(cin);
	REQUIRE(bodies.size() == 1);
	REQUIRE(bodies[0]->GetType() == "Sphere");
	std::cout << "Test 1 passed\n";
}

TEST_CASE("Add Parallelepiped")
{
	std::cout << "Test 2: add parallelepiped\n";
	std::vector<std::shared_ptr<CBody>> bodies;
	CBodyHandler handler(std::cin, std::cout, bodies);
	std::string userInput = "2 400 15.6 20.5 25.8\n";
	std::istringstream iss(userInput);
	std::streambuf* cin = std::cin.rdbuf(iss.rdbuf());
	handler.Operate();
	std::cin.rdbuf(cin);
	REQUIRE(bodies.size() == 1);
	REQUIRE(bodies[0]->GetType() == "Parallelepiped");
	std::cout << "Test 2 passed\n";
}

TEST_CASE("Add Cone")
{
	std::cout << "Test 3: Add Cone\n";
	std::vector<std::shared_ptr<CBody>> bodies;
	CBodyHandler handler(std::cin, std::cout, bodies);
	std::string userInput = "3 250 6.5 15.5\n";
	std::istringstream iss(userInput);
	std::streambuf* cin = std::cin.rdbuf(iss.rdbuf());
	handler.Operate();
	std::cin.rdbuf(cin);
	REQUIRE(bodies.size() == 1);
	REQUIRE(bodies[0]->GetType() == "Cone");
	std::cout << "Test 3 passed\n";
}

TEST_CASE("Add Cylinder")
{
	std::cout << "Test 4: Add Cylinder\n";
	std::vector<std::shared_ptr<CBody>> bodies;
	CBodyHandler handler(std::cin, std::cout, bodies);
	std::string userInput = "4 250 6.5 15.5\n";
	std::istringstream iss(userInput);
	std::streambuf* cin = std::cin.rdbuf(iss.rdbuf());
	handler.Operate();
	std::cin.rdbuf(cin);
	REQUIRE(bodies.size() == 1);
	REQUIRE(bodies[0]->GetType() == "Cylinder");
	std::cout << "Test 4 passed\n";
}

TEST_CASE("Add Compound")
{
	std::cout << "Test 5: Add Compound\n";
	std::vector<std::shared_ptr<CBody>> bodies;
	CBodyHandler handler(std::cin, std::cout, bodies);
	std::string userInput = "5\n4 250 6.5 15.5\n2 400 15.6 20.5 25.8\n5\n";
	std::istringstream iss(userInput);
	std::streambuf* cin = std::cin.rdbuf(iss.rdbuf());
	handler.Operate();
	std::cin.rdbuf(cin);
	REQUIRE(bodies.size() == 1);
	REQUIRE(bodies[0]->GetType() == "Compound");
	std::cout << "Test 5 passed\n";
}

TEST_CASE("Input invalid command")
{
	std::ostringstream output;
	std::cout << "Test 6: Input invalid command\n";
	std::vector<std::shared_ptr<CBody>> bodies;
	CBodyHandler handler(std::cin, output, bodies);
	std::string userInput = "10\n";
	std::istringstream iss(userInput);
	std::streambuf* cin = std::cin.rdbuf(iss.rdbuf());
	handler.Operate();
	std::cin.rdbuf(cin);
	REQUIRE(output.str() == "Unknown command\n");
	std::cout << "Test 6 passed\n";
}

TEST_CASE("Input invalid args count")
{
	std::ostringstream output;
	std::cout << "Test 7: Invalid args count\n";
	std::vector<std::shared_ptr<CBody>> bodies;
	CBodyHandler handler(std::cin, output, bodies);
	std::string userInput = "4 250 6.5\n";
	std::istringstream iss(userInput);
	std::streambuf* cin = std::cin.rdbuf(iss.rdbuf());
	handler.Operate();
	std::cin.rdbuf(cin);
	REQUIRE(output.str() == "Invalid args count\n");
	std::cout << "Test 7 passed\n";
}