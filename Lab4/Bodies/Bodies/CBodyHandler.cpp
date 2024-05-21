#include "CBodyHandler.h"

CBodyHandler::CBodyHandler(std::istream& in, std::ostream& out, std::vector<std::shared_ptr<CBody>>& bodies)
	: m_input(in)
	, m_output(out)
	, m_bodies(bodies)
{
}

void CBodyHandler::Introduce()
{
	m_output << AddBodies;
	m_output << AddSphereIntro;
	m_output << SphereExample;
	m_output << AddParallelepipedIntro;
	m_output << ParallelepipedExample;
	m_output << AddConeIntro;
	m_output << ConeExample;
	m_output << AddCylinderIntro;
	m_output << CylinderExample;
	m_output << CompoundStartMode;
	m_output << CompoundEndMode;
	m_output << MaxMassCommand;
	m_output << MinWeightCommand;
	m_output << PrintBoidesCommand;
	m_output << ExitCommand;
}


std::vector<std::string> CBodyHandler::Split(std::string s, std::string delimiter) {
	size_t pos_start = 0, pos_end, delim_len = delimiter.length();
	std::string token;
	std::vector<std::string> res;

	while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
		token = s.substr(pos_start, pos_end - pos_start);
		pos_start = pos_end + delim_len;
		res.push_back(token);
	}

	res.push_back(s.substr(pos_start));
	return res;
}

bool CBodyHandler::IsInt(const std::string& byteArg)
{
	if (byteArg.empty())
	{
		return false;
	}

	for (int i = 0; i < byteArg.size(); i++)
	{
		if (i == 0 && (byteArg[i] != '-' && !isdigit(byteArg[i])))
		{
			return false;
		}
		else if (i != 0 && !isdigit(byteArg[i]))
		{
			return false;
		}
	}

	return true;
}

std::shared_ptr<CBody> CBodyHandler::MaxMass()
{
	if (m_bodies.empty())
	{
		m_output << MaxMassErr;
		return nullptr;
	}
	double maxMass = -DBL_MAX, currentMass = 0;
	std::shared_ptr<CBody> maxMassBody;
	std::ostringstream strm;
	for (auto& body : m_bodies)
	{
		if ((currentMass = body->GetMass()) > maxMass)
		{
			maxMass = currentMass;
			maxMassBody = body;
		}
	}
	//m_output << MaxMassResult << maxMassBody->ToString(strm) << std::endl;
	return maxMassBody;
}

std::shared_ptr<CBody> CBodyHandler::MinWeight()
{
	if (m_bodies.empty())
	{
		m_output << MinWeightErr;
		return nullptr;
	}
	double minWeight = DBL_MAX, currentWeight = 0;
	std::shared_ptr<CBody> minWeightBody;
	std::ostringstream strm;

	for (auto& body : m_bodies)
	{
		currentWeight = (body->GetMass() * G) - (body->GetVolume() * WaterDensity * G);
		if (minWeight > currentWeight)
		{
			minWeight = currentWeight;
			minWeightBody = body;
		}
	}
	//m_output << MinWeightResult << minWeightBody->ToString(strm) << std::endl;
	return minWeightBody;
}

void CBodyHandler::PrintBodies() const
{
	if (m_bodies.empty())
	{
		m_output << EmptyBodies;
	}
	std::ostringstream strm;
	m_output << BodiesSize << m_bodies.size() << std::endl;
	for (int i = 0; i < m_bodies.size(); i++)
	{
		m_output << m_bodies[i]->ToString(strm) << std::endl;
		strm.str("");
	}
	return;
}

bool CBodyHandler::CheckArgs(std::vector<std::string> args)
{
	try 
	{
		for (auto arg : args) 
		{
			double value = std::stod(arg);
			if (value <= 0)
			{
				m_output << ArgLower0Err;
				return false;
			}
		}
	}
	catch (...)
	{
		m_output << ArgToDoubleErr;
		return false;

	}
	return true;
}

void CBodyHandler::AddSphere(CSphere sphere)
{
	m_bodies.push_back(std::make_shared<CSphere>(sphere));
}

void CBodyHandler::AddParallelepiped(CParallelepiped parallelepiped)
{
	m_bodies.push_back(std::make_shared<CParallelepiped>(parallelepiped));
}

void CBodyHandler::AddCone(CCone cone)
{
	m_bodies.push_back(std::make_shared<CCone>(cone));
}

void CBodyHandler::AddCylinder(CCylinder cylinder)
{
	m_bodies.push_back(std::make_shared<CCylinder>(cylinder));
}

void CBodyHandler::AddCompound(std::shared_ptr<CCompound> compound)
{
	m_bodies.push_back(compound);
}

CSphere CBodyHandler::CreateSphere(std::vector<std::string> args)
{
	double density = stod(args[1]);
	double radius = stod(args[2]);
	return CSphere(density, radius);
}

CParallelepiped CBodyHandler::CreateParallelepiped(std::vector<std::string> args)
{
	double density = stod(args[1]);
	double height = stod(args[2]);
	double width = stod(args[3]);
	double depth = stod(args[4]);
	return CParallelepiped(density, height, width, depth);
}

CCone CBodyHandler::CreateCone(std::vector<std::string> args)
{
	double density = stod(args[1]);
	double radius = stod(args[2]);
	double height = stod(args[3]);
	return CCone(density, radius, height);
}

CCylinder CBodyHandler::CreateCylinder(std::vector<std::string> args)
{
	double density = stod(args[1]);
	double radius = stod(args[2]);
	double height = stod(args[3]);
	return CCylinder(density, radius, height);
}

std::shared_ptr<CCompound> CBodyHandler::CreateCompound()
{
	std::string line;
	std::shared_ptr<CCompound> compound = std::make_shared<CCompound>();
	bool flag = true;
	m_output << CompoundModeEnable;
	while (flag == true)
	{
		std::getline(m_input, line);
		std::vector<std::string> splittedLine = Split(line, " ");
		int command = 0;

		if (IsInt(splittedLine[0]))
		{
			command = stoi(splittedLine[0]);
		}
		switch (command)
		{
		case 1:
		{
			if (splittedLine.size() != 3)
			{
				m_output << ArgsCountErr;
				break;
			}
			else if (!CheckArgs(splittedLine))
			{
				break;
			}

			compound->AddChild(std::make_shared<CSphere>(CreateSphere(splittedLine)));
			break;
		}
		case 2:
		{
			if (splittedLine.size() != 5)
			{
				m_output << ArgsCountErr;
				break;
			}
			else if (!CheckArgs(splittedLine))
			{
				break;
			}

			compound->AddChild(std::make_shared<CParallelepiped>(CreateParallelepiped(splittedLine)));
			break;
		}
		case 3:
		{
			if (splittedLine.size() != 4)
			{
				m_output << ArgsCountErr;
				break;
			}
			else if (!CheckArgs(splittedLine))
			{
				break;
			}


			compound->AddChild(std::make_shared<CCone>(CreateCone(splittedLine)));
			break;
		}
		case 4:
		{
			if (splittedLine.size() != 4)
			{
				m_output << ArgsCountErr;
				break;
			}
			else if (!CheckArgs(splittedLine))
			{
				break;
			}

			compound->AddChild(std::make_shared<CCylinder>(CreateCylinder(splittedLine)));
			break;
		}
		case 5:
		{
			std::shared_ptr<CCompound> subCompound = CreateCompound();
			if (subCompound.get()->GetSize() != 0)
			{
				compound->AddChild(subCompound);
			}
			break;
		}
		case 6:
		{
			flag = false;
			break;
		}
		default:
			std::cout << UnknownCommand;
			break;
		}
	}

	m_output << CompoundModeDisable;
	return compound;
}

void CBodyHandler::Operate()
{
	std::string line;
	
	while (std::getline(m_input, line) && !m_exit) 
	{
		std::vector<std::string> splittedLine = Split(line, " ");
		int command = 0;

		if (IsInt(splittedLine[0]))
		{
			command = stoi(splittedLine[0]);
		}

		switch (command)
		{
		case 1:
		{
			if (splittedLine.size() != 3)
			{
				m_output << ArgsCountErr;
				break;
			}
			else if (!CheckArgs(splittedLine))
			{
				break;
			}

			AddSphere(CreateSphere(splittedLine));
			break;
		}
		case 2:
		{
			if (splittedLine.size() != 5)
			{
				m_output << ArgsCountErr;
				break;
			}
			else if (!CheckArgs(splittedLine))
			{
				break;
			}

			AddParallelepiped(CreateParallelepiped(splittedLine));
			break;
		}
		case 3:
		{
			if (splittedLine.size() != 4)
			{
				m_output << ArgsCountErr;
				break;
			}
			else if (!CheckArgs(splittedLine))
			{
				break;
			}

			
			AddCone(CreateCone(splittedLine));
			break;
		}
		case 4:
		{
			if (splittedLine.size() != 4)
			{
				m_output << ArgsCountErr;
				break;
			}
			else if (!CheckArgs(splittedLine))
			{
				break;
			}

			
			AddCylinder(CreateCylinder(splittedLine));
			break;
		}
		case 5:
		{
			std::shared_ptr<CCompound> compound = CreateCompound();
			if (compound.get()->GetSize() != 0) 
			{
				AddCompound(compound);
			}
			break;
		}
		case 7:
		{
			std::shared_ptr<CBody> maxMassBody = MaxMass();
			if (maxMassBody != nullptr)
			{
				std::ostringstream strm;
				m_output << MaxMassResult << maxMassBody->ToString(strm) << std::endl;
			}
			
			break;
		}
		case 8:
		{
			std::shared_ptr<CBody> minWeightBody = MinWeight();
			if (minWeightBody != nullptr)
			{
				std::ostringstream strm;
				m_output << MinWeightResult << minWeightBody->ToString(strm) << std::endl;
			}
			
			break;
		}
		case 9:
		{
			PrintBodies();
			break;
		}
		case 10:
		{
			m_exit = true;
			PrintBodies();
			MaxMass();
			MinWeight();
			return;
		}
		default:
			m_output << UnknownCommand;
			break;
		}
	}

	return;
}
