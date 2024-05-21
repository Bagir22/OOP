#include <iostream>
#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../../Catch2/catch.hpp"
#include <iostream>
#include "../HTTPURL/CHttpUrl.h"

TEST_CASE("Valid urls check")
{
	SECTION("Url only with http protocol and some document")
	{
		std::cout << "Test 1: Url only with http protocol and some document\n";

		CHttpUrl url("http://google.com/document");
		REQUIRE(url.GetProtocol() == Protocol::HTTP);
		REQUIRE(url.GetDomain() == "google.com");
		REQUIRE(url.GetDocument() == "/document");
		REQUIRE(url.GetPort() == 80);

		std::cout << "Test 1 passed\n";
	}

	SECTION("Url only with https protocol")
	{
		std::cout << "Test 2: Url only with https protocol\n";

		CHttpUrl url("https://google.com");
		REQUIRE(url.GetProtocol() == Protocol::HTTPS);
		REQUIRE(url.GetDomain() == "google.com");
		REQUIRE(url.GetDocument() == "/");
		REQUIRE(url.GetPort() == 443);

		std::cout << "Test 2 passed\n";
	}

	SECTION("Url only with http protocol and some valid port")
	{
		std::cout << "Test 6: Url only with httpprotocol and some valid port\n";

		CHttpUrl url("http://localhost:8080");
		REQUIRE(url.GetProtocol() == Protocol::HTTP);
		REQUIRE(url.GetDomain() == "localhost");
		REQUIRE(url.GetDocument() == "/");
		REQUIRE(url.GetPort() == 8080);

		std::cout << "Test 6 passed\n";
	}
}

TEST_CASE("Invalid urls check")
{
	SECTION("Empty url")
	{
		std::cout << "Test 3: Empty url\n";


		try
		{
			CHttpUrl url("");
		}
		catch (const std::exception& e)
		{
			std::string err = e.what();
			REQUIRE(err == "Invalid url");
		}

		std::cout << "Test 3 passed\n";
	}

	SECTION("Url only without protocol")
	{
		std::cout << "Test 4: Url only without protocol\n";

		
		try
		{
			CHttpUrl url("google.com");
		}
		catch (const std::exception& e)
		{
			std::string err = e.what();
			REQUIRE(err == "Invalid url");
		}

		std::cout << "Test 4 passed\n";
	}

	SECTION("Url only with invalid protocol")
	{
		std::cout << "Test 5: Url only with invalid protocol\n";


		try
		{
			CHttpUrl url("abcd://google.com");
		}
		catch (const std::exception& e)
		{
			std::string err = e.what();
			REQUIRE(err == "Invalid url");
		}

		std::cout << "Test 5 passed\n";
	}

	SECTION("Url only with port lower min port")
	{
		std::cout << "Test 7: Url only with port lower min port\n";

		try
		{
			CHttpUrl url("http://localhost:0");
		}
		catch (const std::exception& e)
		{
			std::string err = e.what();
			REQUIRE(err == "Invalid port");
		}

		std::cout << "Test 7 passed\n";
	}

	SECTION("Url only with port higer max port")
	{
		std::cout << "Test 8: Url only with port higer max port\n";

		try
		{
			CHttpUrl url("http://localhost:65536");
		}
		catch (const std::exception& e)
		{
			std::string err = e.what();
			REQUIRE(err == "Invalid port");
		}

		std::cout << "Test 8 passed\n";
	}

	SECTION("Url only with non numeric port")
	{
		std::cout << "Test 9: Url only with non numeric port\n";

		try
		{
			CHttpUrl url("http://localhost:numeric");
		}
		catch (const std::exception& e)
		{
			std::string err = e.what();
			REQUIRE(err == "Invalid url");
		}

		std::cout << "Test 9 passed\n";
	}
}

TEST_CASE("Check Url with domain and document")
{
	SECTION("Url with domain and document and HTTP protocol")
	{
		std::cout << "Test 10: Url with domain and document and HTTP protocol\n";
		CHttpUrl url("google.com", "/document", Protocol::HTTP);
		REQUIRE(url.GetProtocol() == Protocol::HTTP);
		REQUIRE(url.GetDomain() == "google.com");
		REQUIRE(url.GetDocument() == "/document");
		REQUIRE(url.GetPort() == 80);
		std::cout << "Test 10 passed\n";
	}

	SECTION("Url with domain and document and HTTPS protocol")
	{
		std::cout << "Test 11: Url with domain and document and HTTPS protocol\n";
		CHttpUrl url("google.com", "/document", Protocol::HTTPS);
		REQUIRE(url.GetProtocol() == Protocol::HTTPS);
		REQUIRE(url.GetDomain() == "google.com");
		REQUIRE(url.GetDocument() == "/document");
		REQUIRE(url.GetPort() == 443);
		std::cout << "Test 11 passed\n";
	}

	SECTION("Url with invalid domain and valid document")
	{
		std::cout << "Test 12: Url with invalid domain and valid document\n";

		try
		{
			CHttpUrl url("", "/document", Protocol::HTTPS);
		}
		catch (const std::exception& e)
		{
			std::string err = e.what();
			REQUIRE(err == "Invalid domain");
		}

		std::cout << "Test 12 passed\n";
	}
}

TEST_CASE("Check Url with domain, document, protocol and ort")
{
	SECTION("Url with domain, document, protocol and valid port")
	{
		std::cout << "Test 13: Url with domain, document, protocol and valid port\n";
		CHttpUrl url("google.com", "/document", Protocol::HTTP, 500);
		REQUIRE(url.GetProtocol() == Protocol::HTTP);
		REQUIRE(url.GetDomain() == "google.com");
		REQUIRE(url.GetDocument() == "/document");
		REQUIRE(url.GetPort() == 500);
		std::cout << "Test 13 passed\n";
	}

	SECTION("Url with domain, document, protocol and port lower than min port")
	{
		std::cout << "Test 13: Url with domain, document, protocol and port lower than min port\n";
		try
		{
			CHttpUrl url("google.com", "/document", Protocol::HTTPS, 0);
		}
		catch (const std::exception& e)
		{
			std::string err = e.what();
			REQUIRE(err == "Invalid port");
		}
		std::cout << "Test 13 passed\n";
	}

	SECTION("Url with domain, document, protocol and port higer than max port")
	{
		std::cout << "Test 14: Url with domain, document, protocol and port lower than max port\n";
		try
		{
			CHttpUrl url("google.com", "/document", Protocol::HTTP, 65536);
		}
		catch (const std::exception& e)
		{
			std::string err = e.what();
			REQUIRE(err == "Invalid port");
		}
		std::cout << "Test 14 passed\n";
	}
}