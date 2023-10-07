%module usdlib

%{
#include "usdlib.h"

using namespace usdproxy;
%}

%include "windows.i"
%include "std_string.i"
%include "usdlib.h"

%include "UsdPrim.i"

%include "UsdStageRefPtr.i"
%include "UsdStageWeakPtr.i"
%include "UsdStagePtr.i"

%include "SdfLayerHandle.i"
%include "UsdStage.i"
%include "SdfPath.i"
%include "UsdGeomScope.i"
%include "UsdGeomMesh.i"
%include "VtIntArray.i"
%include "GfVec3f.i"
%include "VtVec3fArray.i"

