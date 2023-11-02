set(HEADERS
	UsdStage.h
	UsdStageRefPtr.h
	UsdStageWeakPtr.h
	UsdStagePtr.h
	UsdGeomXformOp.h
	UsdGeomScope.h
	UsdGeomXform.h
	UsdGeomMesh.h
	UsdRelationship.h
	UsdReferences.h
	SdfLayerHandle.h
	SdfPath.h
	SdfAssetPath.h
	VtIntArray.h
	VtVec2fArray.h
	VtVec2iArray.h
	GfVec3f.h
	GfVec3d.h
	GfVec2i.h
	GfVec2d.h
	GfVec2f.h
	GfQuath.h
	GfRotation.h
	GfMatrix4d.h
	GfQuatd.h
	GfHalf.h
	GfCamera.h
	VtVec3fArray.h
	VtVec3dArray.h
	VtQuathArray.h
	VtQuatdArray.h
	TfToken.h
	UsdPrim.h
	UsdGeomPrimvarsAPI.h
	UsdGeomPointInstancer.h
	UsdGeomTokens.h
	UsdGeomPrimvar.h
	UsdGeomCamera.h
	UsdAttribute.h
	UsdTimeCode.h
	SdfValueTypeName.h
	UsdSchemaBase.h
	UsdShadeInput.h
	UsdShadeShader.h
	UsdShadeMaterial.h
	UsdShadeConnectableAPI.h
	UsdShadeOutput.h
	UsdLuxDistantLight.h
	UsdLuxDomeLight.h
	UsdLuxNonboundableLightBase.h
	UsdModelAPI.h
	DiagnosticHandler.h
	PxrDiagnosticHandler.h
	KindToken.h
	usdlib.h
	PlugPlugin.h
	PlugPluginPtrVector.h
	PlugRegistry.h
)

set(SOURCES
	UsdStage.cpp
	UsdStageRefPtr.cpp
	UsdStageWeakPtr.cpp
	UsdGeomXformOp.cpp
	UsdGeomScope.cpp
	UsdGeomXform.cpp
	UsdGeomMesh.cpp
	UsdRelationship.cpp
	UsdReferences.cpp
	SdfLayerHandle.cpp
	SdfPath.cpp
	SdfAssetPath.cpp
	VtIntArray.cpp
	VtVec2fArray.cpp
	VtVec2iArray.cpp
	VtQuathArray.cpp
	VtQuatdArray.cpp
	GfVec3f.cpp
	GfVec3d.cpp
	GfVec2i.cpp
	GfVec2d.cpp
	GfVec2f.cpp
	GfQuath.cpp
	GfHalf.cpp
	GfRotation.cpp
	GfMatrix4d.cpp
	GfQuatd.cpp
	GfCamera.cpp
	VtVec3fArray.cpp
	VtVec3dArray.cpp
	TfToken.cpp
	UsdPrim.cpp
	UsdSchemaBase.cpp
	UsdGeomPrimvarsAPI.cpp
	UsdGeomPointInstancer.cpp
	UsdGeomTokens.cpp
	UsdGeomPrimvar.cpp
	UsdAttribute.cpp
	UsdTimeCode.cpp
	UsdGeomCamera.cpp
	SdfValueTypeName.cpp
	UsdModelAPI.cpp
	UsdShadeInput.cpp
	UsdShadeShader.cpp
	UsdShadeMaterial.cpp
	UsdShadeConnectableAPI.cpp
	UsdShadeOutput.cpp
	UsdLuxDistantLight.cpp
	UsdLuxDomeLight.cpp
	UsdLuxNonboundableLightBase.cpp
	DiagnosticHandler.cpp
	PxrDiagnosticHandler.cpp
	KindToken.cpp
	usdlib.cpp
	PlugPlugin.cpp
	PlugPluginPtrVector.cpp
	PlugRegistry.cpp
)

add_library(usdproxy SHARED ${HEADERS} ${SOURCES})
target_compile_definitions(usdproxy PUBLIC "-DNOMINMAX=1")
target_include_directories(usdproxy PUBLIC
		"${PXR_INCLUDE_DIRS}"
)
target_link_directories(usdproxy PUBLIC "c:/libs/usd/lib")
target_link_libraries(usdproxy PUBLIC
		Boost::atomic Boost::regex
		"${PXR_LIBRARIES}"
)
if (EXPORT)
	target_compile_definitions(usdproxy PRIVATE "-DEXPORT=1")
endif()

include(GNUInstallDirs)

install(TARGETS usdproxy DESTINATION ${CMAKE_INSTALL_LIBDIR})
message(STATUS "Install USD plugins dir")
install(DIRECTORY "${USD_ROOT}/lib/usd" DESTINATION ${CMAKE_INSTALL_LIBDIR})

message(STATUS "Install USD main libraries")
file(GLOB DLLS "${USD_ROOT}/bin/*.dll")
foreach (dll ${DLLS})
	get_filename_component(dll_name "${dll}" NAME)
	install(FILES "${dll}" DESTINATION ${CMAKE_INSTALL_LIBDIR})
endforeach ()
file(GLOB DLLS "${USD_ROOT}/lib/*.dll")
foreach (dll ${DLLS})
	get_filename_component(dll_name "${dll}" NAME)
	install(FILES "${dll}" DESTINATION ${CMAKE_INSTALL_LIBDIR})
endforeach ()

message(STATUS "Install USD library runtime deps")
file(GLOB DLLS "${USD_DEPS}/libs/bin/*.dll")
foreach (dll ${DLLS})
	get_filename_component(dll_name "${dll}" NAME)
	install(FILES  "${dll}" DESTINATION "${CMAKE_INSTALL_LIBDIR}")
endforeach ()
file(GLOB DLLS "${USD_DEPS}/libs/lib/*.dll")
foreach (dll ${DLLS})
	get_filename_component(dll_name "${dll}" NAME)
	install(FILES "${dll}" DESTINATION "${CMAKE_INSTALL_LIBDIR}")
endforeach ()
#
#message(STATUS "Copy usd library resources")
#add_custom_command(TARGET tests_main POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory "${USD_ROOT}/lib/usd" "${CMAKE_CURRENT_BINARY_DIR}/usd")

add_subdirectory(swig)
