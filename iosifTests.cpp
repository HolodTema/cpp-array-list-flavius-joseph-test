#include "iosifTests.hpp"
#include <chrono>
#include "ArrayList.hpp"

ArrayList<int> generateArrayList(size_t size)
{
    ArrayList<int> arrayList(size);
    for (int i = 1; i <= size; ++i)
    {
        arrayList.add(i);
    }
    return arrayList;
}


long long iosifTest(ArrayList<int>& arrayList, size_t step)
{
    size_t index = 0;
    size_t size = arrayList.getSize();
    
    auto startTime = std::chrono::high_resolution_clock::now();
    while (size > 1)
    {
        index = (index + step) % size;
        arrayList.pop(index);
        --size;
    }
    auto endTime = std::chrono::high_resolution_clock::now();

    auto durationMicroseconds = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
    return durationMicroseconds.count();
}


void iosifTestBundle(const ArrayList<int> sizes, size_t step, std::ostream& out)
{
    long long time = 0L;
    for (int i = 0; i < sizes.getSize(); ++i)
    {
        ArrayList<int> generatedList = generateArrayList(sizes.get(i));
        
        out << sizes.get(i) << "\t";

        time = iosifTest(generatedList, step);

        out << time << "\n";
    }
}


