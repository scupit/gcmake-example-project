# json-to-cmake Example Project
This is the example project for my [json to CmakeLists.txt conversion tool](https://github.com/scupit/json-to-cmake-rewrite).

The project is meant to show the methods of creating executables and libraries, importing a library, and linking.

## Using this project
### Prerequisites
* [Python 3](https://www.python.org/downloads/)
* [CMake](https://cmake.org/download/)
* [My json-to-cmake tool](https://github.com/scupit/json-to-cmake-rewrite)
* C++ compiler
  - If you're on windows, [MinGW-w64 7.0.0](https://sourceforge.net/projects/mingw-w64/) is what I use

### Configuring and running
* Make sure all of the above tools are either in your system PATH or are readily available
* Run json-to-cmake on this cmake_data.json
  - Notice that the matrix library was cloned into *dep/external*

At this point you will also need to build the matrix library and ensure that the output library is copied to
*dep/lib/matrices* and that its header (Matrix.hpp) is copied to *dep/include/matrices*.

* Configure and generate CMake files into *build*
* Compile the programs as usual

# What is the resulting output from this cmake_data.json?
3 executables in **bin/*configuration***:
  * *matrix-main-2*
  * *main*
  * *matrix-main*

2 static libraries in **lib/*configuration***
  * *math_lib*
  * *printing*

1 shared library in **bin/*configuration*** (with link data in **lib/*configuration*** for applicable systems)
  * *quick-header*

The [matrices](https://github.com/scupit/basic-matrices) library was also imported.

## How the programs are linked together
cmake_data.json aims to simplify visualization and editing of program linking. You can see which libraries and/or
groups are linked to which executables and groups.

It's worth explaining that when linking to/from a group, linking is applied for each output in the group.
  * Every library in a group will be linked to an executable
  * Every library linked to a group will be linked to every executable in that group

However, libraries can also be picked individually from a group and linked to individual executables in a group.

## What is linked in the output?
If you want to see this yourself, compare line 54 "links" of cmake_data.json with the LINK LIBRARIES TO OUTPUTS section
of CMakeLists.txt starting on line 259.

* Linked to all executables in **exes** group (*main* and *matrix-main*):
  - All libraries from **group_libs** group (*math_lib* and *printing*) 
  - *quick-header* shared library

* Individually linked to **math_lib** inside *group_libs* group:
  - *matrices* imported library

* Linked to **matrix-main-2**
  - *math_lib* **only** from *group_libs*
  - *quick header* shared library

# Running the executables
Run the built executables in **bin/*configuration*** from the command line to see their output! 