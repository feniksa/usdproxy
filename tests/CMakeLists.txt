include(FetchContent)
FetchContent_Declare(
		googletest
		URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
		DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

find_package(GTest REQUIRED)

set(HEADERS

)
set(SOURCES

)

set (TESTS
	Usd
)

foreach(test ${TESTS})
	add_test(
			NAME ${test}
			COMMAND tests_main --gtest_filter=Test${test}.*
			WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
		)
		set (TEST_SOURCES ${TEST_SOURCES} Test${test}.cpp)
endforeach()

add_executable(tests_main ${TEST_SOURCES} ${TEST_HEADERS})
target_link_libraries(tests_main
	GTest::gtest
	GTest::gtest_main
	usdproxy
)

target_include_directories(tests_main
	PRIVATE
	"${CMAKE_SOURCE_DIR}/src"
	"${CMAKE_CURRENT_BINARY_DIR}"
)
configure_file(Environment.h.in ${CMAKE_CURRENT_BINARY_DIR}/Environment.h @ONLY)

message(STATUS "Copy USD main libraries")
set(USD_ROOT "c:/libs/usd")
file(GLOB DLLS "${USD_ROOT}/bin/*.dll")
foreach (dll ${DLLS})
	get_filename_component(dll_name "${dll}" NAME)
	add_custom_command(TARGET tests_main POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different "${dll}" "${CMAKE_CURRENT_BINARY_DIR}/${dll_name}")
endforeach ()
file(GLOB DLLS "${USD_ROOT}/lib/*.dll")
foreach (dll ${DLLS})
	get_filename_component(dll_name "${dll}" NAME)
	add_custom_command(TARGET tests_main POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different "${dll}" "${CMAKE_CURRENT_BINARY_DIR}/${dll_name}")
endforeach ()

message(STATUS "Copy USD library runtime deps")
set(USD_DEPS "c:/libs/usdbuild")
file(GLOB DLLS "${USD_DEPS}/libs/bin/*.dll")
foreach (dll ${DLLS})
	get_filename_component(dll_name "${dll}" NAME)
	add_custom_command(TARGET tests_main POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different "${dll}" "${CMAKE_CURRENT_BINARY_DIR}/${dll_name}")
endforeach ()
file(GLOB DLLS "${USD_DEPS}/libs/lib/*.dll")
foreach (dll ${DLLS})
	get_filename_component(dll_name "${dll}" NAME)
	add_custom_command(TARGET tests_main POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different "${dll}" "${CMAKE_CURRENT_BINARY_DIR}/${dll_name}")
endforeach ()

message(STATUS "Copy usd library resources")
add_custom_command(TARGET tests_main POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory "${USD_ROOT}/lib/usd" "${CMAKE_CURRENT_BINARY_DIR}/usd")

message(STATUS "Copy runtime library")
add_custom_command(TARGET tests_main POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different "${CMAKE_BINARY_DIR}/src/usdproxy.dll" "${CMAKE_CURRENT_BINARY_DIR}/usdproxy.dll")
