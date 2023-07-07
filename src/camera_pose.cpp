#include "../include/camera_pose.h"


void estimatePose(const std::vector<cv::Point2f> kp_l, const std::vector<cv::Point2f> kp_r)
{
    cv::Mat f_matrix = cv::findFundamentalMat(kp_l, kp_r, cv::FM_8POINT);
    std::cout<<"Fundamental Matrix:\n"<<f_matrix<<std::endl;;

    cv::Mat camera_matrix = (cv::Mat_<double>(3, 3) << 535.4, 0, 320.1, 0, 539.2, 247.6, 0, 0, 1);

    // Compute the essential matrix
    cv::Mat essential_matrix = cv::findEssentialMat(kp_l, kp_r, camera_matrix, cv::RANSAC, 0.999, 1.0);
    
    // Display the essential matrix
    std::cout << "Essential Matrix:\n" << essential_matrix << std::endl;

    // Recover the camera pose (rotation and translation)
    cv::Mat rot_matrix, trans_vector;
    cv::recoverPose(essential_matrix, kp_l, kp_r, camera_matrix, rot_matrix, trans_vector);
    
    // Display the rotation and translation
    std::cout << "Rotation Matrix:\n" << rot_matrix << std::endl;
    std::cout << "Translation Vector:\n" << trans_vector << std::endl;
    // focalLength    = [535.4, 539.2]; 
    // principalPoint = [320.1, 247.6]; 
}