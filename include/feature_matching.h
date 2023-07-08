#ifndef FEATURE_MATCHING_H
#define FEATURE_MATCHING_H

#include <iostream>
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>
#include "opencv2/core.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/highgui.hpp"

std::tuple<std::vector<cv::Point2f>, std::vector<cv::Point2f>> FindAndMatchFeatures(const cv::Mat image_1, const cv::Mat image_2);
std::tuple<std::vector<cv::KeyPoint>, cv::Mat> RegisterNewImage(const cv::Mat image_new);
#endif
