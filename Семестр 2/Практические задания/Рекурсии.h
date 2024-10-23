#ifndef РЕКУРСИИ_H
#define РЕКУРСИИ_H
#include "AbstractTask.h"

class Рекурсии : public AbstractTask{
public:
    Рекурсии(): AbstractTask(__FILE__){};
    void run() override;

    // Вычисляет факториал числа
    static int get_factorial(int number);
};

#endif //РЕКУРСИИ_H