#include <cv_bridge/cv_bridge.h>
#include <iostream>
#include <nodelet/nodelet.h>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/core/core.hpp>
#include <pluginlib/class_list_macros.h>
#include <ros/ros.h>
#include <vector>

namespace test {
class TestNodelet : public nodelet::Nodelet {
public:
  explicit TestNodelet() = default;
  ~TestNodelet() = default;
  void onInit() {
    float pd[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    cv::Mat p(cv::Size(4, 3), CV_32F, pd);
    std::vector<cv::Point2f> xy;
    xy.push_back(cv::Point2f(2, 3));

    float rpd[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    cv::Mat rp(cv::Size(4, 3), CV_32F, rpd);
    std::vector<cv::Point2f> rxy;
    rxy.push_back(cv::Point2f(1, 2));
    float resultd[4] = {0.0, 0.0, 0.0, 0.0};
    cv::Mat result(cv::Size(1, 4), CV_32F, resultd);

    std::cerr << "OpenCV Header Version: " // << CV_VERSION_EPOCH << "."
              << CV_VERSION_MAJOR << "." << CV_VERSION_MINOR << "."
              << CV_VERSION_REVISION << std::endl;
    std::cerr << "before triangulate" << std::endl;
    cv::triangulatePoints(p, rp, xy, rxy, result);
    std::cerr << "after triangulate" << std::endl;
    std::cerr << "TestNodelet::onInit() done. Success." << std::endl;
  }
};
PLUGINLIB_EXPORT_CLASS(test::TestNodelet, nodelet::Nodelet)
}
