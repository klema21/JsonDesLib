cmake_minimum_required(VERSION 3.10)

if (WIN32)
	add_compile_options(/W3)
    	option(WINHTTP "Use WIN32 sockets" ON)
endif (WIN32)

if (UNIX)
	add_compile_options(-Wall -Wextra -pedantic -fsanitize=address) # -Werror
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

if(WINHTTP)
	target_link_libraries(JsonDesLib PUBLIC library PAL)
endif(WINHTTP)
if(CURL)
	target_link_libraries(JsonDesLib PUBLIC library PAL curl -fsanitize=address)
endif(CURL)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
