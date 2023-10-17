%module(directors="1") DiagnosticHandler

%{
#include "DiagnosticHandler.h"
%}

%feature("director") DiagnosticHandler;
%include "DiagnosticHandler.h"

