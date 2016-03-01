#include <iostream>
#include "videoreader.hh"
#include "haarcascadeclasifier.hh"

using namespace std;

int main()
{
	VideoReader reader("/home/piotr/Wideo/GOPR0100.MP4");
	HaarCascadeClasifier classifier("/home/piotr/Dokumenty/gopro100.xml");
	cv::Mat frame;
	int is_exit = 'n';
	if(reader.IsOpeened())
	{
		while(reader.GetFrame(frame) && !(is_exit=='q'))
		{
			classifier.Classify(frame);
			cv::imshow("frame",frame);
			is_exit = cv::waitKey(40);

		}
		reader.Close();
	}
}

