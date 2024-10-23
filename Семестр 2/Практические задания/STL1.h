#ifndef STL1_H
#define STL1_H

#include "AbstractTask.h"

class STL1 final : public AbstractTask
{
public:
    STL1(): AbstractTask(__FILE__) {}
    void run() override;

    // Вычисляет сумму элементов, не попадающих в заданный интервал [a, b]
    static int sum_elements_not_in_interval(const vector<int>& sequence, int a, int b);
};

#endif //STL1_H
