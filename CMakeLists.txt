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
# IMPORTED LIBRARIES 
# ////////////////////////////////////////////////////////////////////////////////

# Imported lib: matrices
set( matrices_INCLUDE_DIRS
	${PROJECT_SOURCE_DIR}/dep/include
)

set( matrices_HEADERS
	${PROJECT_SOURCE_DIR}/dep/include/matrices/Matrix.hpp
)

find_library( matrices_0
	NAMES matrices
	PATHS ${PROJECT_SOURCE_DIR}/dep/lib/matrices
)

# ////////////////////////////////////////////////////////////////////////////////
# OUTPUT SHARED LIBRARIES 
# ////////////////////////////////////////////////////////////////////////////////

# Output shared library: quick-header 
set( quick-header_HEADERS
	${PROJECT_SOURCE_DIR}/include/QuickHeader.hpp
)

set( quick-header_SOURCES
	${quick-header_HEADERS}
	${PROJECT_SOURCE_DIR}/src/QuickHeader.cpp
)

set( quick-header_INCLUDE_DIRS
	${PROJECT_SOURCE_DIR}/include
)

add_library( quick-header SHARED ${quick-header_SOURCES} )
target_include_directories( quick-header PRIVATE ${quick-header_INCLUDE_DIRS} )

set_target_properties( quick-header PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/${CMAKE_BUILD_TYPE}
	LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/${CMAKE_BUILD_TYPE}
	RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE}
)

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
	${matrices_HEADERS}
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
	${matrices_INCLUDE_DIRS}
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
	${quick-header_HEADERS}
	${math_lib_HEADERS}
	${printing_HEADERS}
)

set( g_exes_SOURCES
	${g_exes_HEADERS}
)

set( g_exes_INCLUDE_DIRS
	${quick-header_INCLUDE_DIRS}
	${math_lib_INCLUDE_DIRS}
	${printing_INCLUDE_DIRS}
)

# Output executable: main
set( main_HEADERS
	${g_exes_HEADERS}
)

set( main_SOURCES
	${main_HEADERS}
	${g_exes_SOURCES}
	${PROJECT_SOURCE_DIR}/main.cpp
)

set( main_INCLUDE_DIRS
	${g_exes_INCLUDE_DIRS}
)

add_executable( main ${main_SOURCES} )
target_include_directories( main PRIVATE ${main_INCLUDE_DIRS} )

set_target_properties( main PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE}
)

# Output executable: matrix-main
set( matrix-main_HEADERS
	${g_exes_HEADERS}
)

set( matrix-main_SOURCES
	${matrix-main_HEADERS}
	${g_exes_SOURCES}
	${PROJECT_SOURCE_DIR}/matrix_main.cpp
)

set( matrix-main_INCLUDE_DIRS
	${g_exes_INCLUDE_DIRS}
)

add_executable( matrix-main ${matrix-main_SOURCES} )
target_include_directories( matrix-main PRIVATE ${matrix-main_INCLUDE_DIRS} )

set_target_properties( matrix-main PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE}
)

# ////////////////////////////////////////////////////////////////////////////////
# OUTPUT EXECUTABLES 
# ////////////////////////////////////////////////////////////////////////////////

# Output executable: matrix-main-2
set( matrix-main-2_HEADERS
	${math_lib_HEADERS}
	${quick-header_HEADERS}
)

set( matrix-main-2_SOURCES
	${matrix-main-2_HEADERS}
	${PROJECT_SOURCE_DIR}/matrix_main_2.cpp
)

set( matrix-main-2_INCLUDE_DIRS
	${math_lib_INCLUDE_DIRS}
	${quick-header_INCLUDE_DIRS}
)

add_executable( matrix-main-2 ${matrix-main-2_SOURCES} )
target_include_directories( matrix-main-2 PRIVATE ${matrix-main-2_INCLUDE_DIRS} )

set_target_properties( matrix-main-2 PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE}
)

# ////////////////////////////////////////////////////////////////////////////////
# LINK LIBRARIES TO OUTPUTS
# ////////////////////////////////////////////////////////////////////////////////

target_link_libraries( main
	math_lib 
	quick-header 
	printing 
)

target_link_libraries( matrix-main
	math_lib 
	quick-header 
	printing 
)

target_link_libraries( math_lib
	${matrices_0}
)

target_link_libraries( matrix-main-2
	math_lib 
	quick-header 
)

# ////////////////////////////////////////////////////////////////////////////////
# IMPORTED LIBRARY COPY COMMANDS
# ////////////////////////////////////////////////////////////////////////////////

# Copy libaries imported by matrices to executable output dir
add_custom_command(TARGET main POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
		${PROJECT_SOURCE_DIR}/dep/lib/matrices
		${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE}
)

# Copy libaries imported by matrices to executable output dir
add_custom_command(TARGET matrix-main POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
		${PROJECT_SOURCE_DIR}/dep/lib/matrices
		${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE}
)