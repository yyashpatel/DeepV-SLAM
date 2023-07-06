#include <iostream>
#include <string>
#include <vector>
#include "opencv2/core.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/highgui.hpp"

#include "load_image_data.hpp"
// const int max_features=500;

// std::string image_path ;

int main()
{
    std::string image_path = "/home/yash/Documents/DeepV-SLAM/data/";

    std::vector<cv::Mat> images = load_images(image_path);
    std::cout<<"all images saved";
    std::cout<<images.size();
}