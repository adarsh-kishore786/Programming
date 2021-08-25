// Sequence containers are a part of STL which maintain
// the ordering of elements in the container. One of their
// defining features is that we can insert elements by
// position.
// Sequence containers in STL: std::vector, std::array,
// std::deque, std::list, std::forward_list, std::basic_string

#include <vector>
#include <deque>
#include <iostream>

int main()
{
    std::vector<int> vect;
    for (int i = 0; i < 6; i++)
        vect.push_back(10 - i);

    std::cout << "Vector: ";
    for (auto i : vect)
        std::cout << i << " ";

    std::cout << "\n";

    std::deque<int> deq;
    for (int i = 0; i < 3; i++)
    {
        deq.push_back(i);
        deq.push_front(10 - i);
    }

    std::cout << "Deque: ";
    for (auto i : deq)
        std::cout << i << " ";

    std::cout << "\n";
}
