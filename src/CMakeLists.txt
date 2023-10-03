set(HEADERS
		usdlib.h
)

set(SOURCES
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

#set(SWIG_DIR "${CMAKE_SOURCE_DIR}/ThirdParty/swigwin-4.1.1")
set(SWIG_EXECUTABLE "${CMAKE_SOURCE_DIR}/ThirdParty/swigwin-4.1.1/swig.exe")

find_package(SWIG 4.0 REQUIRED)
include(${SWIG_USE_FILE})

include_directories(
		${USD_INCLUDE_DIR}
		# Not sure how to avoid setting the boost include path explicitly
#		${USD_INCLUDE_DIR}/boost-1_70
		${CMAKE_CURRENT_SOURCE_DIR}
		${CMAKE_SOURCE_DIR}
)

set_property(SOURCE usdlib.i PROPERTY CPLUSPLUS ON)
swig_add_library(UsdProxyCs
		TYPE MODULE
		LANGUAGE csharp
		OUTPUT_DIR "${CMAKE_BINARY_DIR}/generated"
		SOURCES
		usdlib.i
)
set_target_properties(UsdProxyCs PROPERTIES CXX_STANDARD_REQUIRED 14)
swig_link_libraries(UsdProxyCs usdproxy)


#add_custom_command(TARGET usdproxy POST_BUILD COMMAND "${CMAKE_SOURCE_DIR}/ThirdParty/swigwin-4.1.1/swig.exe"
#		ARGS "-Wall" "-csharp" "-namespace" "usdlib" "-outdir" "${CMAKE_CURRENT_SOURCE_DIR}/generated" "-c++" "${CMAKE_CURRENT_SOURCE_DIR}/usdlib.i")

#swig_add_library(usdlibcs
#		TYPE MODULE
#		LANGUAGE csharp
#		OUTPUT_DIR ${SWIG_GENERATED_FILEDIR}
#		SOURCES
#		${USD_CS_SWIG_SHIM}
#		diagnosticHandler.cpp
#		dll_main.cpp
#)


#if (COPY_DLLS)
#	set(USD_ROOT "d:/workspace2/usd")
#	file(GLOB DLLS "${USD_ROOT}/bin/*.dll")
#	foreach (dll ${DLLS})
#		get_filename_component(dll_name "${dll}" NAME)
#		add_custom_command(TARGET main POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different "${dll}" "${CMAKE_CURRENT_BINARY_DIR}/${dll_name}")
#	endforeach ()
#	file(GLOB DLLS "${USD_ROOT}/lib/*.dll")
#	foreach (dll ${DLLS})
#		get_filename_component(dll_name "${dll}" NAME)
#		add_custom_command(TARGET main POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different "${dll}" "${CMAKE_CURRENT_BINARY_DIR}/${dll_name}")
#	endforeach ()
#endif()

include(GNUInstallDirs)

set_target_properties(usdproxy PROPERTIES PUBLIC_HEADER usdproxy.h)
install(TARGETS usdproxy PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})