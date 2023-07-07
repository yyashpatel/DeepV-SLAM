#include "../include/triangulation.h"

cv::Mat triangulate3D(const std::vector<cv::Point2f> kp_l,
                    const std::vector<cv::Point2f> kp_r, 
                    const cv::Mat camera_proj_matrix1, 
                    const cv::Mat camera_proj_matrix2)
{
    cv::Mat points_4d, points_3d;

    cv::triangulatePoints(camera_proj_matrix1, camera_proj_matrix2, kp_l, kp_r, points_4d);

    //cv::divide(points_4d.colRange(0,3), points_4d.col(3), points_3d);

    std::cout<<points_4d.row(0)<<'\n'<<std::endl;

    return points_4d;

}