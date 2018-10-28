#ifndef _IMAGE_PROCESS_FACTORY_INF_
#define _IMAGE_PROCESS_FACTORY_INF_

#include <iostream>
#include "OpenCvCoreInf.h"

class ImageProcessFactoryInf
{
public:
	virtual int createOpenCvCoreInterface(OpenCvCoreInf **inf) = 0;

	virtual ~ImageProcessFactoryInf();  //virtual derived calss can deleted
protected:
	ImageProcessFactoryInf(); // avoid interface instance
};

#endif  //!_IMAGE_PROCESS_FACTORY_INF_
