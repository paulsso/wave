enable_testing()

# Add test executable
add_executable(wave_tests
    wave_tests.cpp
)

target_include_directories(wave_tests
    PRIVATE
        ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(wave_tests
    PRIVATE
        wave_core
        wave_cpp
        GTest::gtest_main
        GTest::gtest
)

# Register tests
add_test(NAME wave_tests COMMAND wave_tests) 