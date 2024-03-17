#include <iostream>
#include "IntSet.h"

int main() {
    auto set1 = IntSet();
    const int elements1[] = {1, 2, 3, 4, 5};
    auto set2 = IntSet(elements1, 5);
    set1.addElement(1);
    set1.addElement(2);
    set2.deleteElement(5);
    auto set3 = set1 + set2;
    auto set4 = set2 - set1;
    std::cout << set2;

    set3.printElements();
    set4.printElements();
//    readStoreWriteSet(2);
    std::cout << "HOPA;";
    return 0;
}
