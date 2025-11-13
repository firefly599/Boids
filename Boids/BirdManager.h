#include "Bird.h"
#include "Constants.h"
#pragma once
class BirdManager
{
public:
	BirdManager();
	~BirdManager();

	Bird birds[NUMBER_OF_BOIDS];

	void InitializeBirds(int NUMBER_OF_BOIDS);
	void UpdateCycle();
	const void print_data();
	const void print_data_single();

private:
	void CalculateForces();
	std::array<double, 3> CalculateSeparation(Bird this_bird, Bird other_bird);
	std::array<double, 3> CalculateAlignment(Bird this_bird, Bird other_bird);
	std::array<double, 3> CalculateCohesion(Bird this_bird, Bird other_bird);

	void UpdateBirds();
};

