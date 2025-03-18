# Find .NET SDK
find_package(Dotnet REQUIRED)

# Add C# project
add_custom_target(WaveGui ALL
    COMMAND dotnet build ${CMAKE_CURRENT_SOURCE_DIR}/WaveGui.csproj -c Release
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

# Copy native libraries to output directory
add_custom_command(TARGET WaveGui POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:wave_core>
        $<TARGET_FILE:wave_cpp>
        $<TARGET_FILE_DIR:WaveGui>
) 