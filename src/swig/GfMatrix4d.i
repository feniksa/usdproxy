%module GfMatrix4d

%{
#include "GfMatrix4d.h"
%}
%include "arrays_csharp.i"

%apply double INPUT[]  { double* transformation }
%include "GfMatrix4d.h"

