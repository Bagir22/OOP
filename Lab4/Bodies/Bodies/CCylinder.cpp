#include "CCylinder.h"
#include "stdafx.h"

CCylinder::CCylinder(double density, double baseRadius, double height)
	: CSolidBody(density)
	, m_baseRadius(baseRadius)
	, m_height(height)
{
}

CCylinder::~CCylinder()
{
}

double CCylinder::GetBaseRadius() const
{
	return m_baseRadius;
}

double CCylinder::GetHeight() const
{
	return m_height;
}

double CCylinder::GetVolume() const
{
	return M_PI * pow(m_baseRadius, 2) * m_height;
}

std::string CCylinder::GetType() const
{
	return CylinderType;
}


void CCylinder::AppendProperties(std::ostringstream& strm) const
{
	strm << Radius << GetBaseRadius() << std::endl
		<< Height << GetHeight() << std::endl;
}