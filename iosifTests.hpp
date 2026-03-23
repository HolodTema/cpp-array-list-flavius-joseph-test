#ifndef IOSIF_TESTS_HPP
#define IOSIF_TESTS_HPP

#include <chrono>
#include <iostream>
#include "ArrayList.hpp"

ArrayList<int> generateArrayList(size_t size);

long long iosifTest(ArrayList<int>& arrayList, size_t step);

void iosifTestBundle(const ArrayList<int> sizes, size_t step, std::ostream& out);

#endif
