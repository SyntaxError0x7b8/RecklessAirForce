# based on a template by tupini07
# https://github.com/tupini07/raylib-cpp-cmake-template/blob/main/CMakeLists.txt
# 2025-08-10

cmake_minimum_required(VERSION 3.31)

project(RAF)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#enable_testing()

include(FetchContent)

##########################################################################################
# Add dependencies with FetchContent
##########################################################################################

function(add_git_dependency libName gitURL gitTag)
    FetchContent_Declare(${libName}
            GIT_REPOSITORY ${gitURL}
            GIT_TAG        ${gitTag}
            GIT_SHALLOW    TRUE
            GIT_PROGRESS   TRUE
    )
    FetchContent_MakeAvailable(${libName})
    target_compile_options(${libName} PRIVATE "-w")
endfunction()

# Dependencies

#Add Raylib
#[[set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # don't build the supplied example games
add_git_dependency(
        raylib
        https://github.com/raysan5/raylib.git
        5.5
)]]

# Add LDtkLoader
#[[add_git_dependency(
        LDtkLoader
        https://github.com/Madour/LDtkLoader.git
        1.5.3.1
)]]

# Add Box2d
#[[set(BOX2D_BUILD_UNIT_TESTS OFF CACHE BOOL "" FORCE)
set(BOX2D_BUILD_TESTBED OFF CACHE BOOL "" FORCE)
add_git_dependency(
        box2d
        https://github.com/erincatto/box2d.git
        v2.4.1
)]]

# Add {fmt} library
#[[add_git_dependency(
        fmt
        https://github.com/fmtlib/fmt.git
        11.1.2
)]]

##########################################################################################
# Project executable setup
##########################################################################################

# Adding our source files
# Define PROJECT_SOURCES as a list of all source files
file(GLOB_RECURSE RAF_PROJECT_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/*.cc"
        "${CMAKE_CURRENT_LIST_DIR}/gameObject/*.cc"
        "${CMAKE_CURRENT_LIST_DIR}/graphics/*.cc"
        "${CMAKE_CURRENT_LIST_DIR}/map/*.cc"
        #"../../catch2_test/*.cc"
)
message("RAF PROJECT SOURCES: ${RAF_PROJECT_SOURCES}")

# Define PROJECT_INCLUDE to be the path to the include directory of the project
set(RAF_PROJECT_INCLUDE "."
        "gameObject"
        "map"
        "graphics"
        "graphics"
        #"../catch2_test"
)


# add library (trying to make catch2 test work)
add_library(raf-lib STATIC ${RAF_PROJECT_SOURCES})
target_include_directories(raf-lib PUBLIC .)

# Declaring our executable
add_executable(${PROJECT_NAME} ${RAF_PROJECT_SOURCES})
target_sources(${PROJECT_NAME} PRIVATE ${RAF_PROJECT_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${RAF_PROJECT_INCLUDE})


target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
#target_link_libraries(${PROJECT_NAME} PRIVATE raygui)
#target_link_libraries(${PROJECT_NAME} PRIVATE LDtkLoader::LDtkLoader)
#target_link_libraries(${PROJECT_NAME} PRIVATE box2d)
#target_link_libraries(${PROJECT_NAME} PRIVATE fmt)



##########################################################################################
# Project build settings
##########################################################################################

add_definitions(-DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE})

# Setting ASSETS_PATH
if (CMAKE_BUILD_TYPE MATCHES "Debug")
    SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -O0 -DDEBUG")

    # Set the asset path macro to the absolute path on the dev machine
    target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="../assets")
else()
    # Set the asset path macro in release mode to a relative path that assumes the assets folder is in the same directory as the game executable
    target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="../assets")
endif()
