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
    int digits[N]; // ����� ����� �������� ������������������
    char term;
    setlocale(0, "");
    printf("������� ���������� �������� ����� �����:\n");
    if (scanf("%d%c", &size, &term) != 2) // ���� ������ ������������������ �����
    {
        printf("������� �������� ���������� �������� �����\n");
        return 0;
    }

    if (term != '\n' || size <= 0 || size >= N)
    {
        printf("������� �������� ���������� �������� �����\n");
        return 0;
    }


    printf("������� ������������������ �����:\n");
    for (int i = 0; i < size; i++)
        if (scanf("%d", &digits[i]) != 1) // ���� ������������������ �����
        {
            printf("������� �������� �����\n");
            return 0;
        }


    printf("�������� ���� ������������������ �������� ���:\n");
    for (int i = 0; i < size; i++)
        printf("%d ", digits[i]); // ������� �������� ������������������
    printf("\n");


    int last7 = size + 1, index7 = size + 1; // �������� � ���������������� ������ ��������, �������� �������� ������ ��� �������
    // � ������ ������� �������� �������� 7


    index7 = find_index7(digits, size); // ������ ������� �������� 7 �����
    for (int i = size - 1; i > index7; i--)
        if (digits[i] < i + 1)
        {   // ��������� �������, �������� �������� ������ ��� ����������� ������(������ ����� ��������)
            last7 = i;
            break;
        }


    if (index7 == size + 1 || index7 == last7 || index7 == size - 1 || last7 - index7 < 2)
    {   // ��������� ���� �� index7. �� �������� �� index7 ��� �� ���������, ��� � last7. �� � ����� �� index7. ���� �� ���� 1 ������� ����� index7 � last7
        printf("C���� = 0\n���-�� ��������� ������������������ = 0");
        return 0;
    }


    if (last7 == size + 1)
    {
        printf("���������� ����������: ");
        for (int i = index7 + 1; i < size; i++)
        {
            printf("%d ", digits[i]);
            sum7 += digits[i];
            counter += 1;
        }
        printf("\n����� = %d\n", sum7);
        printf("���-�� ��������� ������������������ = %d", counter);
        return 0;
    }
    else
    {
        printf("���������� ����������: ");
        for (int i = index7 + 1; i < last7; i++)
        {
            printf("%d ", digits[i]);
            sum7 += digits[i];
            counter += 1;
        }
        printf("\n����� = %d\n", sum7);
        printf("���-�� ��������� ������������������ = %d", counter);
        return 0;
    }
}