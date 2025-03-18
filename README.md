# WAVE - Workbench for Acoustic Visualization and Experimentation

WAVE is a modern C/C++/C# simulation platform for acoustic levitation devices, inspired by the TinyLev project. It provides a comprehensive environment for simulating, visualizing, and optimizing acoustic levitation setups.

## Features

- Acoustic field simulation
- Particle levitation simulation
- Real-time visualization
- Support for different transducer configurations
- Modern C++20 implementation
- Cross-platform GUI using Avalonia UI

## Building from Source

### Prerequisites

- CMake 3.20 or higher
- C++20 compatible compiler
- .NET 7.0 SDK
- BLAS and LAPACK libraries
- OpenMP

### Ubuntu/Debian Dependencies

```bash
sudo apt install build-essential cmake ninja-build gcc g++ libomp-dev libblas-dev liblapack-dev dotnet-sdk-7.0
```

### Building

```bash
mkdir build && cd build
cmake -G Ninja ..
ninja
```

## Project Structure

```
wave/
├── include/           # C/C++ headers
│   ├── core/         # Core C implementation
│   ├── cpp/          # C++ wrapper
│   └── gui/          # C# GUI application
└── tests/            # Test suite
```

## License

MIT License - See LICENSE file for details 