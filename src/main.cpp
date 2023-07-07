#include <iostream>
#include <string>
#include <vector>
#include "opencv2/core.hpp"

#include "../include/load_image_data.h"
#include "../include/feature_matching.h"
#include "../include/camera_pose.h"
#include "../include/triangulation.h"



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

    std::tuple<cv::Mat, cv::Mat, cv::Mat> pose = estimatePose(kp_l,kp_r);
    cv::Mat rot_matrix = std::get<0>(pose);
    cv::Mat trans_vector = std::get<1>(pose);
    cv::Mat camera_center = std::get<2>(pose);

    cv::Mat camera_proj_matrix1 = cv::Mat::eye(3, 4, CV_64F);
    cv::Mat camera_proj_matrix2;
    camera_proj_matrix2.convertTo(camera_proj_matrix2, CV_64F);
    cv::hconcat(rot_matrix, trans_vector, camera_proj_matrix2);

    cv::Mat points_4d = triangulate3D(kp_l, kp_r, camera_proj_matrix1, camera_proj_matrix2);


}
