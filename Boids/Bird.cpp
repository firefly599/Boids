#include "Bird.h"

void Bird::UpdateTotalForces()
{
	totalForce[0] = (separation[0] * SEPARATION_WEIGHT) + (alignment[0] * ALIGNMENT_WEIGHT) + (cohesion[0] * COHESION_WEIGHT);
	totalForce[1] = (separation[1] * SEPARATION_WEIGHT) + (alignment[1] * ALIGNMENT_WEIGHT) + (cohesion[1] * COHESION_WEIGHT);
	totalForce[2] = (separation[2] * SEPARATION_WEIGHT) + (alignment[2] * ALIGNMENT_WEIGHT) + (cohesion[2] * COHESION_WEIGHT);
}

void Bird::UpdateAcceleration() {
	// F = Ma -> a = F / M
	acceleration = Array3Divide(totalForce, mass);
}

void Bird::UpdateVelocity() {
	velocity = Array3Addition(Array3Multiply(acceleration, DELTA_T), velocity);
}

void Bird::UpdatePosition() {
	position = Array3Addition(Array3Multiply(velocity, DELTA_T), position);
}