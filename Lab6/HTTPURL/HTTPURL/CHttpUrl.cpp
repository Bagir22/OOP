#include "CHttpUrl.h"

const std::string protocolRegex = "(https?)://";
const std::string domainRegexStr = "([0-9a-z\-.]+)";
const std::string portRegex = "(?:\\:([\\d]{1,5}))?";
const std::string documentRegexStr = "(?:(?:/)([\\S]*))?";

const std::regex urlRegex = std::regex(protocolRegex + domainRegexStr + portRegex + documentRegexStr);

const std::regex domainRegex = std::regex(domainRegexStr);
const std::regex documentRegex = std::regex("([\\S]*)?");

const int MinPort = 1;
const int MaxPort = 65535;

const short HttpPort = 80;
const short HttpsPort = 443;

const char Slash = '/';
const std::string Http = "http";
const std::string Https = "https";

const std::string InvalidUrlErr = "Invalid url";
const std::string InvalidPortErr = "Invalid port";
const std::string InvalidDomainErr = "Invalid domain";
const std::string InvalidDocumentErr = "Invalid document";
const std::string InvalidProtocolErr = "Invalid protocol";

const std::string ProtocolPostfix = "://";
const std::string PortPrefix = ":";

std::string StringToLowerCase(const std::string& str)
{
	std::string data = str;
	std::transform(data.begin(), data.end(), data.begin(),[](char ch) 
		{ 
			return std::tolower(ch); 
		});

	return data;
}

Protocol ParseProtocol(const std::string& protocol)
{
	if (protocol == Http)
	{
		return Protocol::HTTP;
	}
	else if (protocol == Https)
	{
		return Protocol::HTTPS;
	}

	throw CUrlParsingError(InvalidProtocolErr);
}

unsigned short GetDefaultPort(const Protocol& protocol)
{
	switch (protocol)
	{
	case Protocol::HTTP:
		return HttpPort;
	case Protocol::HTTPS:
		return HttpsPort;
	default:
		throw CUrlParsingError(InvalidProtocolErr);
	}
}

unsigned short ParsePort(std::string const& stringPort, Protocol protocol)
{
	if (stringPort.empty())
	{
		return GetDefaultPort(protocol);
	}

	int portNumber;

	try
	{
		portNumber = std::stoi(stringPort);
	}
	catch (...)
	{
		throw CUrlParsingError(InvalidPortErr);
	}

	if (portNumber < MinPort || portNumber > MaxPort)
	{
		throw CUrlParsingError(InvalidPortErr);
	}

	return portNumber;
}

bool IsValidDomain(std::string const& domain)
{
	std::smatch matches;
	return (std::regex_match(domain, matches, domainRegex));
}

bool IsValidDocument(std::string const& document)
{
	std::smatch matches;
	return (std::regex_match(document, matches, documentRegex));
}

std::string CHttpUrl::NormalaizeDocument(const std::string& document)
{
	if (document.empty())
	{
		return std::string(1, Slash);
	}
	else if (document[0] == Slash)
	{
		return document;
	}
		
	return Slash + document;
}

CHttpUrl::CHttpUrl(std::string const& url)
{
	std::string lowerUrl = StringToLowerCase(url);

	std::smatch urlMatches;

	if (!std::regex_match(lowerUrl, urlMatches, urlRegex))
	{
		throw CUrlParsingError(InvalidUrlErr);
	}

	try
	{
		m_domain = urlMatches[2];
		m_document = NormalaizeDocument(urlMatches[4]);
		m_protocol = ParseProtocol(urlMatches[1]);
		m_port = ParsePort(urlMatches[3], m_protocol);
	}
	catch (const CUrlParsingError& err)
	{
		throw err;
	}	
}

CHttpUrl::CHttpUrl(std::string const& domain, std::string const& document, Protocol protocol)
{
	if (!IsValidDomain(domain))
	{
		throw CUrlParsingError(InvalidDomainErr);
	}
	m_domain = domain;
	if (!IsValidDocument(NormalaizeDocument(document)))
	{
		throw CUrlParsingError(InvalidDocumentErr);
	}

	m_document = NormalaizeDocument(document);
	m_protocol = protocol;
	m_port = GetDefaultPort(protocol);
}

CHttpUrl::CHttpUrl(std::string const& domain, std::string const& document, Protocol protocol, unsigned short port)
	: CHttpUrl(domain, document, protocol)
{
	m_port = ParsePort(std::to_string(port), protocol);
}


std::string CHttpUrl::GetURL() const
{
	std::string url;
	url += ProtocolToString(m_protocol) + ProtocolPostfix + m_domain + PortPrefix + std::to_string(m_port) + m_document;

	return url;
}

std::string CHttpUrl::GetDomain() const
{
	return m_domain;
}

std::string CHttpUrl::GetDocument() const
{
	return m_document;
}

Protocol CHttpUrl::GetProtocol() const
{
	return m_protocol;
}

unsigned short CHttpUrl::GetPort() const
{
	return m_port;
}

std::string CHttpUrl::ProtocolToString(Protocol protocol)
{

	switch (protocol)
	{
	case Protocol::HTTP:
		return Http;
	case Protocol::HTTPS:
		return Https;
	default:
		throw CUrlParsingError(InvalidProtocolErr);
	}
}
