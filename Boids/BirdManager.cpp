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
	return;
}

const void BirdManager::print_data() {
	for (int i = 0; i < NUMBER_OF_BOIDS; i++) {
		printf("Bird ID: %d\n", birds[i].id);
	}
	return;
}