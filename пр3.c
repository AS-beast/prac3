#include <stdio.h>
#include <math.h>

int lab(int n) {     /* Функція перевірки, чи є в числі три послідовних 9 */
    int lab_count = 0;
    int consecutiveNines = 0;
    while (n > 0) {
        int number = n % 10;
        n /= 10;
        if (number == 9) {
            consecutiveNines++;
            if (consecutiveNines >= 3) {
                lab_count++;
                break;
            }
        }
        else {
            consecutiveNines = 0;
        }
    }
    return lab_count;
}
int countNumbers(int p) {  /* Функція підрахунку кількості допустимих чисел з p */
    if (p == 1)
        return 2; 
    if (p == 2)
        return 4; 

    int current = 0;
    int total_count = pow(2, p);
    for (int i = 0; i < total_count; i++) {
        int combinedNumber = 0;
        for (int j = p - 1; j >= 0; j--) {
            int bit = (i >> j) & 1;
            int digit = bit ? 5 : 9;
            combinedNumber += digit * pow(10, j);
        }
        current += lab(combinedNumber); /* Викликати функцію для перевірки комбінованого числа з трьома або більше п'ятірками підряд і оновити підрахунок.  */
    }
    return total_count - current*2;
}

int main() {
    int p; 
    printf("Введіть розрядність: ");
    scanf("%d", &p);
    if (p>=1){
        int count = countNumbers(p);
        printf("Кількість числ %d розрядності: %d\n", p, count);
    }
    return 0;
}