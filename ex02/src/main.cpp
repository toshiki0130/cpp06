#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Base.hpp"

void test_pointer()
{
    std::cout << "==== start test_pointer ====: " << std::endl;
    for (int i=0; i < 10; i++) {
        Base*p = generate();
        std::cout << "actual object is: ";
        identify(p);
        delete p;
    }
}

void test_reference()
{
    std::cout << "==== start test_reference ====: " << std::endl;
    for (int i=0; i < 10; i++) {
        Base*p = generate();
        std::cout << "actual object is: ";
        identify(*p);
        delete p;
    }
}

int main() {
    srand(static_cast<unsigned int>(std::time(0)));
    test_pointer();
    test_reference();
}
