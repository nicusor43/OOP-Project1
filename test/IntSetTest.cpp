//
// Created by nicusor43 on 3/21/24.
//

#include "IntSetTest.h"

void IntSetTest::TestConstructorCuParametri() {
    const int elements[] = {1, 2, 3, 4, 5};
    auto set = IntSet(elements, 5);

    std::cout << "TestConstructorCuParametri " << set << std::endl;
}

void IntSetTest::TestConstructorCopiere() {
    const int elements[] = {1, 2, 3, 4, 5};
    auto set = IntSet(elements, 5);
    auto set2 = IntSet(set);

    std::cout << "TestConstructorCopiere " << set2 << std::endl;
}

void IntSetTest::TestAdaugareElement() {
    auto set = IntSet();
    set.addElement(1);
    set.addElement(2);
    set.addElement(3);
    set.addElement(4);
    set.addElement(5);

    std::cout << "TestAdaugareElement " << set << std::endl;
}

void IntSetTest::TestStergereElement() {
    const int elements[] = {1, 2, 3, 4, 5};
    auto set = IntSet(elements, 5);
    set.deleteElement(5);

    std::cout << "TestStergereElement " << set << std::endl;
}

void IntSetTest::TestOperatorPlus() {
    const int elements1[] = {1, 2, 3, 4, 5, 6};
    auto set1 = IntSet(elements1, 5);
    const int elements2[] = {6, 7, 8, 9, 10};
    auto set2 = IntSet(elements2, 5);
    auto set3 = set1 + set2;

    std::cout << "TestOperatorPlus " << set3 << std::endl;
}

void IntSetTest::TestOperatorMinus() {
    const int elements1[] = {1, 2, 3, 4, 5, 6, 7};
    auto set1 = IntSet(elements1, 7);
    const int elements2[] = {6, 7, };
    auto set2 = IntSet(elements2, 2);
    auto set3 = set1 - set2;

    std::cout << "TestOperatorMinus " << set3 << std::endl;
}

void IntSetTest::TestOperatorStea() {
    const int elements1[] = {1, 2, 3, 4, 5};
    auto set1 = IntSet(elements1, 5);

    const int elements2[] = {1, 2, 3, 6, 7};
    auto set2 = IntSet(elements2, 5);

    std::cout << "TestOperatorStea " << set1 * set2 << std::endl;
}

void IntSetTest::TestMetodaVectorMultime() {
    const int elements[] = {1, 2, 3, 4, 5, 5};
    auto set = vectorToSet(elements, 6);

    std::cout << "TestMetodaVectorMultime " << set << std::endl;
}

void IntSetTest::TestReadStoreWriteSet() {
    readStoreWriteSet(2);
}

void IntSetTest::TestAdaugareElementEfficent() {
    auto set = IntSet();
    set.addElementEfficent(1);
    set.addElementEfficent(2);
    set.addElementEfficent(3);
    set.addElementEfficent(4);
    set.addElementEfficent(5);
    set.addElementEfficent(5);

    std::cout << "TestAdaugareElementEfficent " << set << std::endl;
}

void IntSetTest::TestOperatorCitire() {
    const int elements[] = {1, 2, 3, 4, 5};
    auto set = IntSet(elements, 5);

    std::cout << "Test Operator Citire: ";
    std::cin >> set;
    std::cout << set << std::endl;
}

void IntSetTest::TestOrderElements() {
    const int elements[] = {5, 7, 8, 4, 5};
    auto set = IntSet(elements, 5);

    std::cout << "Elementele inainte de ordonare: " << set << '\n';
    set.OrderElements();
    std::cout << "Elementele dupa ordonare: ";
    std::cout << set;
}







