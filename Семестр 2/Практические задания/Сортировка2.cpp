#include "Сортировка2.h"

void Сортировка2::run() {
    // Создание файла с матрицей
    if(await_enter_or_escape_input("Сгенерировать новую матрицу? (Enter - да, Space - нет)")) {
        generate_matrix(await_int_input("Введите размерность матрицы"));
    }
    matrix = parse_matrix_from_file(FILE_PATH_INPUT);
    println("Матрица " + to_string(matrix.size()) + "x" + to_string(matrix[0].size()) + ":");
    println(read_file(FILE_PATH_INPUT));

    // Сортировка
    transpose_matrix();
    sort_matrix(await_enter_or_escape_input("Сортировка: Enter - по возрастанию, Space - по убыванию"));
    transpose_matrix();

    // Запись отсортированной матрицы в новый файл
    write_matrix_to_file(matrix, FILE_PATH_OUTPUT);
    println("Матрица успешно отсортирована и записана:");
    println(read_file(FILE_PATH_OUTPUT));
}

void Сортировка2::generate_matrix(int size) {
    vector matrix(size, vector<int>(size));
    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            matrix[x][y] = 10 + rand() % 90;
        }
    }
    write_matrix_to_file(matrix, FILE_PATH_INPUT);
}

void Сортировка2::transpose_matrix() {
    int size = matrix.size();
    vector transposed_matrix(size, vector<int>(size));
    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            transposed_matrix[y][x] = matrix[x][y];
        }
    }
    matrix = transposed_matrix;
}

void Сортировка2::sort_matrix(bool ascending) {
    for (auto &row : matrix) {
        quick_sort(row, function([ascending](const int &value) {
            return ascending ? value : -1 * value;
        }));
    }
}

void Сортировка2::write_matrix_to_file(vector<vector<int> > matrix, const string &file_path) {
    string content;

    // Запись построчно
    for (auto &row : matrix) {
        for (auto &col : row) {
            content.append(to_string(col) + " ");
        }
        content.append("\n");
    }
    rewrite_file(file_path, content);
}

vector<vector<int> > Сортировка2::parse_matrix_from_file(const string &file_path) {
    auto matrix = vector<vector<int>>();

    // Чтение построчно
    for(auto &line : split(read_file(file_path), '\n')) {
        matrix.push_back(vector<int>());
        for (string &token : split(trim(line), ' ')) {
            if (!trim(token).empty()) {
                matrix.back().push_back(stoi(token));
            }
        }
    }
    return matrix;
}