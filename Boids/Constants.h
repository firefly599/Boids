#pragma once

constexpr int NUMBER_OF_BOIDS = 100;


constexpr double SEPARATION_WEIGHT = 0.13;
constexpr double ALIGNMENT_WEIGHT = 3.0;
constexpr double COHESION_WEIGHT = 2.0;

constexpr double SEPARATION_DISTANCE = 0.05;
constexpr double ALIGNMENT_DISTANCE = 0.5;
constexpr double COHESION_DISTANCE = 0.3;

constexpr double NEIGHBOR_DISTANCE = 0.3;
constexpr double MAX_SPEED = 0.1;

constexpr double DELTA_T = 0.2;

constexpr double WORLD_SIZE = 1.0;