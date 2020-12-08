echo # davinci_vision

This repository contain the work on vision pipeline enhancement of the da Vinci robot.

# Introduction
This is part of the dVRK research at WPI AIM lab. The main application is the enhancement of the
vision pipeline of the da Vinci robot via the implementation of augmented reality through simplified process and open-source resource.

# Goal
This project's objective is to implement the augmented reality functionality in the da Vinci Research Kit through
the combination of the physical dVRK system and the AMBF simulation platform (developed by Dr. Adnan Munawar)

# Resource
The primary software resources in this project includes
- OpenCV
- Point Cloud Library (PCL)
- dVRK Library
- ROS

# Project Pipeline
The pipeline of the project is shown in the illustration below
![alt text](https://github.com/nsujumnong/davinci_vision/blob/master/vision%20pipeline%20diagram.png)

The concept of the work is to project the virtual object (ideally the pre-opt scanned image of the patient) on the dVRK endoscope camera feed. To achieve this, we create an overlay for the endoscope camera with the object from the virtual environment including the scanned model/object and simulated dVRK system.
