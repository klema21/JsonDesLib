cmake_minimum_required(VERSION 3.13)


if (WIN32)
	add_compile_options(/W3)
    option(WINHTTP "Use WIN32 sockets" ON)
endif (WIN32)

if (UNIX)
	#	-Werror -fsanitize=thread
	#add_compile_options(-Wall -Wextra -pedantic -pthread -fsanitize=address -O2)
	add_compile_options(-Wall -Wextra -pedantic -pthread -pthread -O0)
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
	option(CURL "Use libcurl" ON)
endif (UNIX)

# set the project name
project(JsonDesLib)

#set project source folder:
INCLUDE_DIRECTORIES(
    ${CMAKE_CURRENT_SOURCE_DIR}/include/
    ${CMAKE_CURRENT_SOURCE_DIR}/test/
)

add_subdirectory(library)
add_subdirectory(PAL)

add_executable(JsonDesLib main.cc)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

if(WINHTTP)
	set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
	FetchContent_MakeAvailable(googletest)
	target_link_libraries(JsonDesLib PUBLIC library PAL)
endif(WINHTTP)
if(CURL)
	target_link_libraries(JsonDesLib PUBLIC library PAL curl -fsanitize=address)
endif(CURL)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

enable_testing()

add_executable(
  hello_test
  test/hello_test.cc
)

if(WINHTTP)
	target_link_libraries(
	  hello_test
	  gtest_main
	  library
	  PAL
	)
endif(WINHTTP)

if(CURL)

	find_package(GTest REQUIRED)
	include_directories(${GTEST_INCLUDE_DIRS}) 

    target_link_libraries(
	hello_test
	gtest_main
	${GTEST_LIBRARIES} pthread
	library
	PAL
	curl
    )
endif(CURL)

include(GoogleTest)
gtest_discover_tests(hello_test)
