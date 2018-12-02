#ifndef DIP_HW05_ROBERTSFILTER_H
#define DIP_HW05_ROBERTSFILTER_H

#include "../common.h"
#include "GradientFilters.h"


class RobertsFilter: public GradientFilters {
private:
protected:
    vector< vector<double> > calculateFx(Mat img) override;
    vector< vector<double> > calculateFy(Mat img) override;
public:
};


#endif //DIP_HW05_ROBERTSFILTER_H
