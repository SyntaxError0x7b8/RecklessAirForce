# initially started from a template by tupini07
# https://github.com/tupini07/raylib-cpp-cmake-template/blob/main/CMakeLists.txt
# I have only reused the function, but I have left the link for future rereference.
# 2025-08-10

cmake_minimum_required(VERSION 4.0)

project(RecklessAirForce)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

enable_testing()

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
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # don't build the supplied example games
add_git_dependency(
        raylib
        https://github.com/raysan5/raylib.git
        5.5
)

# once/if test implemented successfully, change into
# file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/src/*.cc")

set(HEADER_FILES
        ${CMAKE_CURRENT_LIST_DIR}/src/raflib.h
        ${CMAKE_CURRENT_LIST_DIR}/src/map/map.h
        ${CMAKE_CURRENT_LIST_DIR}/src/gameObject/game_object.h
        ${CMAKE_CURRENT_LIST_DIR}/src/graphics/graphics_component.h
        ${CMAKE_CURRENT_LIST_DIR}/src/graphics/proton_graphics.h
        ${CMAKE_CURRENT_LIST_DIR}/src/graphics/hero_graphics_component.h
        ${CMAKE_CURRENT_LIST_DIR}/src/input/movement_handler.h
        ${CMAKE_CURRENT_LIST_DIR}/src/input/hero_shoot.h
        ${CMAKE_CURRENT_LIST_DIR}/src/target/target.h
        ${CMAKE_CURRENT_LIST_DIR}/src/collision/collisions.h
        ################################################################
)

set(SOURCE_FILES
        ${CMAKE_CURRENT_LIST_DIR}/main.cc
        #####################################################################
        ${CMAKE_CURRENT_LIST_DIR}/src/raflib.cc
        ${CMAKE_CURRENT_LIST_DIR}/src/map/map.cc
        ${CMAKE_CURRENT_LIST_DIR}/src/gameObject/game_object.cc
        ${CMAKE_CURRENT_LIST_DIR}/src/graphics/graphics_component.cc
        ${CMAKE_CURRENT_LIST_DIR}/src/graphics/proton_graphics.cc
        ${CMAKE_CURRENT_LIST_DIR}/src/graphics/hero_graphics_component.cc
        ${CMAKE_CURRENT_LIST_DIR}/src/input/movement_handler.cc
        ${CMAKE_CURRENT_LIST_DIR}/src/input/hero_shoot.cc
        ${CMAKE_CURRENT_LIST_DIR}/src/target/target.cc
        ${CMAKE_CURRENT_LIST_DIR}/src/collision/collisions.cc
        #####################################################################
        ${CMAKE_CURRENT_LIST_DIR}/tests/all_tests.cc
)

add_library(raflib STATIC ${HEADER_FILES} ${SOURCE_FILES})

target_include_directories(raflib PUBLIC .)

add_executable(RecklessAirForce ${SOURCE_FILES})


target_link_libraries(RecklessAirForce PRIVATE raylib)
#target_link_libraries(RecklessAirForce PRIVATE raflib)
