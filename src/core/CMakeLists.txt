add_library(wave_core
    wave_core.c
)

target_include_directories(wave_core
    PUBLIC
        ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(wave_core
    PUBLIC
        OpenMP::OpenMP_C
        BLAS::BLAS
        LAPACK::LAPACK
)

# Installation
install(TARGETS wave_core
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
) 