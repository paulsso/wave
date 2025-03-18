#include "cpp/wave_cpp.hpp"
#include <vector>
#include <memory>
#include <complex>

namespace wave {

WaveSimulation::WaveSimulation() {
    wave_init_params(&params_);
}

WaveSimulation::WaveSimulation(double frequency, double amplitude) {
    params_.frequency = frequency;
    params_.amplitude = amplitude;
    params_.phase = 0.0;
    params_.wavelength = 343.0 / frequency;  // Speed of sound / frequency
    params_.k = 2.0 * M_PI / params_.wavelength;
}

std::vector<std::complex<double>> WaveSimulation::calculateField(
    const std::vector<double>& x_grid,
    const std::vector<double>& y_grid,
    const std::vector<double>& z_grid) {
    
    int nx = x_grid.size();
    int ny = y_grid.size();
    int nz = z_grid.size();
    
    // Create a temporary buffer for C complex numbers
    std::vector<_Complex double> temp_field(nx * ny * nz);
    
    wave_calculate_field(&params_,
                        const_cast<double*>(x_grid.data()),
                        const_cast<double*>(y_grid.data()),
                        const_cast<double*>(z_grid.data()),
                        temp_field.data(),
                        nx, ny, nz);
    
    // Convert C complex numbers to C++ complex numbers
    std::vector<std::complex<double>> field(nx * ny * nz);
    for (size_t i = 0; i < field.size(); ++i) {
        field[i] = std::complex<double>(__real__ temp_field[i], __imag__ temp_field[i]);
    }
    
    return field;
}

std::vector<double> WaveSimulation::calculatePotential(
    const std::vector<double>& x_grid,
    const std::vector<double>& y_grid,
    const std::vector<double>& z_grid) {
    
    int nx = x_grid.size();
    int ny = y_grid.size();
    int nz = z_grid.size();
    
    std::vector<double> potential(nx * ny * nz);
    
    wave_calculate_potential(&params_,
                           const_cast<double*>(x_grid.data()),
                           const_cast<double*>(y_grid.data()),
                           const_cast<double*>(z_grid.data()),
                           potential.data(),
                           nx, ny, nz);
    
    return potential;
}

} // namespace wave 