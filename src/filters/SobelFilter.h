#ifndef DIP_HW05_SOBELFILTER_H
#define DIP_HW05_SOBELFILTER_H

#include "../common.h"
#include "GradientFilters.h"


class SobelFilter: public GradientFilters {
private:
protected:
    vector< vector<double> > calculateFx(Mat img) override;
    vector< vector<double> > calculateFy(Mat img) override;
public:
};

#endif //DIP_HW05_SOBELFILTER_H
