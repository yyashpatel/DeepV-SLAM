#include <iostream>
#include <string>
#include <vector>
#include "opencv2/core.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/highgui.hpp"

std::vector<cv::Mat> load_images(const std::string& imagePath)
{
    std::vector<cv::Mat> image_data;

    std::string folderPath = "/home/yash/Documents/image_data";
    cv::String pattern = folderPath + "*.jpg";
    
    std::vector<cv::String> imageFiles;
    cv::glob(pattern, imageFiles, false); 
    for (const auto& file : imageFiles) 
    {
        cv::Mat image = cv::imread(file);
        image_data.push_back(image)    
    }
    return image_data
}