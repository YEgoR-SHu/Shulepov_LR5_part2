#ifndef EVEN_MATH_TASK_HPP
#define EVEN_MATH_TASK_HPP

#include <string>
#include <functional>
#include <iostream>

struct Numbers {
    int x, y, z;
};

// Проверка корректности ввода строки
inline bool UserInput(const std::string& input) {
    if (input.empty() || input[0] == '-') return false;

    size_t pos;
    try {
        int value = std::stoi(input, &pos);
        return pos == input.size();
    } catch (...) {
        return false;
    }
}

// Функция-обертка для ввода значения
inline std::function<void()> EnterNumber(int &varLink, const std::string &label) {
    return [&varLink, label]() {
        std::string raw_input;
        std::cout << label;
        std::getline(std::cin, raw_input);

        while (!UserInput(raw_input)) {
            std::cout << label;
            std::getline(std::cin, raw_input);
        }
        varLink = std::stoi(raw_input);
    };
}

// Подсчет количества четных чисел
inline int CountEven(const Numbers& nums) {
    int count = 0;
    if (nums.x % 2 == 0) count++;
    if (nums.y % 2 == 0) count++;
    if (nums.z % 2 == 0) count++;
    return count;
}

// Подсчет суммы четных чисел
inline int SumEven(const Numbers& nums) {
    int sum = 0;
    if (nums.x % 2 == 0) sum += nums.x;
    if (nums.y % 2 == 0) sum += nums.y;
    if (nums.z % 2 == 0) sum += nums.z;
    return sum;
}

#endif
