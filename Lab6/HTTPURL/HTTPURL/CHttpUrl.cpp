#include "CHttpUrl.h"

const std::string protocolRegex = "(https?)://";
const std::string domainRegexStr = "([0-9a-z\-.]+)";
const std::string portRegex = "(?:\\:([\\d]{1,5}))?";
const std::string documentRegexStr = "(:?(.*))?";

const std::regex urlRegex = std::regex(protocolRegex + domainRegexStr + portRegex + documentRegexStr);

const std::regex domainRegex = std::regex(domainRegexStr);
const std::regex documentRegex = std::regex("([\\S]*)?");

std::string StringToValidParts(const std::string& str)
{
	std::string data = str;
	std::transform(data.begin(), data.end(), data.begin(), [](char ch)
		{
			if (ch == '\\') 
			{
				return int('/');
			}

			return std::tolower(ch); 
		});

	//std::cout << "Data " << data << std::endl;
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

	throw std::invalid_argument(InvalidProtocolErr);
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
		throw std::invalid_argument(InvalidProtocolErr);
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
		throw std::invalid_argument(InvalidPortErr);
	}

	if (portNumber < MinPort || portNumber > MaxPort)
	{
		throw std::invalid_argument(InvalidPortErr);
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
	std::string lowerUrl = StringToValidParts(url);

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
	StringToValidParts(domain);
	StringToValidParts(document);

	if (!IsValidDomain(domain))
	{
		throw std::invalid_argument(InvalidDomainErr);
	}
	m_domain = domain;
	if (!IsValidDocument(NormalaizeDocument(document)))
	{
		throw std::invalid_argument(InvalidDocumentErr);
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
		throw std::invalid_argument(InvalidProtocolErr);
	}
}
