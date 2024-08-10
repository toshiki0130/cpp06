# include "Base.hpp"
# include <iostream>
# include <cstdlib>
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

Base::~Base()
{
    std::cout << "[Base destructor is called]" << std::endl;
}

Base* generate(void)
{
    int ran_n = rand() % 3;
    switch (ran_n) {
        case (0):
            std::cout << "A is generated" << std::endl;
            return new A();
        case (1):
            std::cout << "B is generated" << std::endl;
            return new B();
        case (2):
            std::cout << "C is generated" << std::endl;
            return new C();
    }
    return NULL;
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "Others" << std::endl;
    }
}

void identify(Base& p)
{
    try {
        A& a = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        (void)a;
        return ;
    } catch (std::exception const& e){};
    try {
        B& b = dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        (void)b;
        return ;
    } catch (std::exception const& e){};
    try {
        C& c = dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        (void)c;
        return ;
    } catch (std::exception const& e){};
}