#ifndef DIP_HW05_MARRHILDRETHFILTERS_H
#define DIP_HW05_MARRHILDRETHFILTERS_H

#include "../common.h"
#include "BaseFilters.h"


class MarrHildrethFilters: public BaseFilters {
private:
protected:
    virtual vector<vector<double>> LaplacianOperator(Mat img, argv_t kwargs) = 0;
public:
    Mat applyFilter(Mat img, argv_t kwargs) override;
};

#endif //DIP_HW05_MARRHILDRETHFILTERS_H
