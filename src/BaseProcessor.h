#ifndef DIP_HW05_BASEPROCESSOR_H
#define DIP_HW05_BASEPROCESSOR_H

#include "common.h"


class BaseProcessor {
private:
protected:
    Mat image;
    virtual Mat processImage(argv_t kwargs) = 0;
public:
    explicit BaseProcessor(string pathToImage);
    void execute(argv_t kwargs);
    virtual ~BaseProcessor() = default;
};

#endif //DIP_HW05_BASEPROCESSOR_H
