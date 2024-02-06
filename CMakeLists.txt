cmake_minimum_required(VERSION 3.21)

# Generate universal executable for Apple hardware for Release builds.
# Should be included before calling `project`.
if (APPLE AND "${CMAKE_GENERATOR}" STREQUAL "Xcode")
  set(CMAKE_OSX_ARCHITECTURES "$(ARCHS_STANDARD)")
endif ()

# Change the first parameter (name of your .exe) and last parameter (in DESCRIPTION "" quotes) to whatever.
project(SpaceShooter
        VERSION 0.0.1
        LANGUAGES CXX
        DESCRIPTION "A Space Shooter Demo made in SFML")

# Set Output Directories.
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

include(GNUInstallDirs)

# Set up compiler settings
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/setup_compilers.cmake)

# Setup CCache if available
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/setup_ccache.cmake)

# Enable project folders.
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "CMakeTargets")

### Add SFML dependencies

# Set sfml's linking
set(BUILD_SHARED_LIBS OFF) 

# Fetch sfml as a dependency
include(FetchContent)
set(FETCHCONTENT_QUIET OFF)

FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.0
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE
    FIND_PACKAGE_ARGS
)
FetchContent_MakeAvailable(SFML)

# Add the source files
set(proj_entry "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")
set(proj_source_files "${CMAKE_CURRENT_SOURCE_DIR}/src/private/core/app.cpp")
set(proj_header_files "${CMAKE_CURRENT_SOURCE_DIR}/src/public/core/app.hpp")
set(proj_win32_files "${CMAKE_CURRENT_SOURCE_DIR}/src/public/platforms/win_reset.hpp")

## Executable

if(WIN32)
add_executable(SpaceShooter
    ${proj_entry}
    ${proj_source_files}
    ${proj_header_files}
    ${proj_win32_files})
endif()

if(APPLE)
add_executable(SpaceShooter MACOSX_BUNDLE
    ${proj_entry}
    ${proj_source_files}
    ${proj_header_files})
endif()

# Compile options
target_compile_options(SpaceShooter PRIVATE ${compiler_settings})

# Include directories and libraries
target_include_directories(SpaceShooter PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/public")

# Set C++ standard for the Game
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/setup_cpp_standard.cmake)
set_cpp_standard(SpaceShooter)

target_link_libraries(SpaceShooter PRIVATE sfml-graphics sfml-audio sfml-system sfml-window)

if(MSVC)
    # Set App as the Startup project on Visual Studio
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT SpaceShooter)
    # Tells Visual Studio to set the working directory to the directory where the target's executable will be outputted.
    # That should be the same location where the assets will be copied (see custom commands at the end).
    set_target_properties(SpaceShooter PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "$<TARGET_FILE_DIR:SpaceShooter>")
endif()

# Setup IDE-specific configuration
if(NOT CMAKE_GENERATOR MATCHES "Visual Studio")
  message(STATUS "Configuring for a non-Visual Studio generator")
  # Set default build type to Dedug if no configuration was specified
  if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    message(STATUS "Setting build type to 'Debug' as none was specified.")
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build." FORCE)
  endif()

  # Set the possible values of build type for cmake-gui, ccmake
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release")
endif()

# Setting IDE tree structure
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/src" PREFIX "src" FILES ${proj_entry})
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/src/private" PREFIX "src/private" FILES ${proj_source_files})
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/src/public" PREFIX "src/public" FILES ${proj_header_files})

if(MSVC)
    source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/src/public" PREFIX "src/public" FILES ${proj_win32_files})
endif()

# Copy assets/ with its contents, to CMAKE_RUNTIME_OUTPUT_DIRECTORY
# Using PRE_BUILD to catch up with the creation of CMAKE_RUNTIME_OUTPUT_DIRECTORY on build.
add_custom_command(
    TARGET SpaceShooter PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_CURRENT_SOURCE_DIR}/assets $<TARGET_FILE_DIR:SpaceShooter>/assets
)

# Copy openal32.dll from fetch_content directory to output runtime directory
# (if on Windows and if SFML_AUDIO is included)
if (WIN32 AND SFML_BUILD_AUDIO)
    add_custom_command(
        TARGET SpaceShooter PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${FETCHCONTENT_BASE_DIR}/sfml-src/extlibs/bin/x64/openal32.dll $<TARGET_FILE_DIR:SpaceShooter>
    )
endif()