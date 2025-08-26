# Define PROJECT_SOURCES as a list of all source files
file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/*.cc"
        "${CMAKE_CURRENT_LIST_DIR}/*/*.cc")

add_library(raf_lib STATIC ${PROJECT_SOURCES})
target_include_directories(raf_lib PUBLIC .)

add_executable(raf raf_lib)
target_link_libraries(raf PRIVATE raf_lib)