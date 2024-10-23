#include "Динамические_структуры.h"

void Динамические_структуры::run() {
    // Ввод слов с клавиатуры
    vector<string> sequence = await_string_sequence_input();

    // Наполнение стека
    stack<string> words;
    for (string word : sequence)
        words.push(word);

    // Получение слов, которые не заканчиваются на заданную букву
    stack<string> result = get_words_not_end_with_letter(words,
        await_string_input("Введите букву, на которую не должны заканчиваться слова: ").at(0));

    // Вывод результата
    while (!result.empty()) {
        println(result.top() + " ");
        result.pop();
    }
}

stack<string> Динамические_структуры::get_words_not_end_with_letter(stack<string> &words, char letter) {
    stack<string> result;

    // Запись слов, которые не заканчиваются на заданную букву
    while (!words.empty()) {
        string word = words.top();
        words.pop();
        if (word[word.size() - 1] != letter) {
            result.push(word);
        }
    }
    return result;
}