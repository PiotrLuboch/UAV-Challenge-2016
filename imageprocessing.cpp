#include "imageprocessing.hh"

#include "settings.hh"


void ImageProcessing::ResizeImage(cv::Mat& img)
{
	cv::resize(img.clone(), img, cv::Size(720,576));
}

void ImageProcessing::ToGrayScale(cv::Mat& img)
{
	cv::cvtColor(img,img,cv::COLOR_BGR2GRAY);
}
