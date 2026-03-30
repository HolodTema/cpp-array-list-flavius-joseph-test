import matplotlib.pyplot as plt

def mnk(listTheory, listPractice):
    numerator = sum(listTheory[i] * listPractice[i] for i in range(len(listTheory)))
    denominator = sum(x**2 for x in listTheory)
    return numerator / denominator


sizes = [1000, 5000, 10_000, 50_000, 100_000, 500_000, 1_000_000]
microsecondsTheoretical= [x**2 for x in sizes]
microsecondsReal = [1217, 30090, 131549, 3275042, 9234851, 151277353, 607249055]

# f(n) = k*O(n)
k = mnk(microsecondsTheoretical, microsecondsReal)

microsTheoryMNK = [x*k for x in microsecondsTheoretical]
print(microsTheoryMNK)

plt.figure(figsize=(10, 6))

# graph of real time
plt.plot(sizes, microsecondsReal, 'o-', label='real perfomance', color='blue', linewidth=3)

plt.plot(sizes, microsTheoryMNK, 'o-', label=f'theoretical performance = k*n^2 where k = {k}', color='red')

plt.title("Тест Иосифа-Флавия для C++ ArrayList", fontsize=14)
plt.xlabel("Число элементов (N)", fontsize=12)
plt.ylabel("Время выполнения (микросекунды)", fontsize=12)
plt.grid(True, linestyle='--', alpha=0.7)
plt.legend()

plt.show()
