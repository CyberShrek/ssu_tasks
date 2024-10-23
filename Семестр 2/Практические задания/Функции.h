#ifndef ФУНКЦИИ_H
#define ФУНКЦИИ_H
#include "AbstractSolution.h"

class Функции : public AbstractSolution{
public:
    Функции(): AbstractSolution(__FILE__){};
    void run() override;

    // Вычисляет сумму простых чисел для указанного количества знаков числа
    static long sum_primes(int signs_size);

private:
    // Определяет простое ли число
    static bool is_prime(long number);
};

#endif //ФУНКЦИИ_H