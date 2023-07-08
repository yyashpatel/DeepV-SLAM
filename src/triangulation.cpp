#include "../include/triangulation.h"

cv::Mat triangulate3D(const std::vector<cv::Point2f> kp_l,
                      const std::vector<cv::Point2f> kp_r,
                      const cv::Mat camera_proj_matrix1,
                      const cv::Mat camera_proj_matrix2)
{   
    // store homogeneous and cartesian coordinates
    cv::Mat points_4d, points_3d;

    // triangulate points and find homogeneous world coordinates
    cv::triangulatePoints(camera_proj_matrix1, camera_proj_matrix2, kp_l, kp_r, points_4d);

    // convert homogeneous coordinates to cartesian points
    cv::convertPointsFromHomogeneous(points_4d.t(), points_3d);

    return points_3d;
}