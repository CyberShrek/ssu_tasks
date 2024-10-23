#ifndef ГРАФЫ_H
#define ГРАФЫ_H

#include "AbstractTask.h"

class Графы final : public AbstractTask
{
public:
    Графы(): AbstractTask(__FILE__) {}
    void run() override;

    // Возвращает количество вершин, смежных с указанной вершиной, у неориентированного графа
    static int get_number_of_adjacent_vertices(const vector<set<int>>& adjacency_list, int vertex_i);

private:

    // Список смежности графа
    vector<set<int>> adjacency_list;

    // Строит граф с указанным числом вершин и смежностями
    void build_graph(int size);

    // Добавляет смежность между двумя вершинами
    void add_adjacency(const int& vertex_beg_i, const int& vertex_end_i);

    // Выводит список смежности
    void print_adjacency_list() const;

    // Выводит количество смежных вершин для любой выбранной вершины
    void explore_vertices() const;
};

#endif //ГРАФЫ_H
