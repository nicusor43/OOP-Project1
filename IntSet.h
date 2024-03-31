//
// Created by nicusor43 on 3/15/24.
//

#ifndef OOPPROJ1_INTSET_H
#define OOPPROJ1_INTSET_H

#include <iostream>

class IntSet {
    int *vector{};
    int size{}; // number of elements in the set

public:
    IntSet();

    IntSet(const int *elements, int size);

    IntSet(const IntSet &other); // copy constructor

    ~IntSet();

    IntSet &operator=(const IntSet &set2);

    IntSet operator+(const IntSet &set2) const;

    IntSet operator-(const IntSet &set2) const;

    IntSet operator*(const IntSet &set2) const;

    // cerinte suplimentare
    friend IntSet operator+(IntSet set, int x);
    friend IntSet operator+(int x, IntSet set);

    friend IntSet operator-(IntSet set, int x);
    friend IntSet operator-(int x, IntSet set);

    friend IntSet operator*(IntSet set, int x);
    friend IntSet operator*(int x, IntSet set);



    friend std::ostream &operator<<(std::ostream &out, IntSet const &set);

    friend std::istream &operator>>(std::istream &in, IntSet &set);


    void addElement(int element);
    void addElementEfficent(int element);

    void deleteElement(int element);

    void printElements();

    // cerinte noi

    bool Contains(int element);
    void IncreaseWith(int amount);

    void OrderElements();
    void OrderElements(bool (*func)(int, int));

    void ApplyTransformation(int (*func) (int));

    [[nodiscard]] int getSize() const; // nodiscard is a clang-tidy suggestion
    // Get + Set la vector nu are sens, cat timp avem alte metode care fac acelasi lucru mai bine

};

IntSet vectorToSet(const int elements[], int size);

void readStoreWriteSet(int numberOfSets);

#endif //OOPPROJ1_INTSET_H
