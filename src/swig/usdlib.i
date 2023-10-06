%module usdlib

%{
#include "usdlib.h"

    using namespace usdproxy;
%}

%include "windows.i"
%include "std_string.i"
%include "usdlib.h"

%include "UsdStageRefPtr.i"
%include "UsdStageWeakPtr.i"
%include "SdfLayerHandle.i"
%include "UsdStage.i"
%include "SdfPath.i"
