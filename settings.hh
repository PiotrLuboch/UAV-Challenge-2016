#ifndef SETTINGS_HH
#define SETTINGS_HH

#include "opencv2/core/core.hpp"

class Settings{
public:
	Settings() = delete;
	Settings(const Settings&) = delete;
	Settings(Settings&&) = delete;
	Settings operator=(const Settings&) = delete;
	static cv::Size original_size;
	static cv::Size new_size;
};

#endif // SETTINGS_HH
