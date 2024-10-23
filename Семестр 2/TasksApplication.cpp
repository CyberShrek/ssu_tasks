#pragma once
#include "Практические задания/AbstractTask.cpp"
#include "Практические задания/STL1.cpp"
#include "Практические задания/STL2.cpp"
#include "Практические задания/Графы.cpp"
#include "Практические задания/Деревья.cpp"
#include "Практические задания/Динамические_структуры.cpp"
#include "Практические задания/Рекурсии.cpp"
#include "Практические задания/Сортировка1.cpp"
#include "Практические задания/Сортировка2.cpp"
#include "Практические задания/Функции.cpp"

class TasksApplication
{
public:
    TasksApplication() {
        // Получение заданий
        acquire_tasks();
        println("Получен список заданий");
    };

    // Запуск программы
    void run() const {
        while (true)
            open_tasks_menu();
    };

    // Уничтожает объекты коллекции заданий
    ~TasksApplication() {
        for (AbstractTask* task : tasks) {
            delete task;
        }
    };

private:
    vector<AbstractTask*> tasks{};

    void acquire_tasks() {
        tasks.push_back(new STL1());
        tasks.push_back(new STL2());
        tasks.push_back(new Графы());
        tasks.push_back(new Деревья());
        tasks.push_back(new Динамические_структуры());
        tasks.push_back(new Рекурсии());
        tasks.push_back(new Сортировка1());
        tasks.push_back(new Сортировка2());
        tasks.push_back(new Функции());
    }

    void open_tasks_menu() const {
        println("Задания:");
        for (int i = 0; i < tasks.size(); i++) {
            println(to_string(i + 1) + ". " + tasks[i]->get_name());
        }
        open_task(tasks[
            await_ranged_int_input("Введите номер", 1, tasks.size()) - 1
            ]);
    }

    static void open_task(const AbstractTask* task) {
        println(task->to_text());
        while(await_enter_or_escape_input("Нажмите Enter для запуска программы, или Escape для возврата в меню")) {
            const_cast<AbstractTask *>(task)->run();
        }
    }
};
