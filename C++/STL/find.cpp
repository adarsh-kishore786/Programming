#include <algorithm>
#include <iostream>
#include <list>
#include <numeric> // std::iota

int main()
{
    std::list<int> li(6);
    std::iota(li.begin(), li.end(), 2);

    std::cout << "List: ";
    for (auto i : li)
        std::cout << i << " ";
    std::cout << "\n\n";

    std::cout << "Enter value to search in list: ";
    int value{};
    std::cin >> value;

    auto it { std::find(li.begin(), li.end(), value) };

    if (it == li.end())
    {
        std::cout << "Value doesn't exist in array.\n";
        return 1;
    }

    std::cout << "Value " << *it << " exists in list\n";

    std::cout << "Enter a value to insert before " << *it << ": ";
    std::cin >> value;

    li.insert(it, value);

    std::cout << "\nNew list: ";
    for (auto i : li)
        std::cout << i << " ";
    std::cout << "\n";

    return 0;
}
