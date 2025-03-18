#ifndef WAVE_CPP_HPP
#define WAVE_CPP_HPP

#include "core/wave_core.h"
#include <vector>
#include <complex>

namespace wave {

class WaveSimulation {
public:
    // Default constructor with standard parameters
    WaveSimulation();
    
    // Constructor with custom frequency and amplitude
    WaveSimulation(double frequency, double amplitude);
    
    // Calculate pressure field over a grid
    std::vector<std::complex<double>> calculateField(
        const std::vector<double>& x_grid,
        const std::vector<double>& y_grid,
        const std::vector<double>& z_grid);
    
    // Calculate acoustic potential over a grid
    std::vector<double> calculatePotential(
        const std::vector<double>& x_grid,
        const std::vector<double>& y_grid,
        const std::vector<double>& z_grid);
    
private:
    WaveParams params_;
};

} // namespace wave

#endif // WAVE_CPP_HPP 