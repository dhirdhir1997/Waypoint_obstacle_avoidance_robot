# https---github.com-dhirdhir1997-Waypoint

Waypoint_obstacle_avoidance

In this project a simple C++ code is written for the following scenario:

A robot is constrained to move in a bound 2D-space ([-1,-1] → [1,1]) interspersed with
obstacles. Assume for now that the robot is a point object and the obstacles have a circular
cross-section with varying diameters. Assume that the obstacle data is available to you in the
form of the position of their centers and diameters. We need the robot to explore the workspace
by choosing multiple waypoints in this space. Write a code in C++ to choose these waypoints
over the entire space such that
1. The waypoint does not lie inside any obstacle
2. The waypoint should be reachable from the previously chosen waypoint in a straight-line
path clear of any obstacles
The robot is initially placed at [-1,-1]

Assumptions:
1. There are three sample obstacles taken in the co-ordinate system


      {-0.2, -0.2, 0.3},   // Example obstacle 1 (center: [-0.2, -0.2], diameter: 0.3)
        {-0.5, -0.4, 0.2}, // Example obstacle 2 (center: [-0.5, -0.4], diameter: 0.2)
        {0.7, -0.7, 0.5}   // Example obstacle 3 (center: [0.7, -0.7], diameter: 0.5)
   
2. The robot is point object

        
