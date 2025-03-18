add_library(wave_cpp
    wave_cpp.cpp
)

target_include_directories(wave_cpp
    PUBLIC
        ${CMAKE_SOURCE_DIR}/include/cpp
)

target_link_libraries(wave_cpp
    PUBLIC
        wave_core
        OpenMP::OpenMP_CXX
)

# Installation
install(TARGETS wave_cpp
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
) 