#include "BirdManager.h"
#include <stdio.h>
#include "Utils.h"
#include <iostream>

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
		birds[i] = Bird(i);

		if (i == 0) {
			cout << new_bird.position[0] << ", " << new_bird.position[1] << ", " << new_bird.position[2] << endl;
		}
	}
}
void BirdManager::UpdateBirds(float deltaTime) {
	CalculateForces();

	return;
}

void BirdManager::CalculateForces() {
	for (Bird& this_bird : birds) {
		this_bird.separation = CalculateSeparation(this_bird);
		CalculateAlignment(this_bird);
		CalculateCohesion(this_bird);
	}
}

std::array<double, 3> BirdManager::CalculateSeparation(Bird this_bird) {
	std::array<double, 3> tmp_separation = { 0.0, 0.0, 0.0 };
	for (Bird other_bird : birds) {
		if (this_bird.id != other_bird.id) {
			std::array<double, 3> diff = Array3Subtract(this_bird.position, other_bird.position);
			double distanceSquared = diff[0] * diff[0] + diff[1] * diff[1] + diff[2] * diff[2];

			if (distanceSquared < SEPARATION_DISTANCE && distanceSquared > 0.0) {
				tmp_separation[0] += diff[0];
				tmp_separation[1] += diff[0];
				tmp_separation[2] += diff[0];
			}
		}
	}
	return tmp_separation;
}

std::array<double, 3> BirdManager::CalculateAlignment(Bird this_bird) {
	std::array<double, 3> tmp_alignment = { 0.0, 0.0, 0.0 };
	int counter = 0;
	
	for (Bird other_bird : birds) {
		if (this_bird.id != other_bird.id) {
			double distanceSquared = GetDistance(this_bird.position, other_bird.position);

			if (distanceSquared < SEPARATION_DISTANCE) {
				tmp_alignment[0] += other_bird.velocity[0];
				tmp_alignment[1] += other_bird.velocity[1];
				tmp_alignment[2] += other_bird.velocity[2];
				counter++;
			}
		}
	}
	if (counter > 0) {
		tmp_alignment = Array3Divide(tmp_alignment, static_cast<double>(counter));
		tmp_alignment = Array3Subtract(tmp_alignment, this_bird.velocity);
	}

	return tmp_alignment;
}

std::array<double, 3> BirdManager::CalculateCohesion(Bird this_bird) {
	std::array<double, 3> tmp_cohesion = { 0.0, 0.0, 0.0 };
	int counter = 0;

	for (Bird other_bird : birds) {
		if (this_bird.id != other_bird.id) {
			double distanceSquared = GetDistance(this_bird.position, other_bird.position);
			if (distanceSquared < COHESION_DISTANCE) {
				tmp_cohesion = Array3Addition(tmp_cohesion, other_bird.position);
				counter++;
			}
		}
	}

	if (counter > 0) {
		tmp_cohesion = Array3Divide(tmp_cohesion, static_cast<double>(counter));
		tmp_cohesion = Array3Subtract(tmp_cohesion, this_bird.position);
	}
	return tmp_cohesion;
}


const void BirdManager::print_data() {
	for (int i = 0; i < NUMBER_OF_BOIDS; i++) {
		printf("Bird ID: %d\n", birds[i].id);
	}
	return;
}