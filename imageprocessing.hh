#ifndef IMAGEPROCESSING_HH
#define IMAGEPROCESSING_HH

#include "opencv2/imgproc/imgproc.hpp"


namespace ImageProcessing
{
void ToGrayScale(cv::Mat& img);
//cv::Mat& GetChannel(char channel, cv::Mat& img);
void ResizeImage(cv::Mat& img);
}


#endif // IMAGEPROCESSING_HH
