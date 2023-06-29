#include <iostream>
#include <string>
#include <vector>
#include "opencv2/core.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/highgui.hpp"
// const int max_features=500;

void load_images(){
    std::string folderPath = "/home/yash/Documents/image_data";
    cv::String pattern = folderPath + "*.jpg";
    
    std::vector<cv::String> imageFiles;
    cv::glob(pattern, imageFiles, false); 
    for (const auto& file : imageFiles) 
    {
        cv::Mat image = cv::imread(file);
        
    }
}

int main(){
    return 0;
}