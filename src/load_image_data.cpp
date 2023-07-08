//
// Created by adity on 7/6/2023.
//

#include "../include/load_image_data.h"

std::vector<cv::Mat> LoadImages(const std::string &imagePath)
{
    std::vector<cv::Mat> image_data;

    cv::String pattern = imagePath + "/" + "*.png";
    std::cout << "[Matching Pattern]" << pattern;
    std::vector<cv::String> imageFiles;
    cv::glob(pattern, imageFiles, false);
    for (const auto &file : imageFiles)
    {
        cv::Mat image = cv::imread(file);
        image_data.push_back(image);
    }
    return image_data;
}
