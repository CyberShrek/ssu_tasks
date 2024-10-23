#include "Рекурсии.h"

void Рекурсии::run() {
    println(to_string(get_factorial(
            await_int_input("Введите натуральное число для вычисления факториала"))));
}

int Рекурсии::get_factorial(const int number) {
    return number == 0 ? 1 : number * get_factorial(number - 1);
}