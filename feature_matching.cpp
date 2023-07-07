#include <iostream>
#include <string>
#include <vector>
#include "opencv2/core.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/highgui.hpp"

#include "load_image_data.hpp"
// const int max_features=500;

// std::string image_path ;

int main()
{
    std::string image_path = cv::samples::findFile("starry_night.jpg");
    std::vector<cv::Mat> images = load_images(image_path);
    std::cout<<"all images saved";
    std::cout<<images.size();
    std::cout << CV_VERSION << std::endl;

    cv::Mat img = cv::imread(image_path, cv::IMREAD_COLOR);

    if (img.empty()) {
        std::cout << "Could not read the image:" << image_path << "\n";
        return 1;
    }

    cv::imshow("IMage", img);
    int k = cv::waitKey(0);

    if (k == 's') {
        imwrite("starry_night", img);
    }
    return 0;
}
