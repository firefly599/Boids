#pragma once
#include <array>
class Bird
{
public:
	Bird() : id(0) {};
	Bird(int bird_id) : id(bird_id) {};
	~Bird() = default;

	int id;

	std::array<double, 3> position = {};
	std::array<double, 3> velocity = {};
	std::array<double, 3> acceleration = {};

	std::array<double, 3> separation = {};
	std::array<double, 3> alignment = {};
	std::array<double, 3> cohesion = {};

	int alignmentCounter = 0;
	int cohesionCounter = 0;

	inline void ResetForces() {
		separation = { 0.0, 0.0, 0.0 };
		alignment = { 0.0, 0.0, 0.0 };
		cohesion = { 0.0, 0.0, 0.0 };
	}
};

