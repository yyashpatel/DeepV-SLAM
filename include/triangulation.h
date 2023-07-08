#ifndef TRIANGULATION_H
#define TRIANGULATION_H

#include <iostream>
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>

#include "opencv2/core.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/highgui.hpp"

cv::Mat triangulate3D(const std::vector<cv::Point2f> kp_l,
                    const std::vector<cv::Point2f> kp_r, 
                    const cv::Mat camera_proj_matrix, 
                    const cv::Mat camera_proj_matrix2);

#endif