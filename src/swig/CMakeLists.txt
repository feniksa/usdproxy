#set(SWIG_DIR "${CMAKE_SOURCE_DIR}/ThirdParty/swigwin-4.1.1")
set(SWIG_EXECUTABLE "${CMAKE_SOURCE_DIR}/ThirdParty/swigwin-4.1.1/swig.exe")

find_package(SWIG 4.0 REQUIRED)
include(${SWIG_USE_FILE})

include_directories(
        ${PXR_INCLUDE_DIRS}
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/src
)


foreach(header IN LISTS HEADERS)
    list(APPEND SWIG_HEADERS "${CMAKE_SOURCE_DIR}/src/${header}")
endforeach()

foreach(source IN LISTS SOURCES)
    list(APPEND SWIG_CPP "${CMAKE_SOURCE_DIR}/src/${source}")
endforeach()
add_custom_target(SwigFilesFakeDep ALL DEPENDS ${SWIG_HEADERS} ${SWIG_CPP})

#set_property(SOURCE usdlib.i PROPERTY SWIG_MODULE_NAME mymod_realname)
set_property(SOURCE usdlib.i PROPERTY CPLUSPLUS ON)
set(CMAKE_SWIG_FLAGS "-namespace" "USDPROXY.NET")
swig_add_library(UsdProxyCs
        TYPE MODULE
        LANGUAGE csharp
        OUTPUT_DIR "${CMAKE_CURRENT_BINARY_DIR}"
        SOURCES
        usdlib.i
)

set_target_properties(UsdProxyCs PROPERTIES CXX_STANDARD_REQUIRED 14)
swig_link_libraries(UsdProxyCs usdproxy)
add_dependencies(UsdProxyCs SwigFilesFakeDep)

# Tag the generated folders so they are removed when doing calling the clean target
# Doesn't work with the VC generator ...
set_target_properties(UsdProxyCs PROPERTIES ADDITIONAL_CLEAN_FILES "${CMAKE_BINARY_DIR}/*.cs;")

file(GLOB CSS CONFIGURE_DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/*.cs")
foreach (csfile ${CSS})
    install(FILES "${csfile}" DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
endforeach ()

#set_target_properties(usdproxy PROPERTIES PUBLIC_HEADERS "usdlib.h")
install(TARGETS UsdProxyCs DESTINATION ${CMAKE_INSTALL_LIBDIR})