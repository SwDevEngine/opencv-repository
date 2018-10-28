#include <opencv2/opencv.hpp> 
#include <iostream>
#include "ImageProcessFactoryImp.h"
#include "OpenCvCoreImp.h"

using namespace cv;
using namespace std;
int main(int argc, char** args) {
	ImageProcessFactoryInf *factor_intf = NULL;
	OpenCvCoreInf *core_intf = NULL;

	factor_intf = new ImageProcessFactoryImp;
	if (!factor_intf) {
		printf("Fail to create factor interface");
		return -1;
	}
	
	factor_intf->createOpenCvCoreInterface(&core_intf);
	if (!core_intf) {
		printf("Fail to create opencv core interface");
		return -1;
	}

	//Mat imge_path = imread("test1.jpg");
	const char *imge_path = "test4.jpg";
	core_intf->setParams(OPEN_CV_IMAGE_SHOW, const_cast<char *>(imge_path));
	core_intf->setParams(OPEN_CV_IMAGE_READ, const_cast<char *>(imge_path));
	//core_intf->setParams(OPEN_CV_IMAGE_, const_cast<char *>(imge_path));
	//Mat src = imread("test.jpg", IMREAD_REDUCED_COLOR_2);
	//namedWindow("output", CV_WINDOW_AUTOSIZE);
	//imshow("output", src);


	waitKey(0);
	delete core_intf;
	delete factor_intf; 
	return 0;
}

