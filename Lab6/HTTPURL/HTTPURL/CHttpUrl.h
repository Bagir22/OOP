#pragma once
#include "CUrlParsingError.h"
#include <iostream>
#include <algorithm>
#include <regex>

enum class Protocol
{
    HTTP,
    HTTPS
};

class CHttpUrl
{
public:
    CHttpUrl(std::string const& url);
    CHttpUrl(std::string const& domain, std::string const& document, Protocol protocol = Protocol::HTTP);
    CHttpUrl(std::string const& domain, std::string const& document, Protocol protocol, unsigned short port);

    std::string GetURL()const;
    std::string GetDomain()const;
    std::string GetDocument()const;
    Protocol GetProtocol()const;
    unsigned short GetPort()const;

    static std::string ProtocolToString(Protocol protocol);
    std::string NormalaizeDocument(const std::string& document);
private:
    std::string m_url;
    std::string m_domain;
    std::string m_document;
    Protocol m_protocol;
    unsigned short m_port;
};