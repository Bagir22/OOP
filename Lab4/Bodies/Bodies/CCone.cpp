#include "CCone.h"
#include "stdafx.h"

CCone::CCone(double destiny, double baseRadius, double height)
	:CSolidBody(destiny)
	, m_height(height)
	, m_baseRadius(baseRadius) 
{
}


double CCone::GetBaseRadius() const
{
	return m_baseRadius;
}

double CCone::GetHeight() const
{
	return m_height;
}

double CCone::GetVolume() const
{
	return M_PI * pow(m_baseRadius, 2) * (m_height / 3);
}

std::string CCone::GetType() const
{
	return ConeType;
}

CCone::~CCone()
{
}

void CCone::AppendProperties(std::ostringstream& strm) const
{
	strm << Radius << GetBaseRadius() << std::endl
		<< Height << GetHeight() << std::endl;
}
