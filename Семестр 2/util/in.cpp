
string read_file(const string& path) {
    ifstream file (utf8(path).data());
    if (!file) {
        return  "n/a";
    }
    string content;
    string line;
    while (getline(file, line)) {
        content += line + "\n";
    }
    file.close();
    return content;
}

string await_string_input(const string& title = "Введите строку:\n") {
    println(title + ":");
    string line;
    cin >> line;
    return line;
}

int await_int_input(const string& title = "Введите целое число:\n") {
    const string line = await_string_input(title);
    if (!is_int(line)) {
        print("Допустимы только целые числа. ");
        return await_int_input(title);
    }
    return stoi(line);
}

int await_ranged_int_input(const string& title, const int min, const int max) {
    const int value = await_int_input(title);
    if (value < min || value > max) {
        print("Допустимы значения от " + to_string(min) + " до " + to_string(max) + ". ");
        return await_ranged_int_input(title, min, max);
    }
    return value;
}

vector<int> await_int_sequence_input(const string& title = "Введите последовательность целых чисел через запятую") {
    const string line = await_string_input(title);
    vector<int> ints;
    for (string token : split(line, ',')) {
        token = trim(token);
        if (is_int(token)) {
            ints.push_back(stoi(token));
        } else {
            print("Допустимы только целые числа. ");
            return await_int_sequence_input(title);
        }
    }
    return ints;
}

vector<int> await_ranged_int_sequence_input(const string& title, const int min, const int max) {
    const vector<int> ints = await_int_sequence_input(title);
    for (const int value : ints) {
        if (value < min || value > max) {
            print("Допустимы значения от " + to_string(min) + " до " + to_string(max) + ". ");
            return await_ranged_int_sequence_input(title, min, max);
        }
    }
    return ints;
}

vector<string> await_string_sequence_input(const string& title = "Введите последовательность строк через запятую") {
    const string line = await_string_input(title);
    return split(line, ',');
}

bool await_enter_or_escape_input(const string& title) {
    println(title);
    while (true) {
        int c = getch();
        if (c == 13) return true;
        if (c == 27) return false;
        // Завершение по пробелу для случаев, когда getch не возвращает нажатую клавишу без ввода Enter (как у меня в Clion)
        if (c == 32) return false;
    }
}