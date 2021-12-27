#include <iostream>
#include <vector>

void printVector(const std::vector<int>& v) {
    for (auto e : v)
        std::cout << e << " ";
    std::cout << "\n";
}

std::vector<int> merge_sort(const std::vector<int>& v) {
    int length = v.size();
    if (length <= 1)
        return v;
    std::vector<int> first(v.begin(), v.end() - length/2);
    std::vector<int> second(v.end() - length/2, v.end());

    first = merge_sort(first);
    second = merge_sort(second);

    std::vector<int> final {};
    auto it1 = first.begin();
    auto it2 = second.begin();

    while (it1 != first.end() && it2 != second.end()) {
        if (*it1 < *it2)
            final.push_back(*(it1++));
        else
            final.push_back(*(it2++));
    }

    while (it1 != first.end())
        final.push_back(*(it1++));
    while (it2 != second.end())
        final.push_back(*(it2++));
    return final;
}

int main() {
    std::vector<int> v = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    std::cout << "Initial: ";
    printVector(v);
    v = merge_sort(v);
    std::cout << "Final  : ";
    printVector(v);
}
