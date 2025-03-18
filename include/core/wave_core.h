#ifndef WAVE_CORE_H
#define WAVE_CORE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <complex.h>

// Wave simulation parameters
typedef struct {
    double frequency;    // Frequency in Hz
    double amplitude;    // Normalized amplitude
    double phase;       // Initial phase
    double wavelength;  // Wavelength in meters
    double k;          // Wave number
} WaveParams;

// Initialize wave simulation parameters
void wave_init_params(WaveParams* params);

// Calculate pressure field at given point
_Complex double wave_calculate_pressure(const WaveParams* params, double x, double y, double z);

// Calculate pressure field over a grid (parallelized with OpenMP)
void wave_calculate_field(const WaveParams* params, 
                         double* x_grid, double* y_grid, double* z_grid,
                         _Complex double* field,
                         int nx, int ny, int nz);

// Calculate acoustic potential (parallelized with OpenMP)
void wave_calculate_potential(const WaveParams* params,
                            double* x_grid, double* y_grid, double* z_grid,
                            double* potential,
                            int nx, int ny, int nz);

#ifdef __cplusplus
}
#endif

#endif // WAVE_CORE_H 