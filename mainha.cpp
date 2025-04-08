#include "mainha.h"
#include <iostream>
using namespace std;

int main() {
    Numbers nums{0, 0, 0};

    EnterNumber(nums.x, "Введите число X: ")();
    EnterNumber(nums.y, "Введите число Y: ")();
    EnterNumber(nums.z, "Введите число Z: ")();

    int evenCount = CountEven(nums);
    int evenSum = SumEven(nums);

    cout << "Количество четных чисел: " << evenCount << endl;
    cout << "Сумма четных чисел: " << evenSum << endl;

    return 0;
}
