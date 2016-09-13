# Robot_Paths
This is the project to navigate robots in different pahts using Robot Operating System (ROS). Scripts written in C++.
There are multiple executables to move robots (in my case I used Turtlebot 2 Kobuki base) in a certain paths.
In the include folder there are multiple header files to move robot in a circle (time-based), to move robot in a square path based on the robot's odometry (robot's wheel encoders and so on) and the last file is a simple executable to mave robot forward.
In addition there are multiple other files in the src folder to move robot in a square spiral path, to mimic the movement of the other robot and display the current posiiton of the robot based on its own odometry.
