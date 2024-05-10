#include "CCompound.h"

CCompound::CCompound()
	: m_parent(nullptr)
{
}

double CCompound::GetDensity() const
{
	double mass = 0;
	double volume = 0;
	for (const std::shared_ptr<CBody>& body : m_childs)
	{
		mass += body->GetMass();
		volume += body->GetVolume();
	}

	return mass / volume;
}

std::string CCompound::GetType() const
{
	return CompoundType;
}

size_t CCompound::GetSize() const
{
	return m_childs.size();
}

double CCompound::GetVolume() const
{
	double volume = 0;
	for (const std::shared_ptr<CBody>& body : m_childs)
	{
		volume += body->GetVolume();
	}

	return volume;
}

double CCompound::GetMass() const
{
	double mass = 0;
	for (const std::shared_ptr<CBody>& body : m_childs)
	{
		mass += body->GetMass();
	}

	return mass;
}

void CCompound::AddParent(CCompound* parent)
{
	m_parent = parent;
}

void CCompound::AddChild(std::shared_ptr<CBody> child)
{
	m_childs.push_back(child);
}

CCompound::~CCompound()
{
}

void CCompound::AppendProperties(std::ostringstream& output) const
{
	output << ChildBodies;
	for (auto& ptr : m_childs)
	{
		std::string type = ptr->GetType();
		output << type << " ";
		if (type == CompoundType)
		{
			output << "\n";
			ptr->ToString(output);
		}
	}
	output << std::endl;
}