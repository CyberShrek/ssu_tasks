using namespace std;

enum class Align { LEFT, RIGHT, CENTER };

wstring utf8(const string& text) {
    wstring_convert<codecvt_utf8<wchar_t>> converter;
    return converter.from_bytes(text);
}

vector<string> split(const string& str, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream token_stream(str);
    while (getline(token_stream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

string trim(const string& str) {
    const string whitespace = " \t\n";
    const size_t first = str.find_first_not_of(whitespace);
    if (string::npos == first)
        return str;
    const size_t last = str.find_last_not_of(whitespace);
    return str.substr(first, (last - first + 1));
}

string pad(const string& str, const size_t desired_size, const Align align = Align::LEFT) {
    const size_t padding = desired_size - str.length();
    if (padding <= 0) return str;

    string result = str;
    if (align == Align::RIGHT) result = string(padding, ' ') + result;
    else if (align == Align::CENTER) {
        const size_t leftPadding = padding / 2;
        result = string(leftPadding, ' ') + result + string(padding - leftPadding, ' ');
    }

    // Добавляем пробелы для компенсации длины не-ASCII символов
    for (size_t i = 0; i < str.length(); ++i) {
        if ((str[i] & 0xC0) == 0xC0) result += ' ';
    }

    if (align == Align::LEFT) result += string(padding, ' ');
    return result;
}

bool is_int(const string& str) {
    if (str.empty()) return false;
    char* end;
    strtol(str.c_str(), &end, 10);
    return *end == '\0';
}