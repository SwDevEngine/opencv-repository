#include "openCvOps.h"

int openCvOps::imageShow(const Mat &src) {

	std::cout << "CV ops: image show" << std::endl;
	imshow("imageShow", src);
	waitKey(5000);
	return 0;
}

int openCvOps::setImageErode(const Mat &src) {
	Mat rect = getStructuringElement(MORPH_RECT, Size(20, 20));
	imageShow(rect);
	Mat destImage;
	erode(src, destImage, rect);
	imageShow(destImage);
	return 0;
}

/*
int openCvOps::setImageBlur(const Mat &src) {
	
}
*/
