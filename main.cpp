#include <iostream>
#include "IntSet.h"

int main() {
    auto set1 = IntSet();
    const int elements[] = {1, 2, 3, 4, 5, 5, 5};
    set1 = IntSet(elements, 7);
    std::cout << "set 1 before =: ";
    set1.printElements();
    auto set2 = set1;
    std::cout << '\n' << "set 1: ";
    set1.printElements();

    set2.addElement(10);
    set2.addElement(11);
    std::cout << '\n' << "set 1 after -: ";
    set1.printElements();

    set1.deleteElement(5);
//    std::cout << '\n';
//    std::cout << "set 2: ";
//    set2.printElements();
//    std::cout << '\n';
//    std::cout << "set 3 = set 2 - set 1: ";
//    set3.printElements();
    return 0;
}
