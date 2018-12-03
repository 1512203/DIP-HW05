#ifndef DIP_HW05_GRADIENTFILTERS_H
#define DIP_HW05_GRADIENTFILTERS_H

#include "../common.h"
#include "BaseFilters.h"


class GradientFilters: public BaseFilters {
private:
protected:
    virtual vector< vector<double> > calculateFx(Mat img) = 0;
    virtual vector< vector<double> > calculateFy(Mat img) = 0;
public:
    Mat applyFilter(Mat img, argv_t kwargs) override;
};


#endif //DIP_HW05_GRADIENTFILTERS_H
