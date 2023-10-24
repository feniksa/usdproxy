cmake_minimum_required (VERSION 3.16)
project (usdproxy CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

option(FORCE_COLORED_OUTPUT "Always produce ANSI-colored output (GNU/Clang only)." FALSE)
option(ENABLE_TESTING "Enable testing" TRUE)
option(EXPORT "Export sybmols" TRUE)

include("${CMAKE_SOURCE_DIR}/cmake/CompileOptions.cmake")
find_package(Boost REQUIRED COMPONENTS regex atomic)
find_package(pxr REQUIRED)

set(USD_DEPS "c:/libs/usdbuild")
set(USD_ROOT "c:/libs/usd")

add_subdirectory(src)
if(ENABLE_TESTING)
	enable_testing()
	add_subdirectory(tests)
endif()
