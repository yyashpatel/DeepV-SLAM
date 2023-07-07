//
// Created by adity on 7/6/2023.
//

#include "load_image_data.h"

std::vector<cv::Mat> load_images(const std::string& imagePath)
{
    std::vector<cv::Mat> image_data;

    cv::String pattern = imagePath + "*.png";
    std::cout << pattern;
    std::vector<cv::String> imageFiles;
    cv::glob(pattern, imageFiles, false);
    for (const auto& file : imageFiles)
    {
        std::cout<<file<< '\n';
        cv::Mat image = cv::imread(file);
        image_data.push_back(image);
    }
    return image_data;
}