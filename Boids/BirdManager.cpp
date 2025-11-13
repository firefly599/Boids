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
		CalculateSeparation(this_bird);
		CalculateAlignment(this_bird);
		CalculateCohesion(this_bird);
	}
}

void BirdManager::CalculateSeparation(Bird this_bird) {
	std::array<double, 3> tmp_separation = { 0.0, 0.0, 0.0 };
	for (Bird other_bird : birds) {
		if (this_bird.id != other_bird.id) {
			double dx = this_bird.position[0] - other_bird.position[0];
			double dy = this_bird.position[1] - other_bird.position[1];
			double dz = this_bird.position[2] - other_bird.position[2];
			double distanceSquared = dx * dx + dy * dy + dz * dz;

			if (distanceSquared < SEPARATION_DISTANCE * SEPARATION_DISTANCE && distanceSquared > 0.0) {
				tmp_separation[0] += dx;
				tmp_separation[1] += dy;
				tmp_separation[2] += dz;
			}
		}
	}
	return;
}

void BirdManager::CalculateAlignment(Bird this_bird) {
	// Placeholder for alignment logic
	return;
}

void BirdManager::CalculateCohesion(Bird this_bird) {
	// Placeholder for cohesion logic
	return;
}


const void BirdManager::print_data() {
	for (int i = 0; i < NUMBER_OF_BOIDS; i++) {
		printf("Bird ID: %d\n", birds[i].id);
	}
	return;
}