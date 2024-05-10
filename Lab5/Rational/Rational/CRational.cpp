#include "CRational.h"
#include <stdexcept>
#include "iostream"
#include "ios"

CRational::CRational() :
	m_numerator(0),
	m_denominator(1)
{
}

CRational::CRational(int value)	:
	m_numerator(value),
	m_denominator(1)
{
}

CRational::CRational(int numerator, int denominator)
{
	if (denominator == 0)
	{
		throw std::invalid_argument(Err0Denominator);
	}

	if (denominator < 0) 
	{
		numerator *= -1;
		denominator *= -1;
	}

	m_numerator = numerator;
	m_denominator = denominator;
	Normalize();
}

CRational::~CRational()
{
}

int CRational::GetNumerator() const
{
	return m_numerator;
}

int CRational::GetDenominator() const
{
	return m_denominator;
}

double CRational::ToDouble() const
{
	return double(m_numerator) / double(m_denominator);
}

CRational CRational::operator+() const
{
	return *this;
}

CRational CRational::operator-() const
{
	return CRational(-m_numerator, m_denominator);
}

CRational operator+ (const CRational& num1, const CRational& num2)
{
	int numerator = num1.GetNumerator() * num2.GetDenominator() + num1.GetDenominator() * num2.GetNumerator();
	int denominator = num1.GetDenominator() * num2.GetDenominator();

	return CRational(numerator, denominator);
}

CRational operator- (const CRational& num1, const CRational& num2)
{
	int numerator = num1.GetNumerator() * num2.GetDenominator() - num1.GetDenominator() * num2.GetNumerator();
	int denominator = num1.GetDenominator() * num2.GetDenominator();

	return CRational(numerator, denominator);
}

CRational operator* (const CRational& num1, const CRational& num2)
{
	int numerator = num1.GetNumerator() * num2.GetNumerator();
	int denominator = num1.GetDenominator() * num2.GetDenominator();
	return CRational(numerator, denominator);
}

CRational operator/ (const CRational& num1, const CRational& num2)
{
	int numerator = num1.GetNumerator() * num2.GetDenominator();
	int denominator = num1.GetDenominator() * num2.GetNumerator();
	return CRational(numerator, denominator);
}

CRational& CRational::operator+= (const CRational& num)
{
	*this = *this + num;
	return *this;
}

CRational& CRational::operator-= (const CRational& num)
{
	*this = *this - num;
	return *this;
}

CRational& CRational::operator*= (const CRational& num)
{
	*this = *this * num;
	return *this;
}


CRational& CRational::operator/= (const CRational& num)
{
	*this = *this / num;
	return *this;
}

void CRational::Normalize()
{
	int nod = this->gcd(abs(m_numerator), m_denominator);
	m_numerator /= nod;
	m_denominator /= nod;
}

int CRational::gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

bool operator== (const CRational& num1, const CRational& num2)
{
	return (num1.GetNumerator() == num2.GetNumerator() && num1.GetDenominator() == num2.GetDenominator());
}

bool operator!= (const CRational& num1, const CRational& num2)
{
	return !(num1 == num2);
}

bool operator< (const CRational& num1, const CRational& num2)
{
	return num1.ToDouble() < num2.ToDouble();
}

bool operator> (const CRational& num1, const CRational& num2)
{
	return num1.ToDouble() > num2.ToDouble();
}

bool operator<= (const CRational& num1, const CRational& num2)
{
	return num1.ToDouble() <= num2.ToDouble();
}

bool operator>= (const CRational& num1, const CRational& num2)
{
	return num1.ToDouble() >= num2.ToDouble();
}

std::istream& operator>>(std::istream& input, CRational& num)
{
	int numerator, denominator;
	if (input >> numerator && input.get() == Delimter && input >> denominator)
	{
		num = CRational(numerator, denominator);
	}
	else
	{
		input.setstate(std::ios::failbit);
	}

	return input;
}

std::ostream& operator<<(std::ostream& output, const CRational& num)
{
	output << num.GetNumerator() << Delimter << num.GetDenominator();
	return output;
}

/*
CRational CRational::operator+(const CRational& num1, const CRational& num2)
{
	int numerator = num1.GetNumerator() * num2.GetDenominator() + num1.GetDenominator() * num2.GetNumerator();
	int denominator = num1.GetDenominator() * num2.GetDenominator();

	return CRational(numerator, denominator);
}
*/

/*
CRational operator+(const CRational& num1, const CRational& num2)
{
	int numerator = num1.GetNumerator() * num2.GetDenominator() + num1.GetDenominator() * num2.GetNumerator();
	int denominator = num1.GetDenominator() * num2.GetDenominator();

	return CRational(numerator, denominator);
}
*/
//
//
//CRational& CRational::operator+=(const CRational& num)
//{
//	*this = *this + num;
//	return *this;
//}
//
//CRational& CRational::operator-=(const CRational& num)
//{
//	*this = *this - num;
//	return *this;
//}
//
//CRational& CRational::operator*=(const CRational& num)
//{
//	*this = &
//	return *this;
//}

/*
CRational& operator-(const CRational& num1, const CRational& num2)
{
	int numerator = num1.GetNumerator() * num2.GetDenominator() - num1.GetDenominator() * num2.GetNumerator();
	int denominator = num1.GetDenominator() * num2.GetDenominator();

	return CRational(numerator, denominator);
}
*/