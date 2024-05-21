#pragma once
#include "CSolidBody.h"

const std::string SphereType = "Sphere";

class CSphere final : public CSolidBody
{
public:
	CSphere(double density, double radius);
	double GetRadius() const;
	double GetVolume() const override;
	std::string GetType() const override;
	virtual ~CSphere() = default;

private:
	void AppendProperties(std::ostringstream& strm) const override;
	double m_radius;
};