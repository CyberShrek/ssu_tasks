#ifndef ДЕРЕВЬЯ_H
#define ДЕРЕВЬЯ_H
#include <vector>

#include "AbstractTask.h"

class Деревья final : public AbstractTask
{
public:
    Деревья(): AbstractTask(__FILE__){}
    void run() override;

    // Узел дерева
    class Node
    {
    public:
        // Создаёт узел с заданным элементом
        explicit Node(int value);

        // Вставляет новый элемент в дерево
        void insert(int value);

        // Выводит дерево в консоль
        void print_tree(int level = 0) const;

        // Подсчитывает сумму листьев прямым обходом
        int get_leaves_sum() const;
        // Подсчитывает количество листьев (на тот случай, если под "суммой листьев" подразумевалось количество листьев)
        int get_leaves_count() const;

        ~Node();

    private:
        int value;

        // Дочерние узлы
        Node *l_child = nullptr;
        Node *r_child = nullptr;

    };
};

#endif //ДЕРЕВЬЯ_H