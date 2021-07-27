cmake_minimum_required(VERSION 3.10)

if (WIN32)
	add_compile_options(/W3)
    option(WINHTTP "Use WIN32 sockets" ON)
endif (WIN32)

if (UNIX)
	add_compile_options(-Wall -Wextra -pedantic -Werror)
	option(CURL "Use libcurl" ON)
endif (UNIX)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file(Config.h.in Config.h.in)

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

target_link_libraries(JsonDesLib PUBLIC library PAL)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

