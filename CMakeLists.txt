cmake_minimum_required(VERSION 3.24)
project(HelloLib LANGUAGES CXX)

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

    # Force library output to lib/ folder
    set_target_properties(HelloLib PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/lib"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/lib"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/lib"
    )
endif()

add_library(HelloLib::HelloLib ALIAS HelloLib)
