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

	


};

