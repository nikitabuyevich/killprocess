cmake_minimum_required(VERSION 3.16)

project(killclass
        VERSION 1.0
        DESCRIPTION "Kill all processes that match a specified class name."
        LANGUAGES CXX)

# Only do these if this is the main project, and not if it is included through add_subdirectory
if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

    # Optionally set things like CMAKE_CXX_STANDARD, CMAKE_POSITION_INDEPENDENT_CODE here
    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    # Ensure -std=c++xx instead of -std=g++xx
    set(CMAKE_CXX_EXTENSIONS OFF)
    # Enable exceptions for clang-cl
    set(CMAKE_CXX_FLAGS /EHa)

    # Docs only available if this is the main app
    find_package(Doxygen)
    if (Doxygen_FOUND)
        add_subdirectory(docs)
    else ()
        message(STATUS "Doxygen not found, not building docs")
    endif ()
endif ()

# Make external libraries and libraries globally available.
add_subdirectory(pkg)

# Create the targets for the entire example-app.
add_subdirectory(app)
