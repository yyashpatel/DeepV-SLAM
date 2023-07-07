#include <iostream>
#include <string>
#include <vector>
#include "opencv2/core.hpp"

#include "load_image_data.h"
#include "feature_matching.h"

int main()
{
    std::string image_path = "C:\\Users\\adity\\CLionProjects\\DeepV-SLAM\\data\\";

    std::vector<cv::Mat> images = load_images(image_path);
    cv::Mat image_1 = images[0];
    cv::Mat image_2 = images[1];

    features_2d(images[0], images[1]);
}
