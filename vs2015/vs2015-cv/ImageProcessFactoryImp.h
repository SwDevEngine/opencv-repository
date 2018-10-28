#ifndef _IMAGE_PROCESS_FACTORY_IMP_
#define _IMAGE_PROCESS_FACTORY_IMP_

#include <iostream>
#include "ImageProcessFactoryInf.h"
#include "OpenCvCoreImp.h"

class ImageProcessFactoryImp : public ImageProcessFactoryInf
{ 
public:
	int createOpenCvCoreInterface(OpenCvCoreInf **inf);

	ImageProcessFactoryImp();
	~ImageProcessFactoryImp();
};

#endif //!_IMAGE_PROCESS_FACTORY_IMP_