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
	// Velocity update: v(x) += a(x) * Delta_t
	velocity = Array3Addition(Array3Multiply(acceleration, DELTA_T), velocity);
}

void Bird::UpdatePosition() {
	// Position update: p(x) += velocity(x) * Delta_t
	position = Array3Addition(Array3Multiply(velocity, DELTA_T), position);
	wrapPosition();
}

void Bird::wrapPosition() {
	for (int i = 0; i < 3; ++i) {
		if (position[i] < 0.0) {
			position[i] += WORLD_SIZE;
		} else if (position[i] >= WORLD_SIZE) {
			position[i] -= WORLD_SIZE;
		}
	}
}