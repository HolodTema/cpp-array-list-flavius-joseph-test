#include <iostream>
#include "ArrayList.hpp"
#include "iosifTests.hpp"

void noCli() {
    ArrayList<int> sizes(8);
    sizes.add(1000);
    sizes.add(5000);
    sizes.add(10000);
    sizes.add(50000);
    sizes.add(100000);
    sizes.add(500000);
    sizes.add(1000000);
    
    size_t step = 3;

    iosifTestBundle(sizes, step, std::cout);
}

void cli() {
    iosifTestCLI(std::cin, std::cout);
}

int main() {
    noCli();
    return 0;
}

