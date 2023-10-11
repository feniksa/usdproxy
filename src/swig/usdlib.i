%module usdlib

%{
#include "usdlib.h"

using namespace usdproxy;
%}

%include "windows.i"
%include "std_string.i"
%include "usdlib.h"

%include "UsdPrim.i"
%include "TfToken.i"

%include "UsdStageRefPtr.i"
%include "UsdStageWeakPtr.i"
%include "UsdStagePtr.i"

%include "SdfLayerHandle.i"
%include "UsdStage.i"
%include "SdfPath.i"
%include "SdfAssetPath.i"
%include "UsdGeomXformOp.i"
%include "UsdGeomTokens.i"
%include "UsdGeomScope.i"
%include "UsdGeomXform.i"
%include "UsdGeomMesh.i"
%include "GfVec2d.i"
%include "GfVec2f.i"
%include "GfMatrix4d.i"
%include "VtIntArray.i"
%include "VtVec2fArray.i"
%include "GfVec3f.i"
%include "GfVec3d.i"
%include "GfRotation.i"
%include "GfQuatd.i"
%include "GfQuath.i"
%include "VtVec3fArray.i"
%include "VtQuathArray.i"
%include "UsdAttribute.i"
%include "UsdGeomPointInstancer.i"
%include "UsdShadeShader.i"
%include "UsdShadeConnectableAPI.i"
%include "UsdShadeOutput.i"
%include "UsdShadeMaterial.i"
%include "UsdRelationship.i"
%include "SdfValueTypeName.i"

