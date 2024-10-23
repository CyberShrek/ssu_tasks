#include "Деревья.h"

#include "../util/all.h"

void Деревья::run() {
    // Ввод последовательности целых чисел с клавиатуры
    vector<int> sequence = await_int_sequence_input("Введите узлы дерева через запятую");

    // Создание дерева
    Node tree = Node(sequence.front());
    for (int number : sequence)
        tree.insert(number);

    println("Создано дерево:");
    tree.print_tree();

    println("Сумма листьев:      " + to_string(tree.get_leaves_sum()));
    println("Количество листьев: " + to_string(tree.get_leaves_count()));
}

Деревья::Node::Node(const int value) {
    this->value = value;
}

void Деревья::Node::insert(int value) {
    // Вставка в левое поддерево
    if (value < this->value) {
        if (l_child == nullptr)
            l_child = new Node(value);
        else
            l_child->insert(value);
    }
    // Вставка в правое поддерево
    else if(value > this->value) {
        if (r_child == nullptr)
            r_child = new Node(value);
        else
            r_child->insert(value);
    }
    // Пропуск, если это значение уже присутствует в дереве
}


void Деревья::Node::print_tree(const int level) const {

    // Проверка наличия дочерних узлов
    bool has_left = l_child != nullptr;
    bool has_right = r_child != nullptr;

    // Установка отступа
    string indent = "";
    for (int i = 0; i < level; i++) {
        indent += "  ";
    }

    println(to_string(value) + (has_left || has_right ? " = {" : ""));
    if (has_left) {
        print(indent + "  L: ");
        l_child->print_tree(level + 1);
    }
    if (has_right) {
        print(indent + "  R: ");
        r_child->print_tree(level + 1);
    }
    if(has_left || has_right)
        println(indent + "}");
}

int Деревья::Node::get_leaves_count() const {
    if(l_child == nullptr && r_child == nullptr)
        return 1;

    int count = 0;
    // Прямой левый обход
    if (l_child != nullptr) count += l_child->get_leaves_count();
    if (r_child != nullptr) count += r_child->get_leaves_count();

    return count;
}

int Деревья::Node::get_leaves_sum() const {
    if(l_child == nullptr && r_child == nullptr)
        return value;

    int sum = 0;
    // Прямой левый обход
    if (l_child != nullptr) sum += l_child->get_leaves_sum();
    if (r_child != nullptr) sum += r_child->get_leaves_sum();

    return sum;
}

Деревья::Node::~Node() {
    delete l_child;
    delete r_child;
}