#include "haarcascadeclasifier.hh"

HaarCascadeClasifier::HaarCascadeClasifier(const std::string& file):
	classifier(file)
{
}


void HaarCascadeClasifier::Classify(cv::Mat &img)
{
	std::vector<cv::Rect> objects;
	classifier.detectMultiScale(img, objects);
	for(int i=0;i<objects.size();i++)
	{
		cv::rectangle(img,objects[i],colors[i%colors.size()],3);
	}
}
