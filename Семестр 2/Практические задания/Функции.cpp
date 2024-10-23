#include "Функции.h"

void Функции::run() {
    // Ввод количества знаков числа и вычисление суммы простых чисел
    int signs_size = await_int_input("Введите количество знаков числа");
    println("Сумма простых чисел для " + to_string(signs_size) + "-значного числа: "
        + to_string(sum_primes(signs_size)));
}

long Функции::sum_primes(int signs_size) {
    if(signs_size == 0) return 0;
    signs_size = abs(signs_size);

    // Определение границ диапазона
    const long min = stol(string("1").append(signs_size - 1, '0'));
    const long max = stol(string("9").append(signs_size - 1, '9'));

    // Поиск и суммирование простых чисел
    long sum = 0;
    for(long i = min; i <= max; i++)
        if(is_prime(i)) sum += i;

    return sum;
}

bool Функции::is_prime(const long number) {
    // Поиск делителя исключая 1 и самого себя
    for(long i = 2; i < number - 1; i++)
        if (number % i == 0)
            return false;

    return true;
}