#ifndef UTIL_H
#define UTIL_H

#include "string.cpp"
#include "out.cpp"
#include "in.cpp"
#include "sort.cpp"

using namespace std;

    ///////////////////////
    // Функции из in.cpp // для работы с вводом
    ///////////////////////

// Возвращает содержимое файла по указанному пути
string read_file(const string& path);

// Ввод числа с клавиатуры
// title - заголовок ввода
int await_int_input(const string& prompt);

// Ввод последовательности целых чисел с клавиатуры через запятую
// title - заголовок ввода
int await_ranged_int_input(const string& title, const int min, const int max);

// Ввод последовательности целых чисел с клавиатуры через запятую
// title - заголовок ввода
vector<int> await_int_sequence_input(const string& title);

// Ввод последовательности целых чисел с клавиатуры через запятую в заданном диапазоне
// title - заголовок ввода
// min, max - диапазон ввода
vector<int> await_ranged_int_sequence_input(const string& title, const int min, const int max);

// Ввод последовательности строк с клавиатуры через запятую
// title - заголовок ввода
vector<string> await_string_sequence_input(const string& title);

// Ввод строки с клавиатуры
// title - заголовок ввода
string await_string_input(const string& prompt);

// Возвращает true, если пользователь нажал Enter, или false если нажал Escape (или пробел)
// title - заголовок ввода
bool await_enter_or_escape_input(const string& title);


    ////////////////////////
    // Функции из out.cpp // для работы с выводом
    ////////////////////////

// Преобразует строку в UTF-8 и выводит её в поток вывода
void println(const string& message);

// Преобразует строку в UTF-8 и выводит её в поток вывода с переносом строки
void print(const string& message);

// Перезаписывает содержимое в указанный файл
void rewrite_file(const string& path, const string& content);

// // Удаляет файл
// void remove_file(const string& path);


    /////////////////////////
    // Функции из sort.cpp // для работы с сортировкой
    /////////////////////////

// Сортирует вектор быстрой сортировкой по компаратору
template <typename T>
void quick_sort(vector<T>& vec, function<int(const T&)> get_comparable_value);


    ///////////////////////////
    // Функции из string.cpp // для работы со строками
    ///////////////////////////

// Переводит строку в UTF-8
wstring utf8(const string& text);

// Разделяет строку по указанному разделителю
vector<string> split(const string& str, char delimiter);

// Удаляет пробелы в начале и конце строки
string trim(const string& str);

/**
 * Заполняет строку до нужной длины пробелами.
 *
 * @param str исходная строка
 * @param desired_size желаемая длина строки
 * @param align выравнивание (по умолчанию Align::LEFT)
 * @return строка с добавленными пробелами
 */
string pad(const string& str, size_t desired_size, Align align);

// Проверяет, является ли строка целым числом
bool is_int(const string& str);

#endif
