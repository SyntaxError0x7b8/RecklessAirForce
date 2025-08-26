include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.17.0
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(unit_tests
        graphics_test.cc
)

include_directories(${googletest_SOURCE_DIR})


target_link_libraries(unit_tests PRIVATE raf_lib GTest::gtest_main GTest::gmock)
include(GoogleTest)
gtest_discover_tests(unit_tests)