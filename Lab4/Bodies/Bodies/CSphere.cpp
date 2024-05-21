#include "CSphere.h"
#include "stdafx.h"

CSphere::CSphere(double density, double radius)
	: CSolidBody(density)
	, m_radius(radius)
{
}

double CSphere::GetRadius() const
{
	return m_radius;
}

std::string CSphere::GetType() const
{
	return SphereType;
}

void CSphere::AppendProperties(std::ostringstream& strm) const
{
	strm << Radius << GetRadius() << std::endl;
}


double CSphere::GetVolume() const
{
	return (( 4 / 3 ) * (pow(m_radius, 3) * M_PI));
}


