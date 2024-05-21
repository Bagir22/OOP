#include <iostream>
#include <string>
#include "CHttpUrl.h"
#include "CUrlParsingError.h"

int main()
{
    std::string urlLine;
    while (std::getline(std::cin, urlLine))
    {
        try 
        {
            CHttpUrl url = CHttpUrl(urlLine);
            std::cout << "Current url:\n";
            std::cout << "\tProtocol: " << url.ProtocolToString(url.GetProtocol()) << std::endl;
            std::cout << "\tDomain: " << url.GetDomain() << std::endl;
            std::cout << "\tPort: " << url.GetPort() << std::endl;
            std::cout << "\tDocument: " << url.GetDocument() << std::endl;
        }
        catch (const CUrlParsingError& err )
        {
            std::cout << "Error: " << err.what() << std::endl;
        }
    }
}
