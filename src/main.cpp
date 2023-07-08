#include <iostream>
#include <string>
#include <vector>
#include "opencv2/core.hpp"

#include "load_image_data.h"
#include "feature_matching.h"
#include "camera_pose.h"
#include "triangulation.h"
#include <filesystem>

int main()
{ // print the library versions
    std::cout << "[OpenCV Version] " << CV_VERSION << "\n";

    // dynamically infer the data directory
    std::filesystem::path current_path = std::filesystem::current_path().parent_path() / "data";
    const std::string &image_path = current_path.generic_string();
    std::cout << "[Current Image Directory] " << image_path << "\n\n";

    // load all the images
    std::vector<cv::Mat> images = LoadImages(image_path);

    // feature matching with initial 2 best images
    std::tuple<std::vector<cv::Point2f>, std::vector<cv::Point2f>> key_pts = FindAndMatchFeatures(images[0], images[1]);
    std::vector<cv::Point2f> kp_l = std::get<0>(key_pts);
    std::vector<cv::Point2f> kp_r = std::get<1>(key_pts);

    // pose estimation of inital 2 images
    std::tuple<cv::Mat, cv::Mat, cv::Mat> pose = EstimatePose(kp_l, kp_r);
    cv::Mat rot_matrix = std::get<0>(pose);
    cv::Mat trans_vector = std::get<1>(pose);
    cv::Mat camera_center = std::get<2>(pose);

    cv::Mat camera_proj_matrix1 = cv::Mat::eye(3, 4, CV_64F);
    cv::Mat camera_proj_matrix2;
    camera_proj_matrix2.convertTo(camera_proj_matrix2, CV_64F);
    cv::hconcat(rot_matrix, trans_vector, camera_proj_matrix2);

    cv::Mat points_3d = triangulate3D(kp_l, kp_r, camera_proj_matrix1, camera_proj_matrix2);
    for (int i = 0; i < images.size(); i++)
    {
        std::tuple<std::vector<cv::KeyPoint>, cv::Mat> key_des_new = RegisterNewImage(images[i]);
        std::vector<cv::KeyPoint> kp_new = std::get<0>(key_des_new);
        cv::Mat des_new = std::get<1>(key_des_new);
    }
    return 0;
}
