#include <algorithm>
#include <iostream>
#include <list>
#include <numeric> // std::iota

int main()
{
    std::list<int> li(6);

    // Fill li with numbers starting at 0 and increasing
    std::iota(li.begin(), li.end(), 0);

    std::cout << "List: ";
    for (auto i : li)
        std::cout << i << " ";
    std::cout << "\n\n";

    std::cout << "Min: " << *std::min_element(li.begin(), li.end()) << "\nMax: "
            << *std::max_element(li.begin(), li.end()) << "\n";

    return 0;
}
