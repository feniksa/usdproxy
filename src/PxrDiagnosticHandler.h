#pragma once

#include "usdlib.h"

#include "DiagnosticHandler.h"

#include <pxr/base/tf/diagnostic.h>
#include <pxr/base/tf/diagnosticMgr.h>

#include <string>

namespace usdproxy
{

class PxrDiagnosticHandler: public pxr::TfDiagnosticMgr::Delegate
{
public:
	LIBUSDPROXY_API
	PxrDiagnosticHandler() = default;

	LIBUSDPROXY_API
	PxrDiagnosticHandler(const PxrDiagnosticHandler&) = default;

	LIBUSDPROXY_API
	void SetHandler(const DiagnosticHandler& handler);

	/// Informational messages.
	LIBUSDPROXY_API
	void IssueStatus(pxr::TfStatus const &status) override;

	/// Diagnostic warning messages.
	LIBUSDPROXY_API
	void IssueWarning(pxr::TfWarning const &warning) override;

	/// Recoverable error messages, which should be treated as non-fatal exceptions.
	LIBUSDPROXY_API
	void IssueError(pxr::TfError const &err) override;

	/// Messages recieved here will occur just before the application aborts.
	LIBUSDPROXY_API
	void IssueFatalError(const pxr::TfCallContext &context, const std::string &msg) override;

	LIBUSDPROXY_API
	static
	void CreateGlobalDiagnosticHandler();

	LIBUSDPROXY_API
	static
	void DestroyGlobalDiagnosticHandler();

	LIBUSDPROXY_API
	static
	void RegisterDiagnosticHandler(const DiagnosticHandler& handler);

private:
	static std::unique_ptr<PxrDiagnosticHandler> GlobalDiagnosticHandler;
	DiagnosticHandler m_handler;
};

}