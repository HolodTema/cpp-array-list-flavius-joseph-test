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


int iosifTest(ArrayList<int>& arrayList, size_t step)
{
    size_t index = 0;
    
    while (arrayList.getSize() > 1)
    {
        index = (index + step - 1) % arrayList.getSize();
        arrayList.remove(index);
    }
    return arrayList.get(0);
}


void iosifTestBundle(const ArrayList<int>& sizes, size_t step, std::ostream& out)
{
    int answer = 0;
    long long time = 0;

    out << "N\t\t\tAnswer\t\t\tTime (microseconds)\n";

    for (int i = 0; i < sizes.getSize(); ++i)
    {
        ArrayList<int> generatedList = generateArrayList(sizes.get(i));
        
        out << sizes.get(i) << "\t\t\t";
        
        auto startTime = std::chrono::high_resolution_clock::now();

        answer = iosifTest(generatedList, step);
        
        auto endTime = std::chrono::high_resolution_clock::now();
        auto durationMicros = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
        time = durationMicros.count();
        
        out << answer << "\t\t\t";
        out << time << "\t\t\t\n";
    }
}

void iosifTestCLI(std::istream& is, std::ostream& os)
{
    size_t n = 0;
    size_t step = 0;

    os  << "Flavius Josephus test CLI\n";
    os << "Enter N:\n";
    is >> n;
    os << "Enter step (k):\n";
    is >> step;

    os << "Starting test...\n";

    ArrayList<int> generatedList = generateArrayList(n);
        
    auto startTime = std::chrono::high_resolution_clock::now();
    int answer = iosifTest(generatedList, step);
    auto endTime = std::chrono::high_resolution_clock::now();
    auto durationMicros = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
    long long time = durationMicros.count();

    os << "Answer: " << answer << "\n";
    os << "Time (microseconds): " << time << "\n";
}
        
     


