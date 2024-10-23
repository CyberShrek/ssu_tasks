#ifndef ДИНАМИЧЕСКИЕ_СТРУКТУРЫ_H
#define ДИНАМИЧЕСКИЕ_СТРУКТУРЫ_H
#include "AbstractSolution.h"

class Динамические_структуры final : public AbstractSolution
{
public:
    Динамические_структуры(): AbstractSolution(__FILE__){};
    void run() override;

    // Возвращает все слова, которые не заканчиваются на заданную букву, в заданном стеке
    static stack<string> get_words_not_end_with_letter(stack<string>& words, char letter);
};

#endif //ДИНАМИЧЕСКИЕ_СТРУКТУРЫ_H