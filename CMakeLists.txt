cmake_minimum_required(VERSION 3.8)

set(PROJECT_TARGET mystatics)

project(${PROJECT_TARGET})

if(NOT CMAKE_BUILD_TYPE MATCHES Release)
    if(NOT CMAKE_BUILD_TYPE MATCHES Debug)
        message(FATAL_ERROR "Failed to set CMAKE_BUILD_TYPE use: -DCMAKE_BUILD_TYPE={Debug|Release}")
    endif()
endif()

if(CMAKE_BUILD_TYPE MATCHES Release)
    message(STATUS "Doing a RELEASE build")
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build from: Debug Release RelWithDebInfo MinSizeRel Coverage." FORCE)
endif()

# DEBUG flags and definitions
if(CMAKE_BUILD_TYPE MATCHES Debug)
    message(STATUS "Doing a DEBUG build")
    set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Choose the type of build from: Debug Release RelWithDebInfo MinSizeRel Coverage." FORCE)
endif()

list(APPEND CMAKE_MODULE_PATH
        ${CMAKE_CURRENT_SOURCE_DIR}/cmake
        )

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp
        Manager.cpp
        Manager.h
        TaskA.cpp
        TaskA.h
        TaskB.cpp
        TaskB.h
        ConfigByFunction.h
        ConfigByModule.h
        ConfigByParam.h
        ConfigByAtomic.h ConfigByPointer.h)
add_executable(mystatics ${SOURCE_FILES})

set(SDK_ROOT $ENV{VS_PROJECT_PATH}/IntelligentCloudLibrary/sdks)

######
##  BOOST
######
find_package(Boost REQUIRED COMPONENTS thread system)
target_include_directories(${PROJECT_TARGET} PUBLIC ${Boost_INCLUDE_DIRS})
target_link_libraries(${PROJECT_TARGET} PUBLIC ${Boost_LIBRARIES})


