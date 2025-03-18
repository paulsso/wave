#ifndef SALT_HPP
#define SALT_HPP

#include <vector>
#include <complex>
#include <memory>
#include <string>
#include "particle.h"

namespace salt {

struct MediumProperties {
    double density;
    double speed_of_sound;
    double voltage;
};

struct ComponentProperties {
    bool concave;
    double orientation;
    double displacement;
    double radius_curvature;
    double radius;
    double phase;
    double trans_freq;
    int layers;
    std::vector<int> depth;
    double transducer_diameter;
};

struct Geometry {
    std::vector<double> x;
    std::vector<double> y;
    std::vector<double> z;
    std::vector<double> voltage;
};

struct Medium {
    std::vector<double> x_span;
    std::vector<double> z_span;
    std::vector<double> pressure_field;
    std::vector<double> potential_field;
};

struct Particle {
    double x;
    double y;
    double z;
    double radius;
    double density;
    double mass;
    double volume;
};

class Simulation {
public:
    Simulation(const MediumProperties& medium,
              const ComponentProperties& z_pos,
              const ComponentProperties& z_neg);

    void run();
    void simulate_particle(Particle& particle, double dt);
    
    const std::vector<std::complex<double>>& get_pressure() const;
    const std::vector<double>& get_potential() const;
    const Medium& get_medium() const;
    bool validate_particle(const Particle& particle) const;

private:
    MediumProperties medium_;
    ComponentProperties z_pos_;
    ComponentProperties z_neg_;
    std::vector<std::complex<double>> pressure_;
    std::vector<double> potential_;
    Medium medium_geometry_;
};

} // namespace salt

#endif // SALT_HPP 