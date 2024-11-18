#include "Map.h"
#include <fstream>
#include <iostream>
#include <sstream>

Map::Map() {
    // TODO: Your code here
    // Initialize all distances to a value representing no direct connection
    // Initialize all provinces as unvisited
}

// Loads distance data from a file and fills the distanceMatrix
void Map::loadDistanceData(const std::string& filename) {
    // Read each line in the CSV file
    // Read each cell separated by a comma
    // Convert cell to an integer and store in distanceMatrix
	std::fstream file(filename);
	std::string line;

	int matrixRow = 0;
	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::string cell;
		int matrixCol = 0;
		while (std::getline(ss, cell, ',')) {
			distanceMatrix[matrixRow][matrixCol] = std::stoi(cell);
			matrixCol++;
		}
		matrixRow++;
	}

	std::cout << "Distance matrix loaded successfully!" << std::endl; // TODO: Remove this line in production
}

// Checks if the distance between two provinces is within the allowed maxDistance
bool Map::isWithinRange(int provinceA, int provinceB, int maxDistance) const {
	return distanceMatrix[provinceA][provinceB] <= maxDistance
}

// Marks a province as visited
void Map::markAsVisited(int province) {
	visited[province] = true;
}

// Checks if a province has already been visited
bool Map::isVisited(int province) const {
    return visited[province];
}

// Resets all provinces to unvisited
void Map::resetVisited() {
	std::fill(visited, visited + MAX_SIZE, false);
}

// Function to count the number of visited provinces
int Map::countVisitedProvinces() const {
    return std::count(visited, visited + MAX_SIZE, true);
}

// Function to get the distance between two provinces
int Map::getDistance(int provinceA, int provinceB) const {
    return distanceMatrix[provinceA][provinceB];
}