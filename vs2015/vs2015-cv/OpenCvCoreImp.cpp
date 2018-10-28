#include <iostream>
#include <stdio.h>  
#include <memory>
#include "OpenCvCoreImp.h"


using namespace cv;
	
OpenCvCoreImp::OpenCvCoreImp() {
}

OpenCvCoreImp::~OpenCvCoreImp() {
}

int OpenCvCoreImp::setParams(OpenCvFeatureID feature, void *payload) {
	Mat destImage, grayImage, edge, output_frame;
	Mat *pSrcImage = NULL;
	char *img_name;
	VideoCapture *pSrcVideo = NULL;

	if (!payload) {
		printf("%s, Invalid payload", __FUNCTION__);
	}
	img_name = (char *)payload;

	if(CvCheckFeatureID(feature)) {
		printf("%s, Invalid payload", __FUNCTION__);
		return -1;
	}
	
	switch (feature) {
		case OPEN_CV_IMAGE_READ:
			{
				// read image base some format
				//Mat img_gray_scale_1_2 = imread(img_name, IMREAD_REDUCED_GRAYSCALE_2);
			 //	CvImageShow(img_gray_scale_1_2, "IMREAD_REDUCED_GRAYSCALE_2");
				Mat img_color_1_2 = imread(img_name, IMREAD_REDUCED_COLOR_2);
				CvImageShow(img_color_1_2, "IMREAD_REDUCED_COLOR_2");
				
				//save image
				imwrite("store.png", img_color_1_2);

				//conversion image color space
				Mat des; 
				cvtColor(img_color_1_2, des, COLOR_BGRA2RGBA);
				CvImageShow(des, "COLOR_BGRA2RGBA");
			}
		break;
		case OPEN_CV_IMAGE_SHOW:
			{
				Mat src = imread(img_name);
				CvImageShow(src, "OPEN_CV_IMAGE_SHOW");
			}
			break;
		case OPEN_CV_IMAGE_ERODE:
			pSrcImage = (Mat *)payload;
			CvImageShow(*pSrcImage, "src_image");
			CvImageErode(*pSrcImage, &destImage);
			CvImageShow(destImage, "OPEN_CV_IMAGE_ERODE");
			break;
		case OPEN_CV_IMAGE_BLUR:
			pSrcImage = (Mat *)payload;
			CvImageShow(*pSrcImage, "src_image");
			CvImageBlur(*pSrcImage, &destImage);
			CvImageShow(destImage, "OPEN_CV_IMAGE_BLUR");
			break;
		case OPEN_CV_IMAGE_EDGE:
			pSrcImage = (Mat *)payload;
			CvImageShow(*pSrcImage, "src_image");
			CvImageEdge(*pSrcImage, &destImage);
			break;
		case OPEN_CV_VIDEO_READ:
			pSrcVideo = (VideoCapture *)payload;
			CvVideoRead(*pSrcVideo, output_frame);
			CvImageShow(output_frame, "OPEN_CV_VIDEO_READ");
			printf("%s: Line %d:\n", __FUNCTION__, __LINE__);
			waitKey(1000);
			break;
		default:
			printf("Invalid open cv feature id %d\n", feature);
	}
	return 0;
}

int OpenCvCoreImp::CvCheckFeatureID(OpenCvFeatureID feature){
	std::string name;

	switch (feature) {
	case OPEN_CV_IMAGE_READ:
		name = "OPEN_CV_IMAGE_READ";
		break;
	case OPEN_CV_IMAGE_SHOW:
		name = "OPEN_CV_SHOW_IMAGE";
		break;
	case OPEN_CV_IMAGE_ERODE:
		name = "OPEN_CV_IMAGE_ERODE";
		break;
	case OPEN_CV_IMAGE_BLUR:
		name = "OPEN_CV_IMAGE_BLUR";
		break;
	case OPEN_CV_IMAGE_EDGE:
		name = "OPEN_CV_IMAGE_EDGE";
		break;
	case OPEN_CV_VIDEO_READ:
		name = "OPEN_CV_VIDEO_READ";
		break;
	default:
		printf("%s: Invalid feature id %d\n", __FUNCTION__, feature);
		return -1;
	}

	printf("%s: Parse feature id success, id is %d, name is %s\n", __FUNCTION__, feature, name.c_str());
	return 0;
}

int OpenCvCoreImp::CvImageShow(const Mat &src, const char *name) {
	imshow(name, src);
	//namedWindow();
	return 0;
}

int OpenCvCoreImp::CvImageErode(const Mat &src, Mat *dest) {
	Mat rect_image = getStructuringElement(MORPH_RECT, Size(15, 15));
	erode(src, *dest, rect_image);
	return 0;
}

int OpenCvCoreImp::CvImageBlur(const Mat &src, Mat *dest) {
	blur(src, *dest, Size(7, 7));
	return 0;
}

int OpenCvCoreImp::CvImageEdge(const Mat &src, Mat *dest) {
	Mat edge;
	cvtColor(src, *dest, COLOR_BGR2GRAY);
	imshow("cvtColor", *dest);  // debug
	blur(src, edge, Size(3, 3));
	imshow("blur", edge);  // debug
	Canny(edge, *dest, 3, 9);
	imshow("Canny", *dest);
	return 0;
}

int OpenCvCoreImp::CvVideoRead(VideoCapture &src, Mat &output_frame) {
	Mat rrr;
	src>>output_frame;
	return 0;
}