#include <iostream>
#include "videoreader.hh"
#include "haarcascadeclasifier.hh"
#include "imageprocessing.hh"
#include "settings.hh"

using namespace std;

int main()
{
	VideoReader reader("/home/piotr/Programy/UAV_Challenge/video/GOPR1802.MP4");

	HaarCascadeClasifier classifier("/home/piotr/Programy/UAV_Challenge/data/cascade.xml");
	//VideoReader reader("/home/piotr/Wideo/GOPR0100.MP4");
	//HaarCascadeClasifier classifier("/home/piotr/Dokumenty/gopro100.xml");
	cv::Mat frame;
	int is_exit = 'n';
	if(reader.IsOpeened())
	{
		while(!(is_exit=='q'))
		{
			reader.GetFrame(frame);
			if(!frame.empty())
			{
				ImageProcessing::ToGrayScale(frame);
				ImageProcessing::ResizeImage(frame);
				classifier.Classify(frame);
				cv::imshow("frame",frame);
			}
			is_exit = cv::waitKey(40);
		}
		reader.Close();
		frame.release();
	}
}

