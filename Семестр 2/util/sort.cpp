
template <typename T>
void quick_sort(vector<T>& vec, function<int(const T&)> get_comparable_value) {
    // Если размер вектора меньше или равен 1, то он уже отсортирован, поэтому функция просто возвращает управление.
    if (vec.size() <= 1) return;

    // Опорный элемент (pivot) - в данном случае средний элемент вектора.
    T pivot = vec[vec.size() / 2];

    // Разделение элементов вектора на три группы: меньше опорного, равные опорному и больше опорного.
    vector<T> left, middle, right;
    for (const auto& x : vec) {
        int a = get_comparable_value(x);
        int b = get_comparable_value(pivot);
        if (a < b) {
            left.push_back(x);
        } else if (a == b) {
            middle.push_back(x);
        } else {
            right.push_back(x);
        }
    }

    quick_sort(left, get_comparable_value);
    quick_sort(right, get_comparable_value);

    vec.clear();
    vec.insert(vec.end(), left.begin(), left.end());
    vec.insert(vec.end(), middle.begin(), middle.end());
    vec.insert(vec.end(), right.begin(), right.end());
}