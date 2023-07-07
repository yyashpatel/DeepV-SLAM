#include "feature_matching.h"

void features_2d(const cv::Mat image_1, const cv::Mat image_2)
{
    assert(image_1.data != nullptr && image_2.data != nullptr);

    std::vector<cv::KeyPoint> keypoints_1, keypoints_2;
    std::vector<cv::KeyPoint> kp_1_matched, kp_2_matched;

    // Initialize feature detectors and descriptors
    cv::Ptr<cv::ORB> detector = cv::ORB::create();
    cv::Ptr<cv::DescriptorMatcher> matcher = cv::DescriptorMatcher::create("BruteForce-Hamming");

    cv::Mat descriptors_1, descriptors_2;
    detector->detectAndCompute(image_1, cv::noArray(), keypoints_1, descriptors_1);
    detector->detectAndCompute(image_2, cv::noArray(), keypoints_2, descriptors_2);

    // cv::Mat descriptors_1, descriptors_2;
    // cv::Ptr<FeatureDetector> detector = ORB::create();
    // cv::Ptr<DescriptorExtractor> descriptor = ORB::create();


    // detector->detect(image_1, keypoints_1);
    // detector->detect(image_2, keypoints_2);

    // descriptor->compute(image_1, keypoints_1, descriptors_1);
    // descriptor->compute(image_2, keypoints_2, descriptors_2);

    std::vector<cv::DMatch> brute_hamming_matches;
    matcher->match(descriptors_1, descriptors_2, brute_hamming_matches);

    double min_dist=10000, max_dist=0;

    for ( int i = 0; i < descriptors_1. rows; i++ )
    {
        double dist = brute_hamming_matches[i].distance;
        if ( dist < min_dist ) min_dist = dist;
        if ( dist > max_dist ) max_dist = dist;
    }

    std::vector<cv::DMatch> good_matches;


    for ( int i = 0; i < descriptors_1.rows; i++ )
    {
        if ( brute_hamming_matches[i].distance <= std::max( 2*min_dist, 20.0 ) )
        {
            good_matches.push_back(brute_hamming_matches[i]);
        }
    }

    for (auto match : good_matches)
    {

        kp_1_matched.push_back(keypoints_1[match.queryIdx]);
        kp_2_matched.push_back(keypoints_2[match.trainIdx]);

    }

    //std::cout<<kp_1_matched<<'\n';
    //std::cout<<kp_2_matched<<std::endl;

    cv::Mat matchImg;
    cv::drawMatches(image_1, keypoints_1, image_2, keypoints_2, brute_hamming_matches, matchImg);
    cv::imshow("Matches", matchImg);
    cv::waitKey(0);
}
