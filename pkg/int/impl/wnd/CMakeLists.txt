project(wnd
        VERSION 1.0.0
        DESCRIPTION "Library for dealing with Windows.")

# Library files
set(SRC_LIST "process.cpp")
set(HDR_LIST "${killprocess_SOURCE_DIR}/pkg/int/inc/wnd/process.h")

# Make an automatic library - will be static or dynamic based on user setting
add_library(wnd ${SRC_LIST} ${HDR_LIST})

# Add precompiled headers
#target_precompile_headers(wnd PRIVATE pch.h)

# We need this directory, and users of our library will need it too
target_include_directories(wnd PUBLIC "${killprocess_SOURCE_DIR}/pkg/int/inc")

# All users of this library will need at least C++17
target_compile_features(wnd PUBLIC cxx_std_17)

add_library(wnd::wnd ALIAS wnd)


