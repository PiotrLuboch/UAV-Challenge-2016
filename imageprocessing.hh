#ifndef IMAGEPROCESSING_HH
#define IMAGEPROCESSING_HH

#include "opencv2/core/core.hpp"

using uint = unsigned;
namespace ImageProcessing
{
bool ResizeImage(cv::Mat& img, const uint& width, const uint& height);


}


#endif // IMAGEPROCESSING_HH
