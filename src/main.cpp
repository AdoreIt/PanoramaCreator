#include <iostream>

#include "CSimpleStitcher.hpp"
#include "opencv2/stitching.hpp"

int main()
{
    PanoramaCreator::SimpleStitcher::CSimpleStitcher stitcher(
        std::vector<std::string>{"/home/natalie/AdoreIt/PanoramaCreator/images/1.jpg",
                                 "/home/natalie/AdoreIt/PanoramaCreator/images/2.jpg"});

    return 0;
}
