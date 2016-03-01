#include "haarcascadeclasifier.hh"

HaarCascadeClasifier::HaarCascadeClasifier(const std::string& file):
	classifier(file)
{
}


void HaarCascadeClasifier::Classify(cv::Mat &img)
{
	std::vector<cv::Rect> objects;
	cv::Mat obj = cv::Mat::zeros(img.rows,img.cols,CV_8U);
	cv::cvtColor(img,obj,CV_BGR2GRAY);
	classifier.detectMultiScale(obj, objects);
	for(int i=0;i<objects.size();i++)
	{
		cv::rectangle(img,objects[i],colors[i%colors.size()],3);
	}
}
