#ifndef DIP_HW05_LOGFILTER_H
#define DIP_HW05_LOGFILTER_H

#include "MarrHildrethFilters.h"


class LoGFilter: public MarrHildrethFilters {
private:
protected:
    vector<vector<double>> LaplacianOperator(Mat img, argv_t kwargs) override;
public:
};

#endif //DIP_HW05_LOGFILTER_H
