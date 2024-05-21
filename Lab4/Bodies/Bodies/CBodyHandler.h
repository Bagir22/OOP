#pragma once
#include "iostream"
#include "vector"
#include "CBody.h"
#include "CSphere.h"
#include "CParallelepiped.h"
#include "CCone.h"
#include "CCylinder.h"
#include "CCompound.h"

const double G = 9.8;
const double WaterDensity = 997.0;

const std::string AddBodies = "Add bodies:\n";
const std::string AddSphereIntro = "\tSpehere: 1 density<double> radius<double>\n";
const std::string SphereExample = "\t\tSpehere example: 1 800.5 1.5\n";
const std::string AddParallelepipedIntro = "\tParallelepiped: 2 density<double> width<double> height<double> depth<double>\n";
const std::string ParallelepipedExample = "\t\tParallelepiped example: 2 250.25 2 6.8 14.7\n";
const std::string AddConeIntro = "\tCone: 3 density<double> radius<double> height<double>\n";
const std::string ConeExample = "\t\tCone example: 3 250 6.5 15.5\n";
const std::string AddCylinderIntro = "\tCylinder: 4 density<double> radius<double> height<double>\n";
const std::string CylinderExample = "\t\tCylinder example: 4 250 6.5 15.5\n";
const std::string CompoundStartMode = "\tStart compound: 5\n";
const std::string CompoundEndMode = "\tEnd compound: 6\n";
const std::string MaxMassCommand = "Max mass body: 7\n";
const std::string MinWeightCommand = "Min weight: 8\n";
const std::string PrintBoidesCommand = "Print bodies: 9\n";
const std::string ExitCommand = "Exit: 10\n";
const std::string UnknownCommand = "Unknown command\n";

const std::string MaxMassErr = "Can't find max mass body: bodies empty\n";
const std::string MaxMassResult = "Max mass body: ";
const std::string MinWeightErr = "Can't find min weight body: bodies empty\n";
const std::string MinWeightResult = "Min weight body: ";
const std::string EmptyBodies = "Bodies is empty\n";
const std::string BodiesSize = "Bodies size: ";
const std::string ArgLower0Err = "Arg can't be lower or equal 0\n";
const std::string ArgToDoubleErr = "Can't parse args to double\n";
const std::string ArgsCountErr = "Invalid args count\n";

const std::string CompoundModeEnable = "Compound mode enabled\n";
const std::string CompoundModeDisable = "Compound mode disabled\n";

class CBodyHandler
{
public:
	CBodyHandler(std::istream& input, std::ostream& output, std::vector<std::shared_ptr<CBody>>& bodies);
	void Introduce();
	void Operate();
private:
	std::vector<std::shared_ptr<CBody>>& m_bodies;
	std::istream& m_input;
	std::ostream& m_output;
	bool m_exit = false;

	std::shared_ptr<CBody> MaxMass();
	std::shared_ptr<CBody> MinWeight();
	void PrintBodies() const;
	bool CheckArgs(std::vector<std::string> args);
	void AddSphere(CSphere sphere);
	void AddParallelepiped(CParallelepiped parallelepiped);
	void AddCone(CCone cone);
	void AddCylinder(CCylinder cylinder);
	void AddCompound(std::shared_ptr<CCompound> compound);

	CSphere CreateSphere(std::vector<std::string> args);
	CParallelepiped CreateParallelepiped(std::vector<std::string> args);
	CCone CreateCone(std::vector<std::string> args);
	CCylinder CreateCylinder(std::vector<std::string> args);
	std::shared_ptr<CCompound> CreateCompound();

	std::vector<std::string> Split(std::string s, std::string delimiter);
	bool IsInt(const std::string& byteArg);
};