//
// Created by nicusor43 on 3/15/24.
//

#include "IntSet.h"

IntSet::IntSet() {
    vector = new int[0];
    size = 0;
}

IntSet::IntSet(const int elements[], int newSize) {
    IntSet tempSet = vectorToSet(elements, newSize);
    vector = tempSet.vector;
    size = tempSet.size;
}

void IntSet::addElement(int element) {
    bool isAlready = false;

    for (int i = 0; i < size; i++) {
        if (element == vector[i]) {
            isAlready = true;
            break;
        }
    }

    if (isAlready) return;

    int *newVector = new int[size + 1];
    for (int i = 0; i < size; i++) {
        newVector[i] = vector[i];
    }
    newVector[size] = element;
    delete[] vector;
    vector = new int[size + 1];
    //vector = newVector; BAD; IDIOTIC REALLY
    for (int i = 0; i < size + 1; i++) {
        vector[i] = newVector[i];
    }
    delete[] newVector;
    size++;
}

void IntSet::deleteElement(int element) {
    bool isInSet = false;
    int index = 0;
    for (int i = 0; i <= size; i++) {
        if (vector[i] == element) {
            isInSet = true;
            index = i;
            break;
        }
    }

    if (!isInSet) {
        std::cout << "Elementul " << element << "pe care vrei sa-l stergi nu e in set" << std::endl;
        return;
    }

    int *newVector = new int[size - 1];
    for (int i = 0; i < index; i++) {
        newVector[i] = vector[i];
    }
    for (int i = index + 1; i < size - 1; i++) {
        newVector[i - 1] = vector[i];
    }

    delete[] vector;
    vector = new int[size - 1];
    for (int i = 0; i < size - 1; i++) {
        vector[i] = newVector[i];
    }
    delete[] newVector;
    size--;
}

IntSet &IntSet::operator=(const IntSet &set2) {
    delete[] this->vector;
    this->vector = new int[set2.size];
    for (int i = 0; i < set2.size; i++) {
        this->vector[i] = set2.vector[i];
    }
    this->size = set2.size;
    return *this;
}

IntSet IntSet::operator+(const IntSet &set2) const {
    IntSet newSet = IntSet();
    for (int i = 0; i < size; i++) {
        newSet.addElement(vector[i]);
    }
    for (int i = 0; i < set2.size; i++) {
        newSet.addElement(set2.vector[i]);
    }
    return newSet;
}

IntSet IntSet::operator-(const IntSet &set2) const {
    IntSet newSet = IntSet();
    for (int i = 0; i < this->size; i++) {
        bool isAlready = false;
        for (int j = 0; j < set2.size; j++) {
            if (this->vector[i] == set2.vector[j]) {
                isAlready = true;
                break;
            }
        }
        if (!isAlready) {
            newSet.addElement(this->vector[i]);
        }
    }
    return newSet;
}

void IntSet::printElements() {
    for (int i = 0; i < size; i++) {
        std::cout << vector[i] << " ";
    }
}

int IntSet::getSize() const {
    return size;
}

IntSet::~IntSet() {
    delete[] vector;
}

IntSet vectorToSet(const int elements[], int size) {
    IntSet newSet;
    for (int i = 0; i < size; i++) {
        newSet.addElement(elements[i]);
    }
    return newSet;
}

//IntSet::IntSet(const IntSet &other) : elements(other.elements) {
//    this->size = other.size;
//}
//
//// The default destructor is enough for this class
//IntSet::~IntSet() {
//    std::cout << "The destructor was called" << std::endl;
//}
//
//IntSet &IntSet::operator=(const IntSet &set2) {
//    this->elements = set2.elements;
//    this->size = set2.size;
//    return *this;
//}
//
////IntSet &IntSet::operator=(const IntSet &set2) = default;
//
//int IntSet::getSize() const {
//    return size;
//}
//
//IntSet IntSet::operator+(const IntSet &set2) const {
//    std::vector<int> newElements = elements;
//    // TODO
//}
//
//std::vector<int> IntSet::VectorToSet(std::vector<int> elements) {
//    elements.erase(std::unique(elements.begin(), elements.end()), elements.end());
//    return elements;
//}











