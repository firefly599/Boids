#include "BirdManager.h"
#include <stdio.h>
#include "Utils.h"
#include <iostream>
#include <string>

using namespace std;


BirdManager::BirdManager() {
	InitializeBirds(NUMBER_OF_BOIDS);
	return;
}
BirdManager::~BirdManager() {
}
void BirdManager::InitializeBirds(int numberOfBirds) {
	for (int i = 0; i < numberOfBirds; i++) {
		Bird new_bird = Bird(i);
		new_bird.position = GetRandomFloat3();
		new_bird.acceleration = Array3Divide(GetRandomFloat3(), 10);
		birds[i] = new_bird;

		if (i == 0) {
			cout << new_bird.position[0] << ", " << new_bird.position[1] << ", " << new_bird.position[2] << endl;
		}
	}
}
void BirdManager::UpdateCycle() {
	CalculateForces();
	UpdateBirds();

	check_out_of_bounds();
	return;
}


#pragma region ForceCalculations
void BirdManager::CalculateForces() {
	for (Bird& this_bird : birds) {
		this_bird.ResetForces();

		std::array<double, 3> tmp_separation = { 0.0, 0.0, 0.0 };
		std::array<double, 3> tmp_alignment = { 0.0, 0.0, 0.0 };
		std::array<double, 3> tmp_cohesion = { 0.0, 0.0, 0.0 };

		for (const auto& other_bird : birds) {
			if (this_bird.id != other_bird.id) {
				tmp_separation = Array3Addition(CalculateSeparation(this_bird, other_bird), tmp_separation);
				tmp_alignment = Array3Addition(CalculateAlignment(this_bird, other_bird), tmp_alignment);
				tmp_cohesion = Array3Addition(CalculateCohesion(this_bird, other_bird), tmp_cohesion);
			}
		}
		this_bird.separation = tmp_separation;

		if (this_bird.alignmentCounter > 0) {
			this_bird.alignment = Array3Divide(tmp_alignment, static_cast<double>(this_bird.alignmentCounter));
		}

		if (this_bird.cohesionCounter > 0) {
			std::array<double, 3> average_position = Array3Divide(tmp_cohesion, static_cast<double>(this_bird.cohesionCounter));
			this_bird.cohesion = Array3Subtract(average_position, this_bird.position);
		}
	}
}

std::array<double, 3> BirdManager::CalculateSeparation(Bird this_bird, Bird other_bird) {
	std::array<double, 3> diff = Array3Subtract(this_bird.position, other_bird.position);
	double distanceSquared = diff[0] * diff[0] + diff[1] * diff[1] + diff[2] * diff[2];

	if (distanceSquared < SEPARATION_DISTANCE && distanceSquared > 0.0) {
		return diff;
	}

	return std::array<double, 3>{ 0.0, 0.0, 0.0 };
}

std::array<double, 3> BirdManager::CalculateAlignment(Bird this_bird, Bird other_bird) {
	double distanceSquared = GetDistance(this_bird.position, other_bird.position);

	if (distanceSquared < ALIGNMENT_DISTANCE) {
		this_bird.alignmentCounter++;
		return other_bird.velocity;
	}
	return std::array<double, 3> { 0.0, 0.0, 0.0 };
}

std::array<double, 3> BirdManager::CalculateCohesion(Bird this_bird, Bird other_bird) {
	double distanceSquared = GetDistance(this_bird.position, other_bird.position);
	if (distanceSquared < COHESION_DISTANCE) {
		this_bird.cohesionCounter++;
		return (other_bird.position);

	}
	return std::array<double, 3> {0.0, 0.0, 0.0};
}

#pragma endregion

#pragma region UpdateSection
void BirdManager::UpdateBirds() {
	for (Bird& bird : birds) {
		bird.UpdateTotalForces();
		bird.UpdateAcceleration();
		bird.UpdateVelocity();
		bird.UpdatePosition();
	}
}
#pragma endregion

#pragma region PrintFunctions

const void BirdManager::print_data() {
	for (int i = 0; i < NUMBER_OF_BOIDS; i++) {
		printf("Bird ID: %d\n", birds[i].id);
	}
	return;
}

const void BirdManager::print_data_single() {
	Bird b = birds[0];
	cout << "Sep " << b.separation[0] << b.separation[1] << b.separation[2] << endl;

	return;
}

const void BirdManager::print_positions() {
	int counter;
	for (int x = 0; x < 10; x++) {
		string line = "";
		for (int y = 0; y < 10; y++) {
			counter = 0;
			for (Bird b : birds) {
				int xTenths = static_cast<int>(b.position[0] * 10);
				int yTenths = static_cast<int>(b.position[1] * 10);

				if (xTenths == x && yTenths == y) {
					counter++;
				}
			}
			line += to_string(counter) + " ";
		}
		cout << line << endl;
	}

	return;
}

#pragma endregion


#pragma region OtherFunctions()
const void BirdManager::check_out_of_bounds() {
	for (Bird b : birds) {
		for (int i = 0; i < 3; ++i) {
			if (b.position[i] < 0.0 || b.position[i] >= WORLD_SIZE) {
				cout << "Bird ID " << b.id << " out of bounds on axis " << i << " with position " << b.position[i] << endl;
			}
		}
	}
	return;
}

#pragma endregion