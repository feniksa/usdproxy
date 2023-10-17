#include "DiagnosticHandler.h"
#include <iostream>

namespace usdproxy
{

DiagnosticHandler::~DiagnosticHandler()
{
}

void DiagnosticHandler::IssueStatus(const std::string& msg)
{
	std::cerr << "USD: " << msg << std::endl;
}

void DiagnosticHandler::IssueWarning(const std::string& msg)
{
	std::cerr << "USD: " << msg << std::endl;
}

void DiagnosticHandler::IssueError(const std::string& msg)
{
	std::cerr << "USD: " << msg << std::endl;
}

void DiagnosticHandler::IssueFatalError(const std::string& msg)
{
	std::cerr << "USD: " << msg << std::endl;
}
}