import matplotlib.pyplot as plt

sizes = [1000, 5000, 10_000, 50_000, 100_000, 500_000, 1_000_000]
microsecondsTheoretical= [x**2 for x in sizes]
microsecondsReal = [1226, 29414, 118292, 3303564, 7825702, 146452177, 588028995]

plt.figure(figsize=(10, 6))

# graph of real time
plt.plot(sizes, microsecondsTheoretical, 'o-', label='theoretical performance', color='red')
plt.plot(sizes, microsecondsReal, 'o-', label='real perfomance', color='blue')
# graph of

plt.title("Тест Иосифа-Флавия для C++ ArrayList", fontsize=14)
plt.xlabel("Число элементов (N)", fontsize=12)
plt.ylabel("Время выполнения (микросекунды)", fontsize=12)
plt.grid(True, linestyle='--', alpha=0.7)
plt.legend()

plt.show()