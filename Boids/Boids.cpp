// Boids.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Bird.h"
#include "Constants.h"
#include "BirdManager.h"
#include <random>

using namespace std;

int main()
{
	std::srand(12345); // Seed for reproducibility

	int simulation_cycle = 0;


	BirdManager bird_manager = BirdManager();
	bird_manager.InitializeBirds(NUMBER_OF_BOIDS);
	while (true) {
		// Update and render boids
		//bird_manager.print_data();
		//cout<< "-----" << simulation_cycle++ << endl;
	}
	return 0;
}
