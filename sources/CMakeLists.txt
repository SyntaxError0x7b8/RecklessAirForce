# Define PROJECT_SOURCES as a list of all source files
file(GLOB_RECURSE LIBRARY_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/*.cc"
        "${CMAKE_CURRENT_LIST_DIR}/gameObject/*.cc"
        "${CMAKE_CURRENT_LIST_DIR}/graphics/*.cc"
        "${CMAKE_CURRENT_LIST_DIR}/map/*.cc")

add_library(raf_lib STATIC .)
target_include_directories(raf_lib PUBLIC .)

include_directories("../cmake-build-debug/_deps/raylib-src/src/")

add_executable(raf LIBRARY_SOURCES)
target_link_libraries(raf PRIVATE raf_lib)