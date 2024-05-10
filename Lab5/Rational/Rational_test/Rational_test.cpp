#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../../Catch2/catch.hpp"
#include <iostream>
#include "../Rational/CRational.h"

TEST_CASE("Create rational with default values")
{
	std::cout << "Test 1: rational with default values\n";
	CRational num = CRational();
	REQUIRE(num.GetNumerator() == 0);
	REQUIRE(num.GetDenominator() == 1);
	std::cout << "Test 1 passed\n";
}

TEST_CASE("Create rational with numerator only")
{
	std::cout << "Test 2: rational with numerator only\n";
	CRational num = CRational(2);
	REQUIRE(num.GetNumerator() == 2);
	REQUIRE(num.GetDenominator() == 1);
	std::cout << "Test 2 passed\n";
}

TEST_CASE("Create rational with numerator and denominator without normalize")
{
	std::cout << "Test 3: rational with numerator and denominator without normalize\n";
	CRational num = CRational(1, 2);
	REQUIRE(num.GetNumerator() == 1);
	REQUIRE(num.GetDenominator() == 2);
	std::cout << "Test 3 passed\n";
}

TEST_CASE("Create rational with numerator and denominator with normalize")
{
	std::cout << "Test 4: rational with numerator and denominator with normalize\n";
	CRational num = CRational(4, 8);
	REQUIRE(num.GetNumerator() == 1);
	REQUIRE(num.GetDenominator() == 2);
	std::cout << "Test 4 passed\n";
}

TEST_CASE("Create rational with numerator and negative denominator")
{
	std::cout << "Test 5: rational with numerator and negative denominator\n";
	CRational num = CRational(4, -8);
	REQUIRE(num.GetNumerator() == -1);
	REQUIRE(num.GetDenominator() == 2);
	std::cout << "Test 5 passed\n";
}

TEST_CASE("Create rational with denominator = 0")
{
	std::cout << "Test 6: rational with denominator = 0\n";
	REQUIRE_THROWS_AS(CRational(5, 0), std::invalid_argument);
	std::cout << "Test 6 passed\n";
}

TEST_CASE("Operator: Unary+")
{
	std::cout << "Test 7: unary + operator\n";
	CRational num1 = CRational(3, 5);
	CRational num2 = CRational(3, 5);
	REQUIRE(+num1 == num2);
	std::cout << "Test 7 passed\n";
}

TEST_CASE("Operator: Unary-")
{
	std::cout << "Test 8: unary - operator\n";
	CRational num1 = CRational(3, 5);
	CRational num2 = CRational(-3, 5);
	REQUIRE(-num1 == num2);
	std::cout << "Test 8 passed\n";
}

TEST_CASE("Operator: Binary+")
{
	std::cout << "Test 9: binary + operator\n";
	REQUIRE(CRational(1, 2) + CRational(1, 6) == CRational(2, 3));
	REQUIRE(CRational(1, 2) + 1 == CRational(3, 2));
	REQUIRE(1 + CRational(1, 2) == CRational(3, 2));
	std::cout << "Test 9 passed\n";
}

TEST_CASE("Operator: Binary-")
{
	std::cout << "Test 10: binary - operator\n";
	REQUIRE(CRational(1, 2) - CRational(1, 6) == CRational(1, 3));
	REQUIRE(CRational(1, 2) - 1 == CRational(-1, 2));
	REQUIRE(1 - CRational(1, 2) == CRational(1, 2));
	std::cout << "Test 10 passed\n";
}

TEST_CASE("Operator: +=")
{
	std::cout << "Test 11: operator +=\n";
	CRational num = CRational(1, 2);
	num += CRational(1, 6);
	REQUIRE(num == CRational(2, 3));
	num = CRational(1, 2);
	num += 1;
	REQUIRE(num == CRational(3, 2));
	std::cout << "Test 11 passed\n";
}

TEST_CASE("Operator: -=")
{
	std::cout << "Test 12: operator -=\n";
	CRational num = CRational(1, 2);
	num -= CRational(1, 6);
	REQUIRE(num == CRational(1, 3));
	num = CRational(1, 2);
	num += 1;
	REQUIRE(num == CRational(3, 2));
	std::cout << "Test 12 passed\n";
}

TEST_CASE("Operator: *")
{
	std::cout << "Test 13: operator *\n";
	REQUIRE((CRational(1, 2) * CRational(2, 3)) == CRational(1, 3));
	REQUIRE((CRational(1, 2) * -3) == CRational(-3, 2));
	REQUIRE((7 * CRational(2, 3)) == CRational(14, 3));
	std::cout << "Test 13 passed\n";
}


TEST_CASE("Operator: /")
{
	std::cout << "Test 14: operator /\n";
	REQUIRE((CRational(1, 2) / CRational(2, 3)) == CRational(3, 4));
	REQUIRE((CRational(1, 2) / 5) == CRational(1, 10));
	REQUIRE((7 / CRational(2, 3)) == CRational(21, 2));
	std::cout << "Test 14 passed\n";
}

TEST_CASE("Operator: *=")
{
	std::cout << "Test 15: operator *=\n";
	CRational num = CRational(1, 2);
	num *= CRational(2, 3);
	REQUIRE(num == CRational(1, 3));
	num = CRational(1, 2);
	num *= 3;
	REQUIRE(num == CRational(3, 2));
	std::cout << "Test 15 passed\n";
}

TEST_CASE("Operator: /=")
{
	std::cout << "Test 16: operator /=\n";
	CRational num = CRational(1, 2);
	num /= CRational(2, 3);
	REQUIRE(num == CRational(3, 4));
	num = CRational(1, 2);
	num /= 3;
	REQUIRE(num == CRational(1, 6));
	num = CRational(3, 4);
	num /= CRational(3, 8);
	REQUIRE(num == CRational(2, 1));
	std::cout << "Test 16 passed\n";
}

TEST_CASE("Operator: == and !=")
{
	std::cout << "Test 16: operator == and !=\n";
	REQUIRE((CRational(1, 2) == CRational(1, 2)) == true);
	REQUIRE((CRational(1, 2) == CRational(2, 3)) == false);
	REQUIRE((CRational(4, 1) == 4) == true);
	REQUIRE((CRational(1, 2) == 7) == false);
	REQUIRE((3 == CRational(3, 1)) == true);
	REQUIRE((3 == CRational(2, 3)) == false);
	REQUIRE((CRational(1, 2) != CRational(1, 2)) == false);
	REQUIRE((CRational(1, 2) != CRational(2, 3)) == true);
	REQUIRE((CRational(4, 1) != 4) == false);
	REQUIRE((CRational(1, 2) != 7) == true);
	REQUIRE((3 != CRational(3, 1)) == false);
	REQUIRE((3 != CRational(2, 3)) == true);
	std::cout << "Test 16 passed\n";
}

TEST_CASE("Operator: <, <=, >, >=")
{
	std::cout << "Test 17: operator <, <=, >, >=\n";
	REQUIRE((CRational(1, 2) >= CRational(1, 3)) == true);
	REQUIRE((CRational(1, 2) <= CRational(1, 3)) == false);
	REQUIRE((CRational(3, 1) > 2) == true);
	REQUIRE((CRational(1, 2) < 7) == true);
	REQUIRE((3 <= CRational(7, 2)) == true);
	REQUIRE((3 >= CRational(8, 2)) == false);
	std::cout << "Test 17 passed\n";
}

TEST_CASE("Operator: <<")
{
	std::cout << "Test 18: operator <<\n";
	std::istringstream input("7/15");
	CRational num;
	input >> num;
	REQUIRE(num == CRational(7, 15));
	std::cout << "Test 18 passed\n";
}

TEST_CASE("Operator: >>")
{
	std::cout << "Test 19: operator >>\n";
	std::ostringstream output;
	CRational num = CRational(7, 15);
	output << num;
	REQUIRE(output.str() == "7/15");
	std::cout << "Test 19 passed\n";
}