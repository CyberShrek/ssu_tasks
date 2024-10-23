
void print(const string& message = "") {
    wcout << utf8(message);
}

void println(const string& message = "") {
    wcout << utf8(message) << endl;
}

void rewrite_file(const string& path, const string& content) {
    ofstream file (utf8(path).data());
    file << content;
    file.close();
}

// void remove_file(const string& path) {
//     remove(reinterpret_cast<const char *>(utf8(path).data()));
// }