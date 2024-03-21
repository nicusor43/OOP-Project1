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
    size = tempSet.size;

    delete[] vector;
    vector = new int[size];

    for (int i = 0; i < size; ++i) {
        vector[i] = tempSet.vector[i];
    }
}

IntSet::IntSet(const IntSet &other) {
    this->vector = new int[other.size];
    this->size = other.size;

    if(other.vector != nullptr) {
        for (int i = 0; i < other.size; i++) {
            this->vector[i] = other.vector[i];
        }
    }
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

    for (int i = 0; i < size + 1; i++) {
        vector[i] = newVector[i];
    }

    delete[] newVector;
    size++;
}

void IntSet::deleteElement(int element) {
    bool isInSet = false;
    int index;

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

    for (int i = index + 1; i < size; i++) {
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
    // self-assignment check
    if (this == &set2) {
        return *this;
    }

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

[[nodiscard]] int IntSet::getSize() const {
    return size;
}

IntSet::~IntSet() {
    delete[] vector;
}

std::ostream &operator<<(std::ostream &out, const IntSet &set) {
    for (int i = 0; i < set.size; i++) {
        out << set.vector[i] << " ";
    }
    return out;
}

std::istream &operator>>(std::istream &in, IntSet &set) {
    std::cout << "Introduceti numarul de elemente din multime: " << std::endl;
    int newSize;
    in >> newSize;

    delete[] set.vector;
    set.vector = new int[0];
    set.size = 0;

    for (int i = 0; i < newSize; i++) {
        std::cout << "Introduce elementul " << i + 1 << " din multimea noua: ";
        int newElement;
        in >> newElement;
        set.addElementEfficent(newElement);
    }

    return in;
}

IntSet IntSet::operator*(const IntSet &set2) const {
    IntSet newSet = IntSet();
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < set2.size; j++) {
            if (this->vector[i] == set2.vector[j]) {
                newSet.addElement(this->vector[i]);
            }
        }
    }
    return newSet;
}

void IntSet::addElementEfficent(int element) {
    int newLength = size + 1;
    int *newVector = new int[newLength];

    for (int i = 0; i < size; i++) {
        newVector[i] = vector[i];
        if (vector[i] == element) {
            delete[] newVector;
            return;
        }
    }

    newVector[size] = element;
    delete[] vector;
    vector = newVector;
    size++;
}


IntSet vectorToSet(const int elements[], int size) {
    IntSet newSet;
    for (int i = 0; i < size; i++) {
        newSet.addElement(elements[i]);
    }
    return newSet;
}

void readStoreWriteSet(int numberOfSets) {
    std::cout << "Introduceti " << numberOfSets << " seturi." << std::endl;
    for (int i = 0; i < numberOfSets; i++) {

        int size;
        std::cout << "Introduceti numarul de elemente din setul " << i+1 << ": ";
        std::cin >> size;

        std::cout << "Introduceti elementele din setul " << i+1 << ": ";
        int *elements = new int[size];

        for (int j = 0; j < size; j++) {
            std::cin >> elements[j];
        }

        IntSet newSet = vectorToSet(elements, size);
        std::cout << std::endl << "Elementele din setul" << i+1 << " sunt: ";
        std::cout << newSet << std::endl;
        delete[] elements;
    }
}








