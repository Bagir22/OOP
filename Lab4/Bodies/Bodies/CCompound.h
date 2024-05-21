#pragma once
#include "CSolidBody.h"
#include <vector>

const std::string CompoundType = "Compound";
const std::string ChildBodies = "\tChild bodies: ";
class CCompound final : public CBody
{
public:
	CCompound();
	double GetVolume() const;
	double GetMass() const;
	double GetDensity() const;
	size_t GetSize() const;
	std::string GetType() const override;
	void AddChild(std::shared_ptr<CBody> child);
	virtual ~CCompound() = default;
	std::vector<std::shared_ptr<CBody>> GetChilds() const;

private:
	void AddParent(CCompound* parent);
	void AppendProperties(std::ostringstream& output) const override;
	CCompound* m_parent;
	std::vector<std::shared_ptr<CBody>> m_childs;
};