#pragma once

#include <opencv2/core/cvstd.hpp>
#include "opencv2/stitching.hpp"

namespace SimpleStitcher {

class CSimpleStitcher
{
public:
    CSimpleStitcher();

    std::vector<cv::Mat> readImages(
        const std::vector<std::string>& images_pathes);

    bool stitch(const std::vector<cv::Mat>& images, cv::Mat& panorama);
    void writeResult(const std::string& save_path, const cv::Mat& panorama);
    void showResult(const cv::Mat& panorama);

private:
    cv::Ptr<cv::Stitcher> m_stitcher;
};

} // namespace SimpleStitcher