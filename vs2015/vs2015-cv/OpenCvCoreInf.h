#ifndef _OPEN_CV_CORE_INF_
#define _OPEN_CV_CORE_INF_

enum OpenCvFeatureID {
	OPEN_CV_IMAGE_READ,
	OPEN_CV_IMAGE_SHOW,
	OPEN_CV_IMAGE_ERODE,
	OPEN_CV_IMAGE_BLUR,
	OPEN_CV_IMAGE_EDGE,
	OPEN_CV_VIDEO_READ,
	
	OPEN_CV_FEATURE_MAX,
};

class OpenCvCoreInf
{
public:
	virtual ~OpenCvCoreInf();
	virtual int setParams(OpenCvFeatureID, void *payload) = 0;

protected:
	OpenCvCoreInf();
};

#endif  //!_OPEN_CV_CORE_INF_

