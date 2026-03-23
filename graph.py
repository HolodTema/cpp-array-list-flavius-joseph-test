import matplotlib.pyplot as plt

sizes = [1000, 5000, 10_000, 50_000, 100_000, 500_000, 1_000_000]
microseconds = [1406, 34081, 135633, 3280478, 7404990, 146452177, 588028995]

plt.figure(figsize=(10, 6))

plt.plot(sizes, microseconds, 'o-', label='ArrayList performance', color='royalblue')

plt.title("Тест Иосифа-Флавия для C++ ArrayList", fontsize=14)
plt.xlabel("Число элементов (N)", fontsize=12)
plt.ylabel("Время выполнения (микросекунды)", fontsize=12)
plt.grid(True, linestyle='--', alpha=0.7)
plt.legend()

plt.show()