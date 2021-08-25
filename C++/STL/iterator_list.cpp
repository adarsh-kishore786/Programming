#include <iostream>
#include <list>

int main()
{
    std::list<int> li;
    for (int i = 0; i < 6; i++)
        li.push_back(i);

    std::list<int>::const_iterator it; // read-only iterator
    it = li.cbegin();

    std::cout << "List: ";
    while (it != li.cend())
    {
        std::cout << *it << " ";
        it++;
    }
    std::cout << "\n";
}
