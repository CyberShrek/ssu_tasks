#ifndef СОРТИРОВКА1_H
#define СОРТИРОВКА1_H
#include "AbstractTask.h"

class Сортировка1 final : public AbstractTask{
public:
    Сортировка1(): AbstractTask(__FILE__) {};
    void run() override;

    // Описание сотрудника
    struct Employee{
        string surname;
        string position;
        string birthday;
        int experience;
        int salary;
    };

    // Генерирует рандомный набор сотрудников в файл
    static void generate_employees();

private:
    // Ширина колонок в таблице сотрудников
    static constexpr int COLS_WIDTH[] = {35, 30, 30, 25, 20};
    static constexpr char* FILE_PATH_INPUT = "Семестр 2/Практические задания/Сортировка1.input.txt";
    static constexpr char* FILE_PATH_OUTPUT = "Семестр 2/Практические задания/Сортировка1.output.txt";

    // Список сотрудников
    vector<Employee> employees;

    // Строковое представление сотрудника
    static string stringify(Employee emp);
    // Парсит сотрудника из строки
    static Employee parse(string line);

    // Функции для работы с файлами
    static vector<Employee> parse_employees_from_file(const string &file_path);
    static void write_employees_to_file(vector<Employee> employees, const string &file_path);

    // Сортирует сотрудников по зарплате
    void sort_by_salary(bool ascending = true);

    // Форматирует числа в строку-дату
    static string format_date(int day, int month, int year);
};

#endif //СОРТИРОВКА1_H