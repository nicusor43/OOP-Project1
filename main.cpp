#include <iostream>
#include "IntSet.h"

int main() {
    auto set1 = IntSet();
    const int elements[] = {1, 2, 3, 4, 5, 5, 5};
    set1 = IntSet(elements, 7);
    auto set2 = vectorToSet(elements, 7);
    auto set3 = set2 - set1;
    std::cout << set3;
    std::cin >> set3;
    std::cout << set3;
    return 0;
}
