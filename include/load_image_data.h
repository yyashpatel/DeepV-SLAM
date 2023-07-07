//
// Created by adity on 7/6/2023.
//

#ifndef LOAD_IMAGE_DATA_H
#define LOAD_IMAGE_DATA_H

#include <iostream>
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>

#include "opencv2/core.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/highgui.hpp"

std::vector<cv::Mat> load_images(const std::string& imagePath);

#endif
