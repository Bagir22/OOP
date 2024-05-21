#pragma once
#include "CSolidBody.h"

const std::string CylinderType = "Cylinder";

class CCylinder final : public CSolidBody
{
public:
	CCylinder(double density, double baseRadius, double height);
	double GetBaseRadius() const;
	double GetHeight() const;
	double GetVolume() const override;
	std::string GetType() const override;
	virtual ~CCylinder() = default;

private:
	void AppendProperties(std::ostringstream& strm) const;
	double m_baseRadius;
	double m_height;
};