#include "../include/feature_matching.h"



std::tuple<std::vector<cv::Point2f>, std::vector<cv::Point2f>> features_2d(const cv::Mat image_1, const cv::Mat image_2)
{
    assert(image_1.data != nullptr && image_2.data != nullptr);

    std::vector<cv::KeyPoint> keypoints_1, keypoints_2;
    std::vector<cv::Point2f> kp_img_1, kp_img_2;
    std::vector<cv::DMatch> good_matches;

    // Initialize feature detectors and descriptors
    cv::Ptr<cv::ORB> detector = cv::ORB::create();
    cv::Ptr<cv::DescriptorMatcher> matcher = cv::DescriptorMatcher::create("BruteForce-Hamming");

    cv::Mat descriptors_1, descriptors_2;
    detector->detectAndCompute(image_1, cv::noArray(), keypoints_1, descriptors_1);
    detector->detectAndCompute(image_2, cv::noArray(), keypoints_2, descriptors_2);

    // cv::Mat descriptors_1, descriptors_2;
    // cv::Ptr<FeatureDetector> detector = ORB::create();
    // cv::Ptr<DescriptorExtractor> descriptor = ORB::create();

    std::vector<cv::DMatch> brute_hamming_matches;
    matcher->match(descriptors_1, descriptors_2, brute_hamming_matches);

    double min_dist=10000, max_dist=0;

    for ( int i = 0; i < descriptors_1. rows; i++ )
    {
        double dist = brute_hamming_matches[i].distance;
        if ( dist < min_dist ) min_dist = dist;
        if ( dist > max_dist ) max_dist = dist;
    }


    for ( int i = 0; i < descriptors_1.rows; i++ )
    {
        if ( brute_hamming_matches[i].distance <= std::max( 2*min_dist, 20.0 ) )
        {
            good_matches.push_back(brute_hamming_matches[i]);
        }
    }

    for (int i = 0; i < (int) good_matches.size(); i++) 
    {
        kp_img_1.push_back(keypoints_1[good_matches[i].queryIdx].pt);
        kp_img_2.push_back(keypoints_2[good_matches[i].trainIdx].pt);
    }

    // cv::Mat matchImg;
    // cv::drawMatches(image_1, keypoints_1, image_2, keypoints_2, brute_hamming_matches, matchImg);
    // cv::imshow("Matches", matchImg);
    // cv::waitKey(0);
    return std::make_tuple(kp_img_1, kp_img_2);   
}
