#include <iostream>  
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp> 
#include <opencv2/opencv.hpp>
using namespace cv;

class openCvOps {
public:
	int imageShow(const Mat &src);
	int getImageRectangle(const uint32_t width, const uint32_t high);
	int setImageErode(const Mat &src);
	int setImageBlur(const Mat &src);

	openCvOps(){ };
	~openCvOps() { };
};