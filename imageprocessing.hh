#ifndef IMAGEPROCESSING_HH
#define IMAGEPROCESSING_HH

#include "opencv2/imgproc/imgproc.hpp"

#include "settings.hh"

namespace ImageProcessing
{
inline void ResizeImage(const cv::Mat& in, cv::Mat& out);
}


#endif // IMAGEPROCESSING_HH
