#include "STL1.h"

void STL1::run() {
    // Ввод последовательности целых чисел с клавиатуры
    vector <int> sequence = await_int_sequence_input();

    // Ввод интервала
    int a = await_int_input("Введите нижнюю границу интервала (a)");
    int b = await_int_input("Введите верхнюю границу интервала (b)");

    println("Сумма элементов, не попадающих в интервал ["
        + to_string(a) + ", " + to_string(b) + "]: "
        + to_string(sum_elements_not_in_interval(sequence, a, b)));
}

int STL1::sum_elements_not_in_interval(const vector<int> &sequence, const int a, const int b) {
    int sum = 0;
    for (const int number : sequence)
        if (number < a || number > b)
            sum += number;

    return sum;
}