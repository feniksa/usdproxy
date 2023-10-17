#include "PxrDiagnosticHandler.h"
#include <iostream>

namespace usdproxy
{

std::unique_ptr<PxrDiagnosticHandler> PxrDiagnosticHandler::GlobalDiagnosticHandler;

void PxrDiagnosticHandler::SetHandler(const DiagnosticHandler& handler)
{
	m_handler = handler;
}

void PxrDiagnosticHandler::IssueStatus(pxr::TfStatus const &status)
{
	m_handler.IssueStatus(status.GetCommentary());
}

void PxrDiagnosticHandler::IssueWarning(pxr::TfWarning const &warning)
{
	m_handler.IssueWarning(warning.GetCommentary());
}

void PxrDiagnosticHandler::IssueError(pxr::TfError const &err)
{
	m_handler.IssueError(err.GetCommentary());
}

void PxrDiagnosticHandler::IssueFatalError(pxr::TfCallContext const &context, std::string const &msg)
{
	m_handler.IssueFatalError(msg);
}

void PxrDiagnosticHandler::CreateGlobalDiagnosticHandler()
{
	GlobalDiagnosticHandler = std::make_unique<PxrDiagnosticHandler>();

	pxr::TfDiagnosticMgr& diagnosisInstance = pxr::TfDiagnosticMgr::GetInstance();
	diagnosisInstance.AddDelegate(GlobalDiagnosticHandler.get());
}

void PxrDiagnosticHandler::DestroyGlobalDiagnosticHandler()
{
	GlobalDiagnosticHandler.reset();
}

void PxrDiagnosticHandler::RegisterDiagnosticHandler(const DiagnosticHandler& handler)
{
	if (!GlobalDiagnosticHandler)
		return;

	GlobalDiagnosticHandler->SetHandler(handler);
}

}
