#include <iostream>
#include <vector>

void insertion_sort(std::vector<int>& v) {
    for (int currLength = 1; currLength <= v.size(); currLength++) {
        int element = v[currLength - 1];
        int pos = currLength - 1;
        for (int j = 0; j < currLength - 1; j++) {
            if (v[j] > element) {
                pos = j;
                break;
            }
        }
        for (int j = currLength - 1; j > pos; j--)
            v[j] = v[j - 1];
        v[pos] = element;
    }
}

void printVector(const std::vector<int>& v) {
    for (auto e : v)
        std::cout << e << " ";
    std::cout << "\n";
}

int main() {
    std::vector<int> v = {5, 4223, 3245, 2, 1};
    std::cout << "Initial: ";
    printVector(v);
    insertion_sort(v);
    std::cout << "Final  : ";
    printVector(v);
}
