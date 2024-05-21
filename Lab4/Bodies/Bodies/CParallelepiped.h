#pragma once
#include "CSolidBody.h"

const std::string ParallelepipedType = "Parallelepiped";

class CParallelepiped final : public CSolidBody
{
public:
	CParallelepiped(double density, double height, double width, double depth);
	double GetWidth() const;
	double GetHeight() const;
	double GetDepth() const;
	double GetVolume() const;
	std::string GetType() const override;
	virtual ~CParallelepiped() = default;

private:
	void AppendProperties(std::ostringstream& strm) const override;
	double m_height;
	double m_width;
	double m_depth;
};