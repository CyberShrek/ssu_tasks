#include "AbstractSolution.h"

AbstractSolution::AbstractSolution(const string& _file_) {

    // Путь к файлу класса без расширения
    string non_ext_path = _file_.substr(0, _file_.find_last_of('.'));

    // Имя файла без расширения
    name           = non_ext_path.substr(non_ext_path.find_last_of('/') + 1);
    description    = read_file(non_ext_path + ".txt");
    header         = read_file(_file_);
    implementation = read_file(non_ext_path + ".cpp");
}

string AbstractSolution::get_name() const {
    return name;
}

string AbstractSolution::to_text() const {
    return "\tЗадание \"" + name + "\":\n"+ description
    + "\n\n\tРешение:\n\n"
    + "    ///////////\n"
    + "    // Класс // " + name + ".h:\n"
    + "    ///////////\n\n"
    + header + "\n\n"
    + "    ///////////////////\n"
    + "    // Имплементация // " + name + ".cpp:\n"
    + "    ///////////////////\n\n"
    + implementation;
}