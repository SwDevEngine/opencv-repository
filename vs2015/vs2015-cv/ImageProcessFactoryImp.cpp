#include <iostream>
#include "ImageProcessFactoryImp.h"

int ImageProcessFactoryImp::createOpenCvCoreInterface(OpenCvCoreInf **inf)
{
	int ret = 0;

	*inf = new OpenCvCoreImp();
	if (!(*inf)) {
		std::cout << "Failed to create OpenCvCoreImp" << std::endl;
		ret = -1;
	}
	return ret;
}

ImageProcessFactoryImp::ImageProcessFactoryImp()
{
}

ImageProcessFactoryImp::~ImageProcessFactoryImp()
{
}