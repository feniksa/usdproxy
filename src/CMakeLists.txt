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

add_custom_command(TARGET usdproxy POST_BUILD COMMAND "${CMAKE_SOURCE_DIR}/ThirdParty/swigwin-4.1.1/swig.exe"
		ARGS "-Wall" "-csharp" "-namespace" "usdlib" "-outdir" "${CMAKE_CURRENT_SOURCE_DIR}/generated" "-c++" "${CMAKE_CURRENT_SOURCE_DIR}/usdlib.i")

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

set_target_properties(usdproxy PROPERTIES PUBLIC_HEADER usdproxy.h)
include(GNUInstallDirs)
install(TARGETS usdproxy PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})