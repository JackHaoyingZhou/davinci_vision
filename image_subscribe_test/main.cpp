// Testing code for ROS to OpenCV image subscription

#include <iostream>

#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/Image.h>

//void imageCallback(const sensor_msgs::ImageConstPtr& msg)
//{
//    try
//    {
//        cv_bridge::CvImagePtr cv_ptr = cv_bridge::toCvShare(msg, "bgr8");
//        cv::imwrite("rgb.bmp", cv_ptr->image);
//        cv::imshow("view", cv_bridge::toCvShare(msg,"bgr8")->image);
//        cv::waitKey(30);
//    }
//    catch(cv_bridge::Exception& e)
//    {
//        ROS_ERROR("Could not convert from '%s' to 'bgr8'.", msg->encoding.c_str());
//    }
//}

void imageCallback(const sensor_msgs::ImageConstPtr& msg) {
    try {
        cv_bridge::CvImagePtr cv_ptr = cv_bridge::toCvCopy(msg, "bgr8");
        cv::imwrite("rgb.bmp", cv_ptr->image);
        cv::imshow("view", cv_bridge::toCvShare(msg, "bgr8")->image);
        cv::waitKey(30);
    } catch (cv_bridge::Exception& e) {
        ROS_ERROR("Could not convert from '%s' to 'bgr8'.",
                msg->encoding.c_str());
    }
}


int main(int argc, char **argv)
{
      ros::init(argc, argv, "image_listener");
      ros::NodeHandle nh;
      cv::namedWindow("view");
      cv::startWindowThread();
      image_transport::ImageTransport it(nh);
      image_transport::Subscriber sub = it.subscribe("camera/image", 1, imageCallback);
      ros::spin();
      cv::destroyWindow("view");
      return 0;
}

//#include <iostream>
//#include <stdio.h>

//#include <ros/ros.h>
//#include <image_transport/image_transport.h>
//#include <sensor_msgs/image_encodings.h>
//#include <cv_bridge/cv_bridge.h>

//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/imgproc/imgproc.hpp>

//using namespace std;
//using namespace cv;

//void imageCallback(const sensor_msgs::ImageConstPtr& msg)
//{
//    try
//    {
//        imshow("view", cv_bridge::toCvShare(msg, "bgr8")->image);
//        waitKey(30);
//    }
//    catch(cv_bridge::Exception& e)
//    {
//        ROS_ERROR("Could not convert from '&s' to 'bgr8'.", msg->encoding.c_str());
//    }
//}

//int main(int argc, char **argv)
//{
//    ros::init(argc, argv, "image_listener");
//    ros::NodeHandle nh;
//    cv::namedWindow("view");
//    cv::startWindowThread();
//    image_transport::ImageTransport it(nh);
//    image_transport::Subscriber sub = it.subscribe("camera/image", 1, imageCallback);
//    ros::spin();
////    cv::destroyWindow("view");
//}
