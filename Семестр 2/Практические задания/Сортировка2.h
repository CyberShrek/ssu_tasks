#ifndef СОРТИРОВКА2_H
#define СОРТИРОВКА2_H
#include "AbstractSolution.h"

class Сортировка2 : public AbstractSolution
{
public:
    Сортировка2(): AbstractSolution(__FILE__){};
    void run() override;

    // Генерирует матрицу размером n x n в файл
    static void generate_matrix(int size);

private:
    static constexpr char* FILE_PATH_INPUT = "Семестр 2/Практические задания/Сортировка2.input.txt";
    static constexpr char* FILE_PATH_OUTPUT = "Семестр 2/Практические задания/Сортировка2.output.txt";

    // Двумерный массив (матрица)
    vector<vector<int>> matrix;

    // Транспонирует матрицу
    void transpose_matrix();

    // Сортирует элементы матрицы в каждой строке быстрой сортировкой
    void sort_matrix(bool ascending = true);

    // Для работы с файлами
    static void write_matrix_to_file(vector<vector<int>> matrix, const string &file_path);
    static vector<vector<int>> parse_matrix_from_file(const string &file_path);
};

#endif //СОРТИРОВКА2_H
