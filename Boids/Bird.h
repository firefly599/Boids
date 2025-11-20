#pragma once
#include <array>
#include "Constants.h"
#include "Utils.h"
class Bird
{
public:
	Bird() : id(0) {};
	Bird(int bird_id) : id(bird_id) {};
	~Bird() = default;

	int id;
	double mass = 100.0;

	std::array<double, 3> position = {};
	std::array<double, 3> velocity = {};
	std::array<double, 3> acceleration = {};

	std::array<double, 3> separation = {};
	std::array<double, 3> alignment = {};
	std::array<double, 3> cohesion = {};

	std::array<double, 3> totalForce = {}; 

	int alignmentCounter = 0;
	int cohesionCounter = 0;

	inline void ResetForces() {
		separation = { 0.0, 0.0, 0.0 };
		alignment = { 0.0, 0.0, 0.0 };
		cohesion = { 0.0, 0.0, 0.0 };
	}

	void UpdateTotalForces();
	void UpdateAcceleration();
	void UpdateVelocity();
	void UpdatePosition();

	void wrapPosition();
};

