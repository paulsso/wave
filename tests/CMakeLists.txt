enable_testing()

# Add test executable
add_executable(wave_tests
    wave_tests.cpp
)

target_link_libraries(wave_tests
    PRIVATE
        wave_core
        wave_cpp
)

# Register tests
add_test(NAME wave_tests COMMAND wave_tests) 