#include "imageprocessing.hh"



void ImageProcessing::ResizeImage(const cv::Mat& in, cv::Mat& out)
{
	cv::resize(in, out, Settings::new_size);
}
