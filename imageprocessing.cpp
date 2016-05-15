#include "imageprocessing.hh"

#include "settings.hh"

void ImageProcessing::ResizeImage(cv::Mat& img)
{
	cv::resize(img.clone(), img, cv::Size(720, 576));
}
/*
cv::Mat& ImageProcessing::GetChannel(char channel, cv::Mat& img)
{
	switch (channel)
	{
	case 'r':
		return img.
	case 'g':
		break;
	case 'b':
		break;
	default:
		return cv::Mat();
	}
}*/

void ImageProcessing::ToGrayScale(cv::Mat& img)
{
	cv::cvtColor(img, img, cv::COLOR_BGR2GRAY);
}
