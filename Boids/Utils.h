#pragma once
#include <random>
#include <array>

inline std::array<double, 3> GetRandomFloat3() {
	std::array<double, 3> result = {};
	result[0] = static_cast<double>(std::rand()) / static_cast<double>(RAND_MAX);
	result[1] = static_cast<double>(std::rand()) / static_cast<double>(RAND_MAX);
	result[2] = static_cast<double>(std::rand()) / static_cast<double>(RAND_MAX);
	return result;
}

inline std::array<double, 3> Array3Divide(const std::array<double, 3>& arr, double scalar) {
	return { arr[0] / scalar, arr[1] / scalar, arr[2] / scalar };
}