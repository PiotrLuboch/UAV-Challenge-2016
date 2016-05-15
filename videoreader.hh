#ifndef VIDEOREADER_HH
#define VIDEOREADER_HH

#include <string>
#include "imageprocessing.hh"
#include "opencv2/highgui/highgui.hpp"

class VideoReader
{
	std::string file_name;
	cv::VideoCapture video;
public:
	VideoReader(const std::string& file);
	~VideoReader();
	bool Open(const std::string& file);
	bool Open(const int& device_number);
	bool IsOpeened();
	void Close();
	bool GetFrame(cv::Mat& frame);
};

#endif // VIDEOREADER_HH
