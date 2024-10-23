#include "Графы.h"

void Графы::run() {
    // Создание графа и списков смежности
    build_graph(await_ranged_int_input("Введите количество вершин графа", 0, 100));

    // Работа с графом
    print_adjacency_list();
    explore_vertices();
}

void Графы::build_graph(int size) {
    adjacency_list = vector<set<int>>(size);
    // Заполнение списка смежности
    for (int beg_i = 0; beg_i < size - 1; beg_i++) {
        for (int end_i = beg_i + 1; end_i < size; end_i++) {
            add_adjacency(beg_i, end_i);
        }
    }
}

void Графы::add_adjacency(const int &vertex_beg_i, const int &vertex_end_i) {
    if(await_enter_or_escape_input(
    "Смежны ли вершины " + to_string(vertex_beg_i + 1)+ " и " + to_string(vertex_end_i + 1)
    + "? (Enter - да, Space - нет)")) {
        adjacency_list[vertex_beg_i].insert(vertex_end_i+1);
        adjacency_list[vertex_end_i].insert(vertex_beg_i+1);
    }
}

void Графы::print_adjacency_list() const {
    println("Cписок смежности:");
    for (int i = 0; i < adjacency_list.size(); i++) {
        print(to_string(i + 1) + ": ");
        for (int j : adjacency_list[i]) {
            print(to_string(j) + " ");
        }
        println();
    }
}

void Графы::explore_vertices() const {
    const int vertex_num = await_ranged_int_input(
        "Введите номер вершины или 0 для выхода", 0, adjacency_list.size());

    if(vertex_num != 0) {
        println("Смежных вершин: "
            + to_string(get_number_of_adjacent_vertices(adjacency_list, vertex_num - 1)));
        explore_vertices();
    }
}

int Графы::get_number_of_adjacent_vertices(const vector<set<int> > &adjacency_list, int vertex_i) {
    return adjacency_list[vertex_i].size();
}
