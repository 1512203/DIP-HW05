#ifndef DIP_HW05_SCHARRFILTER_H
#define DIP_HW05_SCHARRFILTER_H


#include "GradientFilters.h"

class ScharrFilter: public GradientFilters {
private:
protected:
    vector< vector<double> > calculateFx(Mat img) override;
    vector< vector<double> > calculateFy(Mat img) override;
public:
};


#endif //DIP_HW05_SCHARRFILTER_H
