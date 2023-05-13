#include <iostream>
#include <vector>
#include <cmath>

// Structure to represent an obstacle
struct Obstacle 
{
    double x;       // x-coordinate of the obstacle center
    double y;       // y-coordinate of the obstacle center
    double diameter; // diameter of the obstacle
};

// Function to check if a point lies inside any obstacle
bool Obstacleavoidance(double x, double y, const std::vector<Obstacle>& obstacles) {
    for (const Obstacle& i : obstacles) 
    {
        double distance = std::hypot(x - i.x, y - i.y);
        if (distance <= i.diameter / 2.0) 
        {
            return true; // Point lies inside an obstacle
        }
    }
    return false; // Point does not lie inside any obstacle
}

int main() 
{
    std::vector<Obstacle> obstacles = 
    {
        {-0.2, -0.2, 0.3},   // Example obstacle 1 (center: [-0.2, -0.2], diameter: 0.3)
        {-0.5, -0.4, 0.2}, // Example obstacle 2 (center: [-0.5, -0.4], diameter: 0.2)
        {0.7, -0.7, 0.5}   // Example obstacle 3 (center: [0.7, -0.7], diameter: 0.5)
    };

    std::vector<std::pair<double, double>> waypoints; // Stores the selected waypoints

    double currentX = -1.0; // Starting x-coordinate
    double currentY = -1.0; // Starting y-coordinate

    waypoints.emplace_back(currentX, currentY); // Add the starting point as the first waypoint

    while (currentX < 1.0 && currentY < 1.0) 
    {
        double nextX = currentX + 0.1; // Increment x-coordinate by 0.1
        double nextY = currentY + 0.1; // Increment y-coordinate by 0.1

        // Check if the next waypoint lies inside any obstacle
        if (!Obstacleavoidance(nextX, nextY, obstacles)) 
        {
            waypoints.emplace_back(nextX, nextY); // Add the next waypoint
            currentX = nextX; // Update the current x-coordinate
            currentY = nextY; // Update the current y-coordinate
        } else 
        {
            currentX += 0.1; // Move only in the x-direction if the next waypoint is inside an obstacle
        }
    }

    // Print the positions and diameters of the obstacles
    std::cout << "Obstacles:\n";
    for (const Obstacle& j : obstacles) 
    {
        std::cout << "Position: [" << j.x << ", " << j.y << "], Diameter: " << j.diameter << "\n";
    }

    // Print the coordinates of the waypoints
    std::cout << "Waypoints:\n";
    for (const auto& k : waypoints) 
    {
        std::cout << "[" << k.first << ", " << k.second << "]\n";
    }

    return 0;
}
