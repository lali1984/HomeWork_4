#include <random>
#include <iostream>
#include <array>
#include <iomanip>
namespace HomeWork4Func
{
    int RandomGeneration(int begin, int end)
    {
        std::random_device num;  //генерирует началиное число для генерации
        std::mt19937_64 gen(num()); //генерирует случайные числа с использованием алгоритма Mersenne Twister
        std::uniform_int_distribution<> distrib(begin, end); // распределяет последовательность в (-25, 25)

        return distrib(gen);
    }

    void PrintArray(const std::array<int, 100>& container)
    {
        std::cout << "Input random array:\tsize = " << container.size() << "\n";
        int i = 0;

        for (int val : container)
        {
            std::cout << "a[" << std::setw(2) << i << "]=" << std::setw(3) << val << " | ";
            i++;

        }

        std::cout << "\n\n";
    }

    void PrintVector(const std::vector<int>& container, int version)
    {
        std::cout << "Vector transform: " << version << "\tsize = " << container.size() << "\n";
        int i = 0;

        for (int val : container)
        {
            std::cout << "v[" << std::setw(2) << i << "]=" << std::setw(3) << val << " | ";
            i++;
        }
            

        std::cout << "\n\n";
    }

    void FindeMinMaxVal(const std::vector<int>& container)
    {
        int max = -25;
        int min = 25;

        for (int val : container)
        {
            if (max < val)
                max = val;

            if (min > val)
                min = val;
        }
        std::cout << "MAX value in dynArray version_2= " << max << '\n';
        std::cout << "MIN value in dynArray version_2 = " << min << "\n\n";
    }
}