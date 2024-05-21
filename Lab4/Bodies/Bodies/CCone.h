#pragma once
#include "CSolidBody.h"

const std::string ConeType = "Cone";

class CCone final : public CSolidBody
{
public:
	CCone(double destiny, double baseRadius, double height);
	double GetBaseRadius() const;
	double GetHeight() const;
	double GetVolume() const override;
	std::string GetType() const override;
	virtual ~CCone() = default;

private:
	void AppendProperties(std::ostringstream& strm) const override;
	double m_baseRadius;
	double m_height;
};