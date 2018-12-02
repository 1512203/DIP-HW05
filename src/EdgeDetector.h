#ifndef DIP_HW05_EDGEDETECTOR_H
#define DIP_HW05_EDGEDETECTOR_H

#include "BaseProcessor.h"


class EdgeDetector: public BaseProcessor {
private:
protected:
    Mat processImage(argv_t kwargs) override;
public:
    explicit EdgeDetector(string pathToImage);
    ~EdgeDetector() override = default;
};


#endif //DIP_HW05_EDGEDETECTOR_H
