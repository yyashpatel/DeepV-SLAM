#ifndef CAMERA_POSE_H
#define CAMERA_POSE_H

#include <iostream>
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>

#include "opencv2/core.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/highgui.hpp"

void estimatePose(const std::vector<cv::Point2f> kp_l, const std::vector<cv::Point2f> kp_r);

#endif