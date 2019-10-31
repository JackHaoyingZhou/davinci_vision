#include <iostream>
#include <fstream>
#include <string>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main(int argc, char* argv[]) {

    // usage: the program takes three arguments: image path, right image name, and left image name
    // the images are saved as png file format
    // the number of each set of image is added automatically until the program is reset
    // run: ./cv_stream full/path/to/save/location/ right_cam_name left_cam_name image_config_file_name

    VideoCapture cap1(0);
    VideoCapture cap2(1);

    // Open default camera
    if(!cap1.open(0))
    {
        cout << "can't find video0" << endl;
        return 0;
    }

    if(!cap2.open(1))
    {
        cout << "can't find video1" << endl;
        return 0;
    }

    int img_counter = 0;

    string path = "";
    string right_name = "";
    string left_name = "";
    string filename = "";
    path = argv[1];
    right_name = argv[2];
    left_name = argv[3];
    filename = argv[4];

    //cout << "num arguments: " << sizeof(argc) << endl;

    filename = path + filename;
    ofstream file;
    file.open(filename);

    file << "<?xml version=\"1.0\"?>\n<opencv_storage>\n<images>\n";

    for(;;)
    {
        Mat frame1;
        Mat frame2;
        cap1 >> frame1;
        cap2 >> frame2;

        if (frame1.empty() && frame2.empty())
        {
            break; // end of video stream
        }
        imshow("right camera", frame1);
        imshow("left camera", frame2);
        int keyboard = waitKey(30);
        if(keyboard == 'q' || keyboard == 27)
        {

            file << "</images>\n</opencv_storage>\n";
            file.close();
            break; // press ESC to stop the stream

        }
        else if (keyboard == 32)
        {
            // Press Spacebar to capture the stereo images
            img_counter++;
            string counter_str = to_string(img_counter);
            cout << "taking screenshot: " << path << "imageset#" << img_counter << endl;
            //string path = "/home/aimlab3/Endoscope_Snapshot/201908_chess/";
            //string right_name = "right.png";
            //string left_name = "left.png";
            imwrite(path + right_name + counter_str + ".png",frame1);
            imwrite(path + left_name + counter_str + ".png",frame2);

            file << path + left_name + counter_str + ".png\n";
            file << path + right_name + counter_str + ".png\n";
        }
    }

    return 0;
}
