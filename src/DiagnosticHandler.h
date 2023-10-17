#pragma once

#include "usdlib.h"
#include <string>

namespace usdproxy
{

class DiagnosticHandler
{
public:
	LIBUSDPROXY_API
	virtual
	~DiagnosticHandler();

	LIBUSDPROXY_API
	virtual
	void IssueStatus(const std::string& msg);

	LIBUSDPROXY_API
	virtual
	void IssueWarning(const std::string& msg);

	LIBUSDPROXY_API
	virtual
	void IssueError(const std::string& msg);

	LIBUSDPROXY_API
	virtual
	void IssueFatalError(const std::string& msg);
private:
};

}
