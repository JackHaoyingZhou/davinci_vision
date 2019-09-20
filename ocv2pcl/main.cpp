#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
#include <stdio.h>
#include <vector>

#include <boost/thread/thread.hpp>
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/io/openni_grabber.h>
#include <pcl/point_cloud.h>
#include <pcl/console/parse.h>
#include <pcl/common/transforms.h>
#include <pcl/common/common_headers.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/point_types.h>

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace pcl;
using namespace cv;

vector<float> xdim;
vector<float> ydim;
vector<float> zdim;

Mat file_matrix;
float sumx;
float sumy;
float sumz;

int readPointcloud(string filename){
    sumx = 0;
    sumy = 0;
    sumz = 0;
    string str;
    int count = 0;

    uint8_t r = 255, g = 0, b = 0;
    uint32_t rgb = ((uint32_t)r << 16 | (uint32_t)g << 8 | (uint32_t)b);

    float x,y,z;

    ifstream file(filename);
    while(getline(file,str)){
        stringstream ss(str);
        //cout << str << endl;
        ss >> x >> y >> z;
        sumx = sumx + x;
        sumy = sumy + y;
        sumz = sumz + z;
        xdim.push_back(x);
        ydim.push_back(y);
        zdim.push_back(z);
        //cout << xdim[count] << endl;
        count++;
    }

//    cout << count << endl;
    sumx = sumx/count;
    sumy = sumy/count;
    sumz = sumz/count;

    xdim.push_back(sumx);
    ydim.push_back(sumy);
    zdim.push_back(sumz);

    return count;

}

boost::shared_ptr<pcl::visualization::PCLVisualizer> simpleVis (pcl::PointCloud<pcl::PointXYZ>::ConstPtr cloud){
    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer (new pcl::visualization::PCLVisualizer ("3D Viewer"));
    viewer->setBackgroundColor(0,0,0);
    viewer->addPointCloud<pcl::PointXYZ> (cloud, "sample cloud");
    viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "sample cloud");
    viewer->addCoordinateSystem(1.0);
    viewer->initCameraParameters ();
    return (viewer);
}

int main(int argc, char* argv[]) {

    std::string filename = "";
    //std::string filename2 = "";
    std::string fileout = "";
    std::string fileoutrgb = "";

    filename = argv[1];
    //filename2 = argv[2];
    fileout = argv[2];
//    fileoutrgb = argv[3];
    cout << filename << endl;
    cout << fileout << endl;

    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_ptr (new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PointCloud<pcl::PointXYZ> cloud_noPtr;
    pcl::PointCloud<pcl::PointXYZRGB> cloud_rgb;

    int psize = readPointcloud(filename);

    cout << "psize: " << psize << endl;
    cout << "sumx: " << sumx << endl;
    cout << "sumy: " << sumy << endl;
    cout << "sumz: " << sumz << endl;

    cloud_noPtr.width = psize;
    cloud_noPtr.height = 1;
    cloud_noPtr.is_dense = false;
    cloud_noPtr.points.resize (cloud_noPtr.width * cloud_noPtr.height);

    for (int i = 0; i < psize ; i ++){
//        cloud.points[i].x = xdim[i];
//        cloud.points[i].y = ydim[i];
//        cloud.points[i].z = zdim[i];
        pcl::PointXYZ cloud;
        cloud.x = -xdim[i];
        cloud.y = -ydim[i];
        cloud.z = -zdim[i];
        cloud_ptr->points.push_back(cloud);

//        cloud_noPtr.points[i].x = -xdim[i]/100;
//        cloud_noPtr.points[i].y = -ydim[i]/100;
//        cloud_noPtr.points[i].z = -zdim[i]/100;


    }

    cloud_ptr->width = (int) cloud_ptr->points.size();
    cloud_ptr->height = 1;

    for (int j = 0; j < 5; j++){
        cout << cloud_noPtr[j] << endl;

    }

    copyPointCloud(cloud_noPtr, cloud_rgb);
    pcl::io::savePCDFileASCII(fileout,cloud_noPtr);
//    pcl::io::savePCDFileASCII(fileoutrgb, cloud_rgb);

    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;
    viewer = simpleVis(cloud_ptr);

    while (!viewer->wasStopped()){

        viewer->spinOnce( 100 );
        boost::this_thread::sleep (boost::posix_time::microseconds(100000));

        int keyboard = waitKey(10);
        if(keyboard == 'q' || keyboard == 27)
        {
            break; //press esc or q to close the viewer
        }

    }

    return 0;
}
