#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <locale.h>
#define _USE_MATH_DEFINES
#include <math.h>

double func(double x);

int main() {
    setlocale(LC_ALL, "RUS");
    FILE* file;
    char filename[] = "func.txt";
    double start, end, step;
    do
    {
        printf("Введите начало интервала (2-4): ");
        scanf("%lf", &start);
    } while (start < 2 || start >= 4);
    do
    {
        printf("Введите конец интервала (2-4): ");
        scanf("%lf", &end);
    } while (end <= 2 || end > 4 || end <= start);
    do
    {
        printf("Введите шаг табуляции: ");
        scanf("%lf", &step);
    } while (step <= 0);
    int choice;
    printf("Выберите действие\n");
    printf("1 - запись в новый файл\n");
    printf("2 - дозапись в существующий файл\n");
    scanf("%d", &choice);
    if (choice == 1)
    {
        file = fopen(filename, "w");
    }
    else if (choice == 2)
    {
        file = fopen(filename, "a");
    }
    else
    {
        printf("Неверный выбор действия. Программа завершена.\n");
        return 1; 
    }
    fprintf(file, "x\t\t y\n");
    for (double x = start; x <= end; x += step)
    {
        double y = func(x);
        fprintf(file, "%.4lf\t%.4lf\n", x, y);
    }
    fclose(file);
    printf("Результаты записаны в файл %s\n", filename);
    return 0;
}

double func(double x)
{
    return pow(x, 3) + 3 * pow(x, 2) - 3;
}