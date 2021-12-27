#include <iostream>
#include <vector>

std::vector<int> quick_sort(const std::vector<int>& arr) {
    int length = arr.size();
    if (length <= 1)
        return arr;

    int pivot = arr[length / 2];

    std::vector<int> small {};
    std::vector<int> large {};
    for (auto e : arr) {
        if (e < pivot)
            small.push_back(e);
        else if (e > pivot)
            large.push_back(e);
    }
    std::vector<int> sortedSmall = quick_sort(small);
    std::vector<int> sortedBig = quick_sort(large);
    sortedSmall.push_back(pivot);
    sortedSmall.insert(sortedSmall.end(), sortedBig.begin(), sortedBig.end());
    return sortedSmall;
}

void printVector(const std::vector<int>& v) {
    for (auto e : v)
        std::cout << e << " ";
    std::cout << "\n";
}

int main() {
    std::vector<int> v = {5, 4, 3, 2, 1};
    std::cout << "Initial: ";
    printVector(v);
    v = quick_sort(v);
    std::cout << "Final  : ";
    printVector(v);
}
