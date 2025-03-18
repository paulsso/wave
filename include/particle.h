#ifndef SALT_PARTICLE_H
#define SALT_PARTICLE_H

#include "salt_types.h"

typedef struct {
    double x;
    double y;
    double z;
    double radius;        // Particle radius in meters
    double density;       // Particle density in kg/m³
    double mass;         // Particle mass in kg
    double volume;       // Particle volume in m³
} Particle;

typedef struct {
    double x;
    double y;
    double z;
    double fx;          // Force in x direction
    double fy;          // Force in y direction
    double fz;          // Force in z direction
} ParticleForce;

/**
 * Validates if a particle can be levitated
 * @param particle Particle properties
 * @param medium Medium properties
 * @return true if particle can be levitated
 */
bool validate_particle(const Particle* particle, const MediumProperties* medium);

/**
 * Computes forces on a particle in the acoustic field
 * @param particle Particle properties
 * @param medium Medium properties
 * @param pressure_field Acoustic pressure field
 * @param potential_field Acoustic potential field
 * @return Forces acting on the particle
 */
ParticleForce compute_particle_forces(
    const Particle* particle,
    const MediumProperties* medium,
    const double* pressure_field,
    const double* potential_field
);

/**
 * Simulates particle motion in the acoustic field
 * @param particle Particle properties
 * @param medium Medium properties
 * @param pressure_field Acoustic pressure field
 * @param potential_field Acoustic potential field
 * @param dt Time step
 * @return New particle position
 */
Particle simulate_particle_motion(
    const Particle* particle,
    const MediumProperties* medium,
    const double* pressure_field,
    const double* potential_field,
    double dt
);

#endif // SALT_PARTICLE_H 