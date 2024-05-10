#pragma once
#include <stdexcept>
#include <numeric>
#include <algorithm>
#include "iostream"

const std::string Err0Denominator;
const char Delimter = '/';

class CRational
{
public:
    CRational();
    CRational(int value);
    CRational(int numerator, int denominator);
    ~CRational();

    int GetNumerator() const;
    int GetDenominator()const;
    double ToDouble()const;

    CRational operator+() const;
    CRational operator-() const;

    friend CRational operator+ (const CRational& num1, const CRational& num2);
    //CRational operator+ (const CRational& num) const;
    friend CRational operator- (const CRational& num1, const CRational& num2);
    friend CRational operator* (const CRational& num1, const CRational& num2);
    friend CRational operator/ (const CRational& num1, const CRational& num2);

    CRational& operator+= (const CRational& num);
    CRational& operator-= (const CRational& num);
    CRational& operator*= (const CRational& num);
    CRational& operator/= (const CRational& num);

    friend bool operator== (const CRational& num1, const CRational& num2);
    friend bool operator!= (const CRational& num1, const CRational& num2);
    friend bool operator< (const CRational& num1, const CRational& num2);
    friend bool operator> (const CRational& num1, const CRational& num2);
    friend bool operator<= (const CRational& num1, const CRational& num2);
    friend bool operator>= (const CRational& num1, const CRational& num2);

    friend std::istream& operator>> (std::istream& input, CRational& num);
    friend std::ostream& operator<< (std::ostream& output, const CRational& num);
    //friend CRational& operator-(const CRational& num1, const CRational& num2);
    //friend CRational operator*(const CRational& num1, const CRational& num2);
    //friend CRational operator/(const CRational& num1, const CRational& num2);

    //CRational& operator+=(const CRational& num);
    //CRational& operator-=(const CRational& num);
    //CRational& operator*=(const CRational& num);
    //CRational& operator/=(const CRational& num);

private:
    int m_numerator;
    int m_denominator;

    void Normalize();
    int gcd(int a, int b);
};