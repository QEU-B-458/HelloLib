cmake_minimum_required(VERSION 3.24)
project(HelloLib LANGUAGES CXX)

# Optionally allow source rebuilds for debugging or future expansion
option(HELLOLIB_PRECOMPILED "Use precompiled binary" ON)

if(HELLOLIB_PRECOMPILED)
    add_library(HelloLib STATIC IMPORTED GLOBAL)
    set_target_properties(HelloLib PROPERTIES
        IMPORTED_LOCATION "${CMAKE_CURRENT_LIST_DIR}/lib/libHelloLib.a"
        INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_LIST_DIR}/include"
    )
else()
    add_library(HelloLib STATIC src/HelloLib.cpp)
    target_include_directories(HelloLib PUBLIC include)
endif()

add_library(HelloLib::HelloLib ALIAS HelloLib)
