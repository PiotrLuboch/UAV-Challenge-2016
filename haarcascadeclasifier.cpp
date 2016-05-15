#include "haarcascadeclasifier.hh"
#include <exception>
#include <iostream>

std::mutex HaarCascadeClasifier::mtx;

HaarCascadeClasifier::HaarCascadeClasifier(const std::string& file) :
		classifier(file)
{
}

std::thread HaarCascadeClasifier::threadClassifier(cv::Mat& img,
		const cv::Rect& cord, const int& index)
{
	return std::thread([=]()
	{	ClassifyPart(std::ref((cv::Mat&)img), cord, index);});
}

void HaarCascadeClasifier::ClassifyPart(cv::Mat& img, const cv::Rect& cord,
		const int& index)
{
	cv::Mat part = img(cord);
	mtx.lock();
	auto object = std::vector<cv::Rect>();
	mtx.unlock();
	classifier.detectMultiScale(part, object);
	cv::Scalar color = cv::Scalar(0, 0, 0);
	for (int i = 0; i < (int) object.size(); ++i)
	{
		std::ref(object.at(i).x) += cord.x;
		std::ref(object.at(i).y) += cord.y;
		mtx.lock();
		cv::rectangle(img, object.at(i), color, 3);
		mtx.unlock();
	}
}

void HaarCascadeClasifier::Classify(cv::Mat& img)
{
	cv::Rect rec[4] =
	{ cv::Rect(0, 0, 360, 310), cv::Rect(0, 260, 360, 315), cv::Rect(320, 260,
			399, 315), cv::Rect(320, 0, 399, 310) };
	try
	{
		std::vector<std::thread> t(4);
		for (int i = 0; i < 4; ++i)
		{
			t.at(i) = std::thread(threadClassifier(img, rec[i], i));
		}
		for (int i = 0; i < 4; ++i)
		{
			if (t.at(i).joinable())
				t.at(i).join();
		}
	} catch (std::out_of_range& e)
	{
		std::cerr <<"std::out_of_range exception caught: "<< e.what() << std::endl;
	} catch (std::exception& e)
	{
		std::cerr <<"std::exception exception caught: "<< e.what() << std::endl;
	}
}
