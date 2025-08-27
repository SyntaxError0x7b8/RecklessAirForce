find_package(Catch2 3 REQUIRED)
add_executable(Catch_tests_run graphics_test.cc)

target_link_libraries(Catch_tests_run PRIVATE raf-lib)
target_link_libraries(Catch_tests_run PRIVATE Catch2::Catch2WithMain)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(Catch)
catch_discover_tests(Catch_tests_run)