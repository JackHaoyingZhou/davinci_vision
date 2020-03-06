//=========================================
// This chroma key algorithm is based on the OpenCV chroma key tutorial from
// https://www.academia.edu/8916198/Chroma_Key_Green_Screen_Background_-_OpenCV
//
// The code is modified to fit the application for da Vinci Surgical System
// vision pipeline research and augmented reality implementation.
// The modification done by Nuttaworn Sujumnong <nsujumnong@wpi.edu>
//
//=========================================

#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>
#include <stdio.h>

#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <sensor_msgs/image_encodings.h>
#include <cv_bridge/cv_bridge.h>

#include <boost/program_options.hpp>

using namespace std;
using namespace cv;

//global variables
const int red_low_max = 255;
const int red_hight_max = 255;
int red_low, red_high;
double red_l,red_h;

const int green_low_max = 255;
const int green_hight_max = 255;
int green_low, green_high;
double green_l,green_h;

const int blue_low_max = 255;
const int blue_hight_max = 255;
int blue_low, blue_high;
double blue_l,blue_h;

// define the slider tracker
void on_trackbar(int, void*)
{
    red_l = getTrackbarPos("Red Low","Image Result1");
    red_h = getTrackbarPos("Red High","Image Result1");

    green_l = getTrackbarPos("Green Low","Image Result1");
    green_h = getTrackbarPos("Green High","Image Result1");

    blue_l = getTrackbarPos("Blue Low","Image Result1");
    blue_h = getTrackbarPos("Blue High","Image Result1");
}


// image callback function
void imageCallback(const sensor_msgs::ImageConstPtr& msg) {
    try {
        cv_bridge::CvImagePtr cv_ptr = cv_bridge::toCvCopy(msg, "bgr8");
        cv::imshow("view", cv_bridge::toCvShare(msg, "bgr8")->image);
        cv::waitKey(30);
    } catch (cv_bridge::Exception& e) {
        ROS_ERROR("Could not convert from '%s' to 'bgr8'.",
                msg->encoding.c_str());
    }
}

// chromaKey function
void chromakey(const Mat under, const Mat over, Mat *dst, const Scalar& color)
{
    *dst = Mat(under.rows, under.cols, CV_8UC3);

    for(int y=0; y<under.rows;y++)
    {
        for(int x=0; x<under.cols;x++)
        {
            int overColor0 = over.at<Vec3b>(y,x)[0];
            int overColor1 = over.at<Vec3b>(y,x)[1];
            int overColor2 = over.at<Vec3b>(y,x)[2];

            int underColor0 = under.at<Vec3b>(y,x)[0];
            int underColor1 = under.at<Vec3b>(y,x)[1];
            int underColor2 = under.at<Vec3b>(y,x)[2];

            if(over.at<Vec3b>(y,x)[0] >= red_l && over.at<Vec3b>(y,x)[0] <= red_h && over.at<Vec3b>(y,x)[1] >= green_l && over.at<Vec3b>(y,x)[1] <= green_h && over.at<Vec3b>(y,x)[2] >= blue_l && over.at<Vec3b>(y,x)[2] <= blue_h)
            //if(overColor0 >= red_l && overColor0 <= red_h && overColor1 >= green_l && overColor1 <= green_h && overColor2 >= blue_l && overColor2 <= blue_h)
            {
                //cout << "true" << endl;
                dst->at<Vec3b>(y,x)[0] = under.at<Vec3b>(y,x)[0];
                dst->at<Vec3b>(y,x)[1] = under.at<Vec3b>(y,x)[1];
                dst->at<Vec3b>(y,x)[2] = under.at<Vec3b>(y,x)[2];

            }
            else
            {
                //cout << "false" << endl;
                dst->at<Vec3b>(y,x)[0] = over.at<Vec3b>(y,x)[0];
                dst->at<Vec3b>(y,x)[1] = over.at<Vec3b>(y,x)[1];
                dst->at<Vec3b>(y,x)[2] = over.at<Vec3b>(y,x)[2];
            }
        }
    }
}


int main(int argc, char **argv) {

    // topic name argument
//    std::string imageinput1 = "";
//    std::string imageinput2 = "";

//    imageinput1 = argv[1];
//    imageinput2 = argv[2];

//    if(imageinput1.empty() || imageinput2.empty())
//    {
//        printf("Please specify the image/video type...");
//        return -1;
//    }

    // initialize ROS node
//    ros::init(argc, argv, "image_listener");
//    ros::NodeHandle nh;
//    namedWindow("view");
////    startWindowThread();
//    image_transport::ImageTransport it(nh);
//    image_transport::Subscriber sub = it.subscribe("ambf/image_data/default_camera",1,imageCallback);
////    ros::spin();
////    destroyWindow("view");


    //VideoCapture cap("../plane.mp4"); // Plane video on top layer
//    VideoCapture cap(0); // endoscope feed on tope layer
    VideoCapture cap("../suj_test2.mp4");
    VideoCapture cap1(0);
//    VideoCapture cap2();

    Mat imgRBG, imgRBG1, combined_images;

    int key = 0;
    Mat background = imread("../fjord.jpg");

    int count = 0;

    namedWindow("Image Result1", 1);

    createTrackbar("Red Low", "Image Result1", 0, 255, on_trackbar);
    createTrackbar("Red High", "Image Result1", 0, 255, on_trackbar);

    createTrackbar("Green Low", "Image Result1", 0, 255, on_trackbar);
    createTrackbar("Green High", "Image Result1", 0, 255, on_trackbar);

    createTrackbar("Blue Low", "Image Result1", 0, 255, on_trackbar);
    createTrackbar("Blue High", "Image Result1", 0, 255, on_trackbar);

    // For green screen background
    cvSetTrackbarPos("Red Low", "Image Result1", 0);
    cvSetTrackbarPos("Red High", "Image Result1", 220);

    cvSetTrackbarPos("Green Low", "Image Result1", 47);
    cvSetTrackbarPos("Green High", "Image Result1", 199);

    cvSetTrackbarPos("Blue Low", "Image Result1", 0);
    cvSetTrackbarPos("Blue High", "Image Result1", 121);


    // The algorithm is terminated/crashed when the video is ended.
    // If a live feed is used, the algorithm is terminted on key command.
    while(key!=27){
        cap >> imgRBG;
        cap1 >> imgRBG1;
        chromakey(background,imgRBG1, &combined_images, Scalar(100,200,185));

        imshow("Image Result1", combined_images);
        key = waitKey(30);
    }

    cap.release();
    cap1.release();

    destroyWindow("view");

    return 0;
}
