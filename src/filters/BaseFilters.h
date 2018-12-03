#ifndef DIP_HW05_BASEFILTERS_H
#define DIP_HW05_BASEFILTERS_H

#include "../common.h"


class BaseFilters {
private:
protected:
public:
    virtual Mat applyFilter(Mat img, argv_t kwargs) = 0;
};

#endif //DIP_HW05_BASEFILTERS_H
