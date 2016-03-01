#ifndef HAARCASCADECLASIFIER_HH
#define HAARCASCADECLASIFIER_HH

#include "opencv2/objdetect/objdetect.hpp"
#include "videoreader.hh"
#include "colors.hh"
#include "imageprocessing.hh"

class HaarCascadeClasifier
{
	cv::CascadeClassifier classifier;
public:
	HaarCascadeClasifier(const std::string& file);
	void Classify(cv::Mat& img);
};

#endif // HAARCASCADECLASIFIER_HH
