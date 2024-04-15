cmake_minimum_required(VERSION 3.20)
project(BoxInput LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_library(loglib NAMES log)
find_library(androidlib NAMES android)

set(SOURCES
        src/jni/javaConnector.cpp
        src/lib.cpp
)

add_library(BoxInput SHARED ${SOURCES})
target_link_libraries(BoxInput ${loglib} ${androidlib})
target_include_directories(BoxInput PRIVATE src)