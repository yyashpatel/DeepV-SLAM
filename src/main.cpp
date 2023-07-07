#include <iostream>
#include <string>
#include <vector>
#include "opencv2/core.hpp"

#include "../include/load_image_data.h"
#include "../include/feature_matching.h"
#include "../include/camera_pose.h"


int main()
{
    //std::string image_path = "C:\\Users\\adity\\CLionProjects\\DeepV-SLAM\\data\\";
    std::string image_path = "/home/yash/Documents/DeepV-SLAM/data/";
    std::vector<cv::Mat> images = load_images(image_path);
    cv::Mat image_1 = images[0];
    cv::Mat image_2 = images[1];

    std::tuple<std::vector<cv::Point2f>, std::vector<cv::Point2f>> key_pts = features_2d(images[0], images[1]);
    std::vector<cv::Point2f> kp_l = std::get<0>(key_pts);
    std::vector<cv::Point2f> kp_r = std::get<1>(key_pts);

    estimatePose(kp_l,kp_r);

}
