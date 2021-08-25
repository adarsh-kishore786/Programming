#include <vector>
#include <iostream>

int main()
{
    std::vector<int> vect;
    for (int i = 0; i < 6; i++)
        vect.push_back(i);

    std::vector<int>::const_iterator it; // read-only iterator
    it = vect.cbegin();

    std::cout << "Vector: ";
    while (it != vect.cend())
    {
        std::cout << *it << " ";
        it++;
    }
    std::cout << "\n";
}
