#ifndef ABSTRACT_TASK_H
#define ABSTRACT_TASK_H

using namespace std;

// Абстрактный класс, позволяющий упростить работу с заданиями.
class AbstractTask
{
public:

    // Запускает реализованную по заданию программу
    virtual void run() = 0;

    // Возвращает имя задания
    virtual string get_name() const;

    // Возвращает описание и решение задания
    virtual string to_text() const;

    virtual ~AbstractTask() = default;

protected:

    // Требует макрос __FILE__ в аргументе для вычисления пути файла производного класса.
    explicit AbstractTask(const string& _file_);

private:
    // Название задания
    string name{};
    // Описание задания
    string description{};
    // Исходный код заголовка
    string header{};
    // Исходный код имплементации
    string implementation{};
};

#endif