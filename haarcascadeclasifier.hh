#ifndef HAARCASCADECLASIFIER_HH
#define HAARCASCADECLASIFIER_HH

#include <thread>
#include <vector>
#include <mutex>

#include "opencv2/objdetect/objdetect.hpp"
#include "videoreader.hh"
#include "colors.hh"
#include "imageprocessing.hh"

class HaarCascadeClasifier
{
	cv::CascadeClassifier classifier;
	std::vector<cv::Rect> obj[4];
	void ClassifyPart(cv::Mat& img, const cv::Rect& cord, const int& index);
	std::thread threadClassifier(cv::Mat& img, const cv::Rect& cord, const int& index);
	static std::mutex mtx;
public:
	HaarCascadeClasifier(const std::string& file);
	void Classify(cv::Mat& img);
};

#endif // HAARCASCADECLASIFIER_HH
