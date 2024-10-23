#include "Сортировка1.h"

void Сортировка1::run() {
    // Создание файла со списком сотрудников
    if (await_enter_or_escape_input("Сгенерировать новый список сотрудников? (Enter - да, Space - нет)")) {
        generate_employees();
    }
    // Чтение списка сотрудников
    println("Список сотрудников:");
    println(read_file(FILE_PATH_INPUT));
    employees = parse_employees_from_file(FILE_PATH_INPUT);

    // Сортировка
    sort_by_salary(await_enter_or_escape_input("Сортировка по зарплате: Enter - по возрастанию, Space - по убыванию"));

    // Запись отсортированного списка сотрудников в новый файл и из этого файла
    write_employees_to_file(employees, FILE_PATH_OUTPUT);
    println("Сотрудники успешно отсортированы и записаны:");
    println(read_file(FILE_PATH_OUTPUT));
}

vector<Сортировка1::Employee> Сортировка1::parse_employees_from_file(const string &file_path) {
    vector<Employee> employees;

    // Чтение построчно
    bool ignore = true; // Игнорировать первую строку (заголовок)
    for (string line: split(read_file(file_path), '\n')) {
        if (ignore) {
            ignore = false;
            continue;
        }
        if (string trimmed_line = trim(line); !trimmed_line.empty())
            employees.push_back(parse(trimmed_line));
    }
    return employees;
}

void Сортировка1::write_employees_to_file(vector<Employee> employees, const string &file_path_to) {

    string content =
        pad("Фамилия", COLS_WIDTH[0], Align::CENTER) + "|"
        + pad("Должность", COLS_WIDTH[1], Align::CENTER) + "|"
        + pad("Дата рождения", COLS_WIDTH[2], Align::CENTER) + "|"
        + pad("Стаж работы", COLS_WIDTH[3], Align::CENTER) + "|"
        + pad("Зарплата", COLS_WIDTH[4], Align::CENTER) + "\n";

    // Запись построчно
    for (auto emp: employees) {
        content += stringify(emp);
    }
    rewrite_file(file_path_to, content);
}

void Сортировка1::sort_by_salary(bool ascending) {
    quick_sort(employees, function([ascending](const Employee &emp) {
        return ascending ? emp.salary : -1 * emp.salary;
    }));
}


string Сортировка1::stringify(Employee emp) {
    return
    pad(emp.surname, COLS_WIDTH[0]) + "|"
    + pad(emp.position, COLS_WIDTH[1]) + "|"
    + pad(emp.birthday, COLS_WIDTH[2], Align::CENTER) + "|"
    + pad(to_string(emp.experience), COLS_WIDTH[3], Align::RIGHT) + "|"
    + pad(to_string(emp.salary), COLS_WIDTH[4], Align::RIGHT) + "|"
    + "\n";
}

Сортировка1::Employee Сортировка1::parse(string line) {
    const vector<string> tokens = split(line, '|');
    return {
        trim(tokens[0]),
        trim(tokens[1]),
        trim(tokens[2]),
        stoi(trim(tokens[3])),
        stoi(trim(tokens[4])),
    };
}

void Сортировка1::generate_employees() {
    // Возможные фамилии сотрудников
    string surnames[] = {   "Аквариус", "Бионикс", "Галактион", "Дракон","Ехидна", "Жагуар", "Зуракс", "Иллюзис",
    "Каламарин", "Левитрон", "Ахлебар", "Бездарикс","Вздыбенкос", "Галактионис", "Дрыгасар", "Ерзебар",
    "Железовикс", "Завихренкос", "Иванюкар", "Каламбурин","Флумпикс", "Глупенкос", "Квазимодикс", "Псевдобурис",
    "Абракадабр", "Бурундук", "Вурдалак", "Гадюк","Дивногорск", "Ежевников", "Животов", "Зверобой",
    "Иллюминат", "Кабардин", "Лаванд", "Магнит","Нострадам", "Орфограф", "Пифагор", "Риторик",
    "Аквариусек", "Биониксен", "Галактионер", "Драконбург","Ехиднштейн", "Жагуаровский", "Зураксполь", "Иллюзисберг",
    "Каламаринек", "Левитронович", "Ахлебарчак", "Бездариксен","Вздыбенкоски", "Галактионисбург", "Дрыгасарек", "Ерзебарчак",
    "Железовиксен", "Завихренкосполь", "Иванюкарштейн", "Каламбуринек","Флумпиксен", "Глупенкоски", "Квазимодиксен", "Псевдобурисбург",
    "Абракадабрович", "Бурундукович", "Вурдалаковский", "Гадюкштейн","Дивногорсковский", "Ежевникович", "Животович", "Зверобоева",
    "Иллюминатовский", "Кабардиновский", "Лавандовский", "Магнитовский","Нострадамусовский", "Орфографовский", "Пифагорович", "Риториковский"};
    // Возможные должности
    const string positions[] = {"Тестировщик","Разработчик","Программист","Менеджер","Консультант","Хтонист",
        "Некромант","Демонолог","Чернокнижник","Харбингер","Кибердемон","Пинкидемон","Риппер",
        "Манкубус","Абаддон","Архонт","Культист","Хаосник","Бухгалтер", "Слесарь", "Журналист","Владыка"};

    vector<Employee> employees;

    for(string surname : surnames) {
        Employee employee;
        employee.surname = surname;
        employee.position = positions[rand() % positions->length()];
        employee.birthday = format_date(rand() % 31 + 1, rand() % 12 + 1, 2024 - rand() % 666);
        employee.experience = rand() % 666;
        employee.salary = rand() % 100500;
        employees.push_back(employee);
    }

    write_employees_to_file(employees, FILE_PATH_INPUT);
}

string Сортировка1::format_date(int day, int month, int year) {
    return (day > 9 ? "" : "0") + to_string(day) + "." + (month > 9 ? "" : "0") + to_string(month) + "." + to_string(year);
}