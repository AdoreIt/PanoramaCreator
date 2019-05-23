#include <iostream>

#include "CSimpleStitcher.hpp"
#include "opencv2/stitching.hpp"

int main()
{
    std::cout << "Starting..." << std::endl;
    SimpleStitcher::CSimpleStitcher stitcher;

    cv::Mat panorama;

    if (stitcher.stitch(
            stitcher.readImages(std::vector<std::string>{
                "/home/natalie/AdoreIt/PanoramaCreator/images/1.jpg",
                "/home/natalie/AdoreIt/PanoramaCreator/images/2.jpg"}),
            panorama))
    {
        stitcher.writeResult(
            "/home/natalie/AdoreIt/PanoramaCreator/images/result.jpg",
            panorama);
    }

    return 0;
}
