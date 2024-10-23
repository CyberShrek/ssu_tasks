#ifndef РЕКУРСИИ_H
#define РЕКУРСИИ_H
#include "AbstractSolution.h"

class Рекурсии : public AbstractSolution{
public:
    Рекурсии(): AbstractSolution(__FILE__){};
    void run() override;

    // Вычисляет факториал числа
    static int get_factorial(int number);
};

#endif //РЕКУРСИИ_H