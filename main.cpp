#include <iostream>
#include "ArrayList.hpp"
#include "iosifTests.hpp"

int main()
{
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
    return 0;
}
