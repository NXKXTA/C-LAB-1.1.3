#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#define N 90000


int find_index7(int A[N], int len)
{
    for (int i = 0; i < len; i++)
        if (A[i] % 7 == 0)
            return i;
}


int main()
{
    int size = 0, counter = 0, sum7 = 0;
    int digits[N]; // Здесь будет вводимая последовательность
    char term;
    setlocale(0, "");
    printf("Введите количество вводимых целых чисел:\n");
    if (scanf("%d%c", &size, &term) != 2) // Ввод длинны последовательности чисел
    {
        printf("Указано неверное количество вводимых чисел\n");
        return 0;
    }

    if (term != '\n' || size <= 0 || size >= N)
    {
        printf("Указано неверное количество вводимых чисел\n");
        return 0;
    }


    printf("Введите последовательность чисел:\n");
    for (int i = 0; i < size; i++)
        if (scanf("%d", &digits[i]) != 1) // Ввод последовательности чисел
        {
            printf("Введено неверное число\n");
            return 0;
        }


    printf("Введённая вами последовательность выглядит так:\n");
    for (int i = 0; i < size; i++)
        printf("%d ", digits[i]); // Выводим введённую последовательность
    printf("\n");


    int last7 = size + 1, index7 = size + 1; // Объявить и инициализировать индекс элемента, значение которого меньше его индекса
    // и индекс первого элемента кратного 7


    index7 = find_index7(digits, size); // Индекс первого кратного 7 числа
    for (int i = size - 1; i > index7; i--)
        if (digits[i] < i + 1)
        {   // Последний элемент, значение которого меньше его порядкового номера(индекс этого элемента)
            last7 = i;
            break;
        }


    if (index7 == size + 1 || index7 == last7 || index7 == size - 1 || last7 - index7 < 2)
    {   // Проверяем есть ли index7. Не является ли index7 тем же элементом, что и last7. Не в конце ли index7. Есть ли хоть 1 элемент между index7 и last7
        printf("Cумма = 0\nКол-во элементов последовательности = 0");
        return 0;
    }


    if (last7 == size + 1)
    {
        printf("Подходящий промежуток: ");
        for (int i = index7 + 1; i < size; i++)
        {
            printf("%d ", digits[i]);
            sum7 += digits[i];
            counter += 1;
        }
        printf("\nСумма = %d\n", sum7);
        printf("Кол-во элементов последовательности = %d", counter);
        return 0;
    }
    else
    {
        printf("Подходящий промежуток: ");
        for (int i = index7 + 1; i < last7; i++)
        {
            printf("%d ", digits[i]);
            sum7 += digits[i];
            counter += 1;
        }
        printf("\nСумма = %d\n", sum7);
        printf("Кол-во элементов последовательности = %d", counter);
        return 0;
    }
}