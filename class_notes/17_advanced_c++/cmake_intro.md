# What is CMake?
CMake stands for Cross-Platform Make. It is:

* **Build-System Generator:** Instead of building software directly, CMake generates native build system files (e.g., Makefiles for Unix-like systems, project files for Visual Studio, Ninja build files, etc.).
* **Configuration Tool:** It allows developers to configure their projects in a way that's portable across different environments.

## How Does CMake Work?
CMake operates in two main stages:

* **Configuration Stage:**
You create a file called ```CMakeLists.txt``` that describes your project, its source files, dependencies, and desired output.
CMake reads this file and generates the necessary build system files.
* **Build Stage:**
Using the generated build files, the actual build process is carried out with the system's native build tool (e.g., ```make```, ```ninja```, ```msbuild```).

## Key Concepts
1. **CMakeLists.txt:**
   * The configuration file used to define your project.
   * Contains instructions like:
```cmake
cmake_minimum_required(VERSION 3.20)
project(MyProject)
add_executable(MyExecutable main.cpp)
```
   * Each line uses CMake commands to set up targets, link libraries, specify compiler options, etc.

2. **Targets:**
   * CMake organizes your outputs (executables, libraries) into "targets."
   * Example targets: ```add_executable```, ```add_library```.

3. **Out-of-Source Builds:**
   * CMake encourages building in a separate directory from the source code.
   * This keeps your source directory clean and makes it easy to have multiple build configurations (e.g., Debug, Release).

4. **Toolchain Files:**
   * CMake supports cross-compiling by allowing you to specify a toolchain file that defines the compiler and linker for the target platform.

5. Modules and Find Scripts:
   * CMake includes many built-in modules for common tasks, such as finding external libraries like FindBoost or FindOpenGL.

## Basic Workflow
Write a CMakeLists.txt file.
Configure the project:
```bash
mkdir build
cd build
cmake ..
```
Build the project:
```bash
cmake --build .
```

## Why Use CMake?
* Cross-Platform: Write once, build anywhere (Windows, macOS, Linux, etc.).
* Flexibility: Integrates with various compilers, IDEs, and build tools.
* Scalability: Handles small and large projects with ease.
* Dependency Management: Automatically finds and configures third-party libraries.
* Example CMakeLists.txt
* Here's an example of a basic configuration:

```cmake
cmake_minimum_required(VERSION 3.16)
project(ExampleProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Add an executable
add_executable(Example main.cpp)

# Link libraries
find_package(OpenGL REQUIRED)
target_link_libraries(Example OpenGL::GL)
```