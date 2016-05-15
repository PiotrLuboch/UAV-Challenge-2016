#include <iostream>
#include "videoreader.hh"
#include "haarcascadeclasifier.hh"
#include "imageprocessing.hh"
#include "settings.hh"
#include "exit_codes.hh"

using namespace std;

int main(int argc, char** argv)
{
	if (argc != 3)
		return ERROR_NOT_ENOUGH_PARAMETERS;

	string video_file_name = string(argv[1]);
	string classifier_file_name = string(argv[2]);
	VideoReader reader(video_file_name);
	HaarCascadeClasifier classifier(classifier_file_name);

	cv::Mat frame;
	int is_exit = 'n';

	if (reader.IsOpeened())
	{
		while (!(is_exit == 'q'))
		{
			reader.GetFrame(frame);
			if (!frame.empty())
			{
				ImageProcessing::ResizeImage(frame);
				ImageProcessing::ToGrayScale(frame);
				classifier.Classify(frame);
				cv::imshow("window", frame);
			}
			is_exit = cv::waitKey(40);
		}
		reader.Close();
		frame.release();
	}

	return EXIT_OK;
}

