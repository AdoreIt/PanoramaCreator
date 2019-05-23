#pragma once

#include <opencv2/core/cvstd.hpp>
#include "opencv2/stitching.hpp"

namespace PanoramaCreator {
namespace SimpleStitcher {

class CSimpleStitcher
{
public:
    CSimpleStitcher();
    CSimpleStitcher(const std::vector<std::string>& images_pathes);

    std::vector<cv::Mat> readImages(const std::vector<std::string>& images_pathes);

    void createPanorama(const std::vector<std::string>& images_pathes);

    cv::Mat resize(const cv::Mat& image, const float& size_persentage);
    bool stitch(const std::vector<cv::Mat>& images, cv::Mat& panorama);
    cv::Mat cropRedundant(const cv::Mat& panorama);

    void writeResult(const std::string& save_path, const cv::Mat& panorama);
    void showResult(const cv::Mat& panorama);

private:
    cv::Ptr<cv::Stitcher> m_stitcher;
};

} // namespace SimpleStitcher
} // namespace PanoramaCreator
