// Все библиотеки, используемые в проекте, подключены здесь
#include <locale>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <stack>
#include <conio.h>
#include <codecvt>
#include <functional>
#include "util/all.h"
#include "ConcoleApplication.cpp"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    ConcoleApplication().run();
    return 0;
}

