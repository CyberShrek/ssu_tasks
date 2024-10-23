#ifndef STL2_H
#define STL2_H

#include "AbstractSolution.h"

class STL2 final : public AbstractSolution
{
public:
    STL2(): AbstractSolution(__FILE__) {}
    void run() override;

    // Возвращает множество цифр, которые встречаются только в двузначных числах
    static set<int> get_digits_of_two_digit_numbers(const vector<int>& sequence);
};

#endif //STL2_H
