#include <iostream>
#include "IntSet.h"
#include "test/IntSetTest.h"

int main() {
    IntSetTest::TestConstructorCuParametri();
    IntSetTest::TestConstructorCopiere();
    IntSetTest::TestAdaugareElement();
    IntSetTest::TestStergereElement();
    IntSetTest::TestOperatorPlus();
    IntSetTest::TestOperatorMinus();
    IntSetTest::TestOperatorStea();
//    IntSetTest::TestMetodaVectorMultime();
    IntSetTest::TestAdaugareElementEfficent();
//    IntSetTest::TestOperatorCitire();

    IntSetTest::TestOrderElements();

    return 0;
}
