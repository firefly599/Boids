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


inline double GetDistance(const std::array<double, 3>& a, const std::array<double, 3>& b) {
	double dx = a[0] - b[0];
	double dy = a[1] - b[1];
	double dz = a[2] - b[2];
	return std::sqrt(dx * dx + dy * dy + dz * dz);
}

inline std::array<double, 3> Array3Divide(const std::array<double, 3>& arr, double scalar) {
	return { arr[0] / scalar, arr[1] / scalar, arr[2] / scalar };
}

inline std::array<double, 3> Array3Subtract(const std::array<double, 3>& a, const std::array<double, 3>& b) {
	return { a[0] - b[0], a[1] - b[1], a[2] - b[2] };
}

inline std::array<double, 3> Array3Addition(const std::array<double, 3>& a, const std::array<double, 3>& b) {
	return { a[0] + b[0], a[1] + b[1], a[2] + b[2] };
}

inline std::array<double, 3> Array3Multiply(const std::array<double, 3>& a, double scalar) {
	return { a[0] * scalar, a[1] * scalar, a[2] * scalar };
}