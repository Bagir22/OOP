#pragma once
#include "CBody.h"

class CSolidBody : public CBody
{
public:
	CSolidBody(double density);
	double GetDensity() const override;
	double GetMass() const override;
	virtual ~CSolidBody() = default;

private:
	double m_density;
};