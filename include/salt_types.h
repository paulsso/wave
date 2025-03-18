#ifndef SALT_TYPES_H
#define SALT_TYPES_H

#include <complex.h>
#include <stdbool.h>

// Physical constants for acoustic levitation
#define SALT_PI 3.14159265358979323846
#define SALT_TRANSDUCER_DIAMETER_10MM 10e-3
#define SALT_TRANSDUCER_DIAMETER_16MM 16e-3
#define SALT_TRANSDUCER_FREQUENCY 40e3
#define SALT_MAX_VOLTAGE 12.0
#define SALT_MIN_VOLTAGE 6.0
#define SALT_MAX_PARTICLE_DENSITY 6.0  // g/cm³ for 16mm transducers
#define SALT_MAX_PARTICLE_SIZE 3.0e-3  // 3mm for 10mm transducers

typedef struct {
    double density;        // kg/m³
    double speed_of_sound; // m/s
    double voltage;        // V (6-12V for 10mm, up to 20V for 16mm)
} MediumProperties;

typedef struct {
    bool concave;
    double orientation;    // 1.0 for top, -1.0 for bottom
    double displacement;   // mm
    double radius_curvature; // mm
    double radius;        // mm
    double phase;         // degrees (0-180)
    double trans_freq;    // kHz (typically 40kHz)
    int layers;           // 1-8
    int* depth;          // Number of transducers per layer
    double transducer_diameter; // mm (10mm or 16mm)
} ComponentProperties;

typedef struct {
    double* x;
    double* y;
    double* z;
    size_t size;
    double* voltage;      // Individual transducer voltages
} Geometry;

typedef struct {
    double* x_span;
    double* z_span;
    size_t x_size;
    size_t z_size;
    double* pressure_field;  // Acoustic pressure field
    double* potential_field; // Acoustic potential field
} Medium;

// Validation functions
bool validate_medium_properties(const MediumProperties* props);
bool validate_component_properties(const ComponentProperties* props);
bool validate_geometry(const Geometry* geom);

#endif // SALT_TYPES_H 