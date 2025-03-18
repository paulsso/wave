#include <omp.h>
#include <math.h>
#include <complex.h>
#include "core/wave_core.h"

// Initialize wave simulation parameters
void wave_init_params(WaveParams* params) {
    params->frequency = 40.0e3;  // 40 kHz
    params->amplitude = 1.0;     // Normalized amplitude
    params->phase = 0.0;         // Initial phase
    params->wavelength = 343.0 / params->frequency;  // Speed of sound / frequency
    params->k = 2.0 * M_PI / params->wavelength;     // Wave number
}

// Calculate pressure field at given point
_Complex double wave_calculate_pressure(const WaveParams* params, double x, double y, double z) {
    double r = sqrt(x*x + y*y + z*z);
    if (r < 1e-6) {
        return params->amplitude;  // Avoid division by zero
    }
    return params->amplitude * cexp(-I * params->k * r) / (params->k * r);
}

// Calculate pressure field over a grid (parallelized with OpenMP)
void wave_calculate_field(const WaveParams* params, 
                         double* x_grid, double* y_grid, double* z_grid,
                         _Complex double* field,
                         int nx, int ny, int nz) {
    #pragma omp parallel for collapse(3)
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            for (int k = 0; k < nz; k++) {
                int idx = i * ny * nz + j * nz + k;
                field[idx] = wave_calculate_pressure(params, 
                                                   x_grid[i], y_grid[j], z_grid[k]);
            }
        }
    }
}

// Calculate acoustic potential (parallelized with OpenMP)
void wave_calculate_potential(const WaveParams* params,
                            double* x_grid, double* y_grid, double* z_grid,
                            double* potential,
                            int nx, int ny, int nz) {
    #pragma omp parallel for collapse(3)
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            for (int k = 0; k < nz; k++) {
                int idx = i * ny * nz + j * nz + k;
                _Complex double p = wave_calculate_pressure(params, 
                                                         x_grid[i], y_grid[j], z_grid[k]);
                potential[idx] = cabs(p) * cabs(p);  // Square of pressure magnitude
            }
        }
    }
} 