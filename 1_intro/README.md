# Introduction to ROS2
The following information is designed for the use of ROS2 Humble on Ubuntu 22.04
## Ressources
### Official tutorial
To help you go through this class you could find support on [official ros2 tutorial](https://docs.ros.org/en/humble/Tutorials.html).
### Classic ROS2 command

<details>
  <summary>Click to extend</summary>
  Hidden message
</details>


## Starting
### Set-up workspace
There is few lines to add to your `.bashrc` to makes things easier for you afterwards
```
export ROS_DOMAIN_ID=<your_domain_id>
# export ROS_LOCALHOST_ONLY=1
source /opt/ros/humble/setup.bash

source ~/ros2_ws/install/setup.bash
```

### Goals
Try to follow the tutorial on https://docs.ros.org/en/humble/Tutorials/Beginner-Client-Libraries/Colcon-Tutorial.html 

You have 3 objectives:
- Write a subscriber/publisher sending the name of your computer and your domain id.
- With a other node. Write a service server/client sendind the name of your computer and your domain id and answering if it is the good one.
- Write a launch file that allow to launch both service client and subscriber, use a parameter to define what are the correct string and the correct number to send to the service client.

