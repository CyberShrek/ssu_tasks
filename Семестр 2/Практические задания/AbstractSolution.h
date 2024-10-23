#ifndef ABSTRACT_SOLUTION_H
#define ABSTRACT_SOLUTION_H

using namespace std;

// Абстрактный класс, позволяющий упростить работу с моими решениями.
class AbstractSolution
{
public:

    // Запускает реализованную по заданию программу
    virtual void run() = 0;

    // Возвращает название
    virtual string get_name() const;

    // Возвращает описание и решение задания
    virtual string to_text() const;

    virtual ~AbstractSolution() = default;

protected:

    // Требует макрос __FILE__ в аргументе для вычисления пути файла производного класса.
    explicit AbstractSolution(const string& _file_);

private:
    // Название
    string name{};
    // Описание
    string description{};
    // Исходный код заголовка
    string header{};
    // Исходный код имплементации
    string implementation{};
};

#endif