#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../../Catch2/catch.hpp"
#include "../Bodies/CBody.h"
#include "../Bodies/CBodyHandler.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <sstream>

TEST_CASE("Create sphere")
{
	std::cout << "Test 1: create sphere\n";

	CSphere sphere(1000, 10);

	CHECK(sphere.GetDensity() == 1000.0);
	CHECK(sphere.GetRadius() == 10.0);
	double volume = ((4 / 3) * (pow(10.0, 3) * M_PI));
	CHECK(sphere.GetVolume() == volume);
	CHECK(sphere.GetMass() == (sphere.GetVolume() * 1000.0));

	std::cout << "Test 1 passed\n";
}

TEST_CASE("Create parallelepiped")
{
	std::cout << "Test 1: create parallelepiped\n";

	CParallelepiped parallelepiped(1000, 10, 10, 10);

	CHECK(parallelepiped.GetDensity() == 1000.0);
	CHECK(parallelepiped.GetWidth() == 10.0);
	CHECK(parallelepiped.GetHeight() == 10.0);
	CHECK(parallelepiped.GetDepth() == 10.0);
	CHECK(parallelepiped.GetVolume() == 10.0 * 10.0 * 10.0);
	CHECK(parallelepiped.GetMass() == (parallelepiped.GetVolume() * 1000.0));

	std::cout << "Test 2 passed\n";
}

TEST_CASE("Create cone")
{
	std::cout << "Test 3: create cone\n";

	CCone cone(1000, 10, 10);

	CHECK(cone.GetDensity() == 1000.0);
	CHECK(cone.GetHeight() == 10.0);
	CHECK(cone.GetBaseRadius() == 10.0);
	CHECK(cone.GetVolume() == (pow(10, 2) * M_PI) * 10 / 3.0);
	CHECK(cone.GetMass() == (cone.GetVolume() * 1000.0));

	std::cout << "Test 3 passed\n";
}

TEST_CASE("Create cylinder")
{
	std::cout << "Test 3: create cylinder\n";

	CCylinder cylinder(1000, 10, 10);

	CHECK(cylinder.GetDensity() == 1000.0);
	CHECK(cylinder.GetHeight() == 10.0);
	CHECK(cylinder.GetBaseRadius() == 10.0);
	CHECK(cylinder.GetVolume() == (pow(10, 2) * M_PI) * 10);
	CHECK(cylinder.GetMass() == (cylinder.GetVolume() * 1000.0));

	std::cout << "Test 4 passed\n";
}

TEST_CASE("Create compound")
{
	std::cout << "Test 5: create compound\n";

	std::vector<std::shared_ptr<CBody>> childrens;

	CCompound compound = CCompound();
	std::shared_ptr<CBody> sphere = std::make_shared<CSphere>(1200, 12);
	std::shared_ptr<CBody> cylinder = std::make_shared<CCylinder>(1200, 12, 12);
	std::shared_ptr<CBody> cone = std::make_shared<CCone>(1200, 12, 12);
	std::shared_ptr<CBody> parallelepiped = std::make_shared<CParallelepiped>(1200, 12, 12, 12);

	childrens.push_back(sphere);
	childrens.push_back(cylinder);
	childrens.push_back(cone);
	childrens.push_back(parallelepiped);

	compound.AddChild(sphere);
	compound.AddChild(cylinder);
	compound.AddChild(cone);
	compound.AddChild(parallelepiped);

	CHECK(compound.GetChilds() == childrens);

	std::cout << "Test 5 passed\n";
}