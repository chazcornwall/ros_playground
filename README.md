# ros_playground
place for testing and playing around with ros

# Create new package

1. Go into `src` directory
2. Use `catkin_create_pkg` cli tool

# Build all packages in workspace

1. Source ros
2. Run `catkin_make`

**NOTE** For python nodes, do not forget to make the node an executable: `chmod +x scripts/<python file>.py`

# Run nodes

1. Launch `roscore` in another window
2. `source devel/setup.bash` 
3. `rosrun <package name> <node name>`
