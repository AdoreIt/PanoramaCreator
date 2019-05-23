#include <iostream>

#include "opencv2/highgui.hpp"
#include "opencv2/imgcodecs.hpp"
#include "rapidjson/stringbuffer.h"

#include "CSimpleStitcher.hpp"

namespace PanoramaCreator {
namespace SimpleStitcher {

CSimpleStitcher::CSimpleStitcher()
{
    cv::Stitcher::Mode mode = cv::Stitcher::PANORAMA;
    m_stitcher = cv::Stitcher::create(mode, false);
}

CSimpleStitcher::CSimpleStitcher(const std::vector<std::string>& images_pathes)
{
    cv::Stitcher::Mode mode = cv::Stitcher::PANORAMA;
    m_stitcher = cv::Stitcher::create(mode, false);

    createPanorama(images_pathes);
}

std::vector<cv::Mat> CSimpleStitcher::readImages(const std::vector<std::string>& images_pathes)
{
    std::vector<cv::Mat> images;
    for (const std::string& image_path : images_pathes)
    {
        cv::Mat image = cv::imread(image_path);
        if (image.data != NULL)
        {
            images.push_back(cv::imread(image_path));
        }
        else
        {
            std::cout << "Image read error: "
                      << "Path " + image_path + " is not valid\n";
        }
    }
    return images;
}

void CSimpleStitcher::createPanorama(const std::vector<std::string>& images_pathes)
{
    std::vector<cv::Mat> images = readImages(images_pathes);

    std::cout << "Starting..." << std::endl;
    cv::Mat panorama;

    if (stitch(images, panorama))
    {
        writeResult("/home/natalie/AdoreIt/PanoramaCreator/images/result.jpg", panorama);
    }
}

cv::Mat CSimpleStitcher::resize(const cv::Mat& image, const float& size_persentage)
{
    cv::Mat resized_image;
    cv::resize(
        image,
        resized_image,
        cv::Size(image.cols * size_persentage, image.rows * size_persentage),
        0,
        0,
        CV_INTER_LINEAR);
    return resized_image;
}

bool CSimpleStitcher::stitch(const std::vector<cv::Mat>& images, cv::Mat& panorama)
{
    std::cout << images.size();
    cv::Stitcher::Status status = m_stitcher->stitch(images, panorama);

    if (status != cv::Stitcher::OK)
    {
        std::cout << "Can't stitch images, error code = " << int(status) << std::endl;
        return false;
    }

    std::cout << "stitching completed successfully\n";
    return true;
}

void CSimpleStitcher::writeResult(const std::string& save_path, const cv::Mat& panorama)
{
    cv::imwrite(save_path, panorama);
}

void CSimpleStitcher::showResult(const cv::Mat& panorama)
{
    cv::imshow("Final Panorama", panorama);
    cv::waitKey();
}

} // namespace SimpleStitcher
} // namespace PanoramaCreator
