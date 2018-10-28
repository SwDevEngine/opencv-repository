#ifndef _OPEN_CV_CORE_IMP_
#define _OPEN_CV_CORE_IMP_

#include <iostream>
#include <string>
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp> 
#include <opencv2/opencv.hpp>

#include "OpenCvCoreInf.h"

using namespace cv;

class OpenCvCoreImp : public OpenCvCoreInf
{
public:
	int setParams(OpenCvFeatureID, void *payload);

	OpenCvCoreImp();
	~OpenCvCoreImp();

private:
	
	int CvCheckFeatureID(OpenCvFeatureID feature);
	//cv ops
	int CvImageShow(const Mat &src, const char *type);
	int CvImageErode(const Mat &src, Mat *dest);
	int CvImageBlur(const Mat &src, Mat *dest);
	int CvImageEdge(const Mat &src, Mat *dest);
	int CvVideoRead(VideoCapture &src, Mat &output_frame);
};

#endif // !_OPEN_CV_CORE_IMP_

