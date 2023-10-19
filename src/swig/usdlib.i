%module usdlib

%{
#include "usdlib.h"

using namespace usdproxy;
%}

%include "windows.i"
%include "std_string.i"
%include "usdlib.h"

%include "UsdPrim.i"
%include "UsdGeomPrimvarsAPI.i"
%include "TfToken.i"

%include "UsdStage.i"
%include "UsdStageRefPtr.i"
%include "UsdStageWeakPtr.i"
%include "UsdStagePtr.i"
%include "UsdReferences.i"

%include "SdfLayerHandle.i"
%include "SdfPath.i"
%include "SdfAssetPath.i"
%include "UsdGeomXformOp.i"
%include "UsdGeomTokens.i"
%include "UsdGeomScope.i"
%include "UsdGeomXform.i"
%include "UsdGeomMesh.i"
%include "UsdGeomCamera.i"
%include "GfVec2i.i"
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
%include "GfCamera.i"
%include "VtVec2iArray.i"
%include "VtVec3fArray.i"
%include "VtQuathArray.i"
%include "UsdAttribute.i"
%include "UsdGeomPointInstancer.i"
%include "UsdShadeShader.i"
%include "UsdShadeConnectableAPI.i"
%include "UsdShadeOutput.i"
%include "UsdShadeMaterial.i"
%include "UsdLuxNonboundableLightBase.i"
%include "UsdLuxDistantLight.i"
%include "UsdLuxDomeLight.i"
%include "UsdRelationship.i"
%include "UsdTimeCode.i"
%include "SdfValueTypeName.i"
%include "GfHalf.i"
%include "DiagnosticHandler.i"
%include "PxrDiagnosticHandler.i"


