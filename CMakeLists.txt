################################################################################
# Generated with Skylar Cupit's json-to-cmake tool                             #
# GitHub: https://github.com/scupit/json-to-cmake-rewrite                      #
################################################################################

cmake_minimum_required( VERSION 3.12 )
project( gcmake-groups-test )

# ////////////////////////////////////////////////////////////////////////////////
# LANGUAGE STANDARDS
# ////////////////////////////////////////////////////////////////////////////////

set( CMAKE_C_STANDARD 99 CACHE STRING "C compiler standard year" )
set_property( CACHE CMAKE_C_STANDARD PROPERTY STRINGS 99 )
message( "Using C compiler standard --std=c${CMAKE_C_STANDARD}" )

set( CMAKE_CXX_STANDARD 11 CACHE STRING "CXX compiler standard year" )
set_property( CACHE CMAKE_CXX_STANDARD PROPERTY STRINGS 11 )
message( "Using CXX compiler standard --std=c++${CMAKE_CXX_STANDARD}" )

set( CMAKE_C_STANDARD_REQUIRED ON )
set( CMAKE_CXX_STANDARD_REQUIRED ON )

set( CMAKE_C_EXTENSIONS OFF )
set( CMAKE_CXX_EXTENSIONS OFF )

# ////////////////////////////////////////////////////////////////////////////////
# BUILD TARGETS
# ////////////////////////////////////////////////////////////////////////////////

set_property( CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" )

if( "${CMAKE_BUILD_TYPE}" STREQUAL "" )
	set( CMAKE_BUILD_TYPE "Debug" CACHE STRING "Project Configuration" FORCE )
endif()

if( "${CMAKE_BUILD_TYPE}" STREQUAL "Debug" )
	set( CMAKE_CXX_FLAGS "-g -Wall -Wextra -Wconversion -Wuninitialized -pedantic -pedantic-errors " )
	set( CMAKE_C_FLAGS "-g -Wall -Wextra -Wconversion -Wuninitialized -pedantic -pedantic-errors " )
elseif( "${CMAKE_BUILD_TYPE}" STREQUAL "Release" )
	set( CMAKE_CXX_FLAGS "-O2 -DNDEBUG -s " )
	set( CMAKE_C_FLAGS "-O2 -DNDEBUG -s " )
endif()

message( "Using compiler flags: ${CMAKE_CXX_FLAGS}" )
message( "Building project '${CMAKE_BUILD_TYPE}' configuration" )

# ////////////////////////////////////////////////////////////////////////////////
# IMPORTED LIBRARIES (none)
# ////////////////////////////////////////////////////////////////////////////////

# ////////////////////////////////////////////////////////////////////////////////
# OUTPUT SHARED LIBRARIES (none)
# ////////////////////////////////////////////////////////////////////////////////

# ////////////////////////////////////////////////////////////////////////////////
# OUTPUT STATIC LIBRARIES (none)
# ////////////////////////////////////////////////////////////////////////////////

# ////////////////////////////////////////////////////////////////////////////////
# LIBRARY OUTPUT GROUPS 
# ////////////////////////////////////////////////////////////////////////////////

# Output Group g_grouped_libs
set( g_grouped_libs_HEADERS
)

set( g_grouped_libs_SOURCES
)

set( g_grouped_libs_INCLUDE_DIRS
	${PROJECT_SOURCE_DIR}/include
)

# Output static library: math_lib
set( math_lib_HEADERS
	${g_grouped_libs_HEADERS}
	${PROJECT_SOURCE_DIR}/include/math/Doubler.hpp
	${PROJECT_SOURCE_DIR}/include/math/Halver.hpp
)

set( math_lib_SOURCES
	${math_lib_HEADERS}
	${g_grouped_libs_SOURCES}
	${PROJECT_SOURCE_DIR}/src/math/Doubler.cpp
	${PROJECT_SOURCE_DIR}/src/math/Halver.cpp
)

set( math_lib_INCLUDE_DIRS
	${g_grouped_libs_INCLUDE_DIRS}
)

add_library( math_lib STATIC ${math_lib_SOURCES} )
target_include_directories( math_lib PRIVATE ${math_lib_INCLUDE_DIRS} )

set_target_properties( math_lib PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/${CMAKE_BUILD_TYPE}
	LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/${CMAKE_BUILD_TYPE}
)

# Output static library: printing
set( printing_HEADERS
	${g_grouped_libs_HEADERS}
	${PROJECT_SOURCE_DIR}/include/printing/Hello.hpp
	${PROJECT_SOURCE_DIR}/include/printing/Moo.hpp
)

set( printing_SOURCES
	${printing_HEADERS}
	${g_grouped_libs_SOURCES}
	${PROJECT_SOURCE_DIR}/src/printing/Hello.cpp
	${PROJECT_SOURCE_DIR}/src/printing/Moo.cpp
)

set( printing_INCLUDE_DIRS
	${g_grouped_libs_INCLUDE_DIRS}
)

add_library( printing STATIC ${printing_SOURCES} )
target_include_directories( printing PRIVATE ${printing_INCLUDE_DIRS} )

set_target_properties( printing PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/${CMAKE_BUILD_TYPE}
	LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/${CMAKE_BUILD_TYPE}
)

# ////////////////////////////////////////////////////////////////////////////////
# EXECUTABLE OUTPUT GROUPS 
# ////////////////////////////////////////////////////////////////////////////////

# Output Group g_exes
set( g_exes_HEADERS
)

set( g_exes_SOURCES
)

set( g_exes_INCLUDE_DIRS
)

# Output executable: main
set( main_HEADERS
	${g_exes_HEADERS}
	${math_lib_HEADERS}
	${printing_HEADERS}
)

set( main_SOURCES
	${main_HEADERS}
	${g_exes_SOURCES}
	${PROJECT_SOURCE_DIR}/main.cpp
)

set( main_INCLUDE_DIRS
	${g_exes_INCLUDE_DIRS}
	${math_lib_INCLUDE_DIRS}
	${printing_INCLUDE_DIRS}
)

add_executable( main ${main_SOURCES} )
target_include_directories( main PRIVATE ${main_INCLUDE_DIRS} )

set_target_properties( main PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE}
)

# Output executable: not_linked
set( not_linked_HEADERS
	${g_exes_HEADERS}
	${printing_HEADERS}
)

set( not_linked_SOURCES
	${not_linked_HEADERS}
	${g_exes_SOURCES}
	${PROJECT_SOURCE_DIR}/not_linked_main.cpp
)

set( not_linked_INCLUDE_DIRS
	${g_exes_INCLUDE_DIRS}
	${printing_INCLUDE_DIRS}
)

add_executable( not_linked ${not_linked_SOURCES} )
target_include_directories( not_linked PRIVATE ${not_linked_INCLUDE_DIRS} )

set_target_properties( not_linked PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE}
)

# ////////////////////////////////////////////////////////////////////////////////
# OUTPUT EXECUTABLES (none)
# ////////////////////////////////////////////////////////////////////////////////

# ////////////////////////////////////////////////////////////////////////////////
# LINK LIBRARIES TO OUTPUTS
# ////////////////////////////////////////////////////////////////////////////////

target_link_libraries( main
	printing 
	math_lib 
)

target_link_libraries( not_linked
	printing 
)

