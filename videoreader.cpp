#include "videoreader.hh"

VideoReader::VideoReader(const std::string& file):
	file_name(file), video(file_name)
{
}

VideoReader::~VideoReader(){
	Close();
}

bool VideoReader::Open(const std::string &file)
{
	if(IsOpeened())
		Close();
	return video.open(file);
}

bool VideoReader::Open(const int& device_number)
{
	if(IsOpeened())
		Close();
	return video.open(device_number);
}

bool VideoReader::IsOpeened()
{
	return video.isOpened();
}

void VideoReader::Close()
{
	video.release();
}

bool VideoReader::GetFrame(cv::Mat& frame)
{
	return video.read(frame);
}
