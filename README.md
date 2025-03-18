# WAVE - Acoustic Wave Simulation

[![CI](https://github.com/paulsso/wave/actions/workflows/ci.yml/badge.svg?branch=main)](https://github.com/paulsso/wave/actions/workflows/ci.yml)
[![codecov](https://codecov.io/gh/paulsso/wave/branch/main/graph/badge.svg)](https://codecov.io/gh/paulsso/wave)
[![Release](https://img.shields.io/github/v/release/paulsso/wave?include_prereleases&sort=semver)](https://github.com/paulsso/wave/releases)

WAVE is a modern C/C++/C# simulation platform for acoustic levitation devices, inspired by the TinyLev project. It provides a comprehensive environment for simulating, visualizing, and optimizing acoustic levitation setups.

## Features

- Acoustic field simulation
- Particle levitation simulation
- Real-time visualization
- Support for different transducer configurations
- Modern C++20 implementation
- Cross-platform GUI using Avalonia UI

## Prerequisites

### Build Tools and Libraries

```bash
# Install build tools and dependencies
sudo apt update
sudo apt install -y \
    build-essential \
    cmake \
    ninja-build \
    gcc \
    g++ \
    libomp-dev \
    libblas-dev \
    liblapack-dev \
    clang \
    clang-tools
```

### .NET 9.0 SDK

1. Add Microsoft package repository:
```bash
wget https://packages.microsoft.com/config/ubuntu/$(lsb_release -rs)/packages-microsoft-prod.deb -O packages-microsoft-prod.deb
sudo dpkg -i packages-microsoft-prod.deb
rm packages-microsoft-prod.deb
```

2. Install .NET 9.0 SDK:
```bash
sudo apt update
sudo apt install -y dotnet-sdk-9.0
```

## Building from Source

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