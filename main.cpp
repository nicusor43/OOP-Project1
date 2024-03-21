#include <iostream>
#include "IntSet.h"
#include "IntSetTest.h"

int main() {
//    auto set1 = IntSet();
//    const int elements1[] = {1, 2, 3, 4, 5};
//    auto set2 = IntSet(elements1, 5);
//    set1.addElement(1);
//    set1.addElement(2);
//    set2.deleteElement(5);
//    auto set3 = set1 + set2;
//    auto set4 = set2 - set1;
//    std::cout << set2;
//
//    set3.printElements();
//    readStoreWriteSet(2);
//    set3.getSize();
//
//    std::cout << "HOPA;";

    IntSetTest::TestConstructorCuParametri();
    IntSetTest::TestConstructorCopiere();
    IntSetTest::TestAdaugareElement();
    IntSetTest::TestStergereElement();
    IntSetTest::TestOperatorPlus();
    IntSetTest::TestOperatorMinus();
    IntSetTest::TestOperatorStea();
    IntSetTest::TestMetodaVectorMultime();
    IntSetTest::TestAdaugareElementEfficent();
    IntSetTest::TestOperatorCitire();


    return 0;
}
