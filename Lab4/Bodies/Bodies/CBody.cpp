#include "CBody.h"

CBody::CBody()
{
}

CBody::~CBody()
{
}


std::string CBody::ToString(std::ostringstream& strm) const
{
	strm << GetType() << ":" << std::endl
		<< std::fixed << std::setprecision(Precision)
		<< Density << GetDensity() << std::endl
		<< Volume << GetVolume() << std::endl
		<< Mass << GetMass() << std::endl;
	AppendProperties(strm);
	return strm.str();
}