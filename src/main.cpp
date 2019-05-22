#include <iostream>

#include "CSimpleStitcher.hpp"
#include "opencv2/stitching.hpp"

int main()
{
    std::cout << "Starting..." << std::endl;
    SimpleStitcher::CSimpleStitcher stitcher;

    cv::Mat panorama;
    /// home/natalie/AdoreIT/PanoramaCreator/images/1.jpg
    if (stitcher.stitch(
            stitcher.readImages(std::vector<std::string>{
                "/home/natalie/AdoreIT/PanoramaCreator/images/1.jpg",
                "/home/natalie/AdoreIT/PanoramaCreator/images/2.jpg"}),
            panorama))
    {
        stitcher.writeResult(
            "/home/natalie/AdoreIT/PanoramaCreator/images/result.jpg",
            panorama);
    }

    return 0;
}
