#ifndef DIP_HW05_LAPLACEFILTER_H
#define DIP_HW05_LAPLACEFILTER_H

#include "../common.h"
#include "MarrHildrethFilters.h"


class LaplaceFilter: public MarrHildrethFilters {
private:
protected:
    vector<vector<double>> LaplacianOperator(Mat img, argv_t kwargs) override;
public:
};

#endif //DIP_HW05_LAPLACEFILTER_H
