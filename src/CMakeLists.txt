set(HEADERS
	UsdStage.h
	UsdStageRefPtr.h
	UsdStageWeakPtr.h
	UsdStagePtr.h
	UsdGeomScope.h
	UsdGeomXform.h
	UsdGeomMesh.h
	SdfLayerHandle.h
	SdfPath.h
	VtIntArray.h
	GfVec3f.h
	VtVec3fArray.h
	TfToken.h
	UsdPrim.h
	UsdGeomTokens.h
	UsdGeomPrimvar.h
	UsdShadeMaterial.h
	usdlib.h
)

set(SOURCES
	UsdStage.cpp
	UsdStageRefPtr.cpp
	UsdStageWeakPtr.cpp
	UsdGeomScope.cpp
	UsdGeomXform.cpp
	UsdGeomMesh.cpp
	SdfLayerHandle.cpp
	SdfPath.cpp
	VtIntArray.cpp
	GfVec3f.cpp
	VtVec3fArray.cpp
	TfToken.cpp
	UsdPrim.cpp
	UsdGeomTokens.cpp
	UsdGeomPrimvar.cpp
	UsdShadeMaterial.cpp
	usdlib.cpp
)

add_library(usdproxy SHARED ${HEADERS} ${SOURCES})
target_compile_definitions(usdproxy PUBLIC "-DNOMINMAX=1")
target_include_directories(usdproxy PUBLIC
		"${PXR_INCLUDE_DIRS}"
)
target_link_directories(usdproxy PUBLIC "c:/libs/usd/lib")
target_link_libraries(usdproxy PUBLIC
		Boost::filesystem
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
