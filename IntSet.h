//
// Created by nicusor43 on 3/15/24.
//

#ifndef OOPPROJ1_INTSET_H
#define OOPPROJ1_INTSET_H

#include <iostream>
#include <algorithm>
#include <iterator>

class IntSet {
    int *vector{};
    int size{}; // number of elements in the set

public:
    IntSet();

    IntSet(const int *elements, int size);
    // IntSet(const IntSet &other); todo
    ~IntSet();
    IntSet &operator=(const IntSet &set2);
    IntSet operator+(const IntSet &set2) const;
    IntSet operator-(const IntSet &set2) const;


    void addElement(int element);

    void deleteElement(int element);

    void printElements();


    [[nodiscard]] int getSize() const; // nodiscard is a clang-tidy suggestion
    // Get + Set la vector nu are sens, cat timp avem alte metode care fac acelasi lucru mai bine

};

IntSet vectorToSet(const int elements[], int size);

#endif //OOPPROJ1_INTSET_H
