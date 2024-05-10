#pragma once
#include "iostream"
#include <sstream>
#include <iomanip>

const std::string Density = "\tDensity: ";
const std::string Volume = "\tVolume: ";
const std::string Mass = "\tMass: ";

const std::string Radius = "\tRadius: ";
const std::string Height = "\tHeight: ";
const std::string Width = "\tWidth: ";
const std::string Depth = "\tDepth: ";

const int Precision = 3;

class CBody
{
public:
	CBody();
	virtual double GetDensity() const = 0;
	virtual double GetVolume() const = 0;
	virtual double GetMass() const = 0;
	std::string ToString(std::ostringstream& output) const;
	virtual std::string GetType() const = 0;
	virtual ~CBody();
	
private:
	virtual void AppendProperties(std::ostringstream& strm) const = 0;
};