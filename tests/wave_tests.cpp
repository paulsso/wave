#include <gtest/gtest.h>
#include "core/wave_core.h"
#include "cpp/wave_cpp.hpp"
#include <vector>
#include <cmath>
#include <complex>

TEST(WaveCoreTest, PressureCalculation) {
    WaveParams params;
    wave_init_params(&params);
    
    // Test pressure at a known distance
    double x = 0.1;  // 10 cm
    double y = 0.0;
    double z = 0.0;
    
    _Complex double p = wave_calculate_pressure(&params, x, y, z);
    double magnitude = std::abs(std::complex<double>(__real__ p, __imag__ p));
    double expected = params.amplitude / (params.k * x);
    
    // Pressure should match the expected value
    EXPECT_NEAR(magnitude, expected, 1e-10);
}

TEST(WaveCppTest, FieldCalculation) {
    wave::WaveSimulation sim(40.0e3, 1.0);  // 40 kHz, unit amplitude
    
    // Create a simple 2x2x2 grid
    std::vector<double> x_grid = {-0.1, 0.1};
    std::vector<double> y_grid = {-0.1, 0.1};
    std::vector<double> z_grid = {-0.1, 0.1};
    
    auto field = sim.calculateField(x_grid, y_grid, z_grid);
    
    // Check field size
    EXPECT_EQ(field.size(), 8);  // 2x2x2 = 8 points
    
    // Check that field values are non-zero
    for (const auto& p : field) {
        EXPECT_GT(std::abs(p), 0.0);
    }
}

TEST(WaveCppTest, PotentialCalculation) {
    wave::WaveSimulation sim(40.0e3, 1.0);
    
    // Create a simple 2x2x2 grid
    std::vector<double> x_grid = {-0.1, 0.1};
    std::vector<double> y_grid = {-0.1, 0.1};
    std::vector<double> z_grid = {-0.1, 0.1};
    
    auto potential = sim.calculatePotential(x_grid, y_grid, z_grid);
    
    // Check potential size
    EXPECT_EQ(potential.size(), 8);  // 2x2x2 = 8 points
    
    // Check that potential values are non-negative
    for (const auto& p : potential) {
        EXPECT_GE(p, 0.0);
    }
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} 