#include "STL2.h"

void STL2::run() {
    // Ввод последовательности целых чисел с клавиатуры
    vector<int> sequence = await_int_sequence_input();

    print("Цифры, встречающихся только в двузначных числах: ");
    for (const int digit : get_digits_of_two_digit_numbers(sequence)) {
        print(to_string(digit) + " ");
    }
    println();
}

set<int> STL2::get_digits_of_two_digit_numbers(const vector<int>& sequence) {
    // Контейнер для цифр, которые встречаются только в двузначных числах
    set<int> digits;

    // Поиск двухзначных чисел и добавление их цифр в множество
    for (const int number : sequence) {
        if (string stringed_number = to_string(abs(number)); stringed_number.length() == 2) {
            digits.insert(stringed_number[0] - '0');
            digits.insert(stringed_number[1] - '0');
        }
    }
    return digits;
}