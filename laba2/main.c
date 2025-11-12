#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Объявления функций
void title(void);
void fillArray(int arr[], int size, int mode);
void printArray(int arr[], int size);
int task1(int arr[], int size);
int task2(int arr[], int size);

void main() {
    setlocale(LC_ALL, "en_US.UTF-8");
    
    title();
    
    int size;
    int fill_mode;
    
    printf("Введите размер массива: ");
    scanf("%d", &size);
    
    printf("Выберите способ заполнения массива (1 - с клавиатуры, 2 - случайные значения): ");
    scanf("%d", &fill_mode);
    
    int arr[size];
    fillArray(arr, size, fill_mode);
    
    printf("\nМассив: ");
    printArray(arr, size);
    
    // Задание 1
    printf("\nЗадание 1.\n");
    int result1 = task1(arr, size);
    if (result1 != -1) {
        printf("Минимальный четный элемент: %d\n", result1);
    } else {
        printf("Четные элементы не найдены\n");
    }
    
    // Задание 2
    printf("\nЗадание 2.\n");
    int result2 = task2(arr, size);
    if (result2 != -1) {
        printf("Индекс последнего нечетного элемента, некратного первому: %d\n", result2);
    } else {
        printf("Подходящие элементы не найдены\n");
    }
}

void title() {
    printf("Лабораторная работа № 2\n");
    printf("Вариант № 1, группа 6105-090301D, автор Варламов Дамир Алексеевич\n\n");
}

void fillArray(int arr[], int size, int mode) {
    if (mode == 1) {
        // Заполнение с клавиатуры
        printf("Введите %d элементов массива:\n", size);
        for (int i = 0; i < size; i++) {
            printf("arr[%d] = ", i);
            scanf("%d", &arr[i]);
        }
    } else {
        // Заполнение случайными значениями
        printf("Заполнение массива случайными значениями...\n");
        for (int i = 0; i < size; i++) {
            arr[i] = rand() % 100;  // числа от 0 до 99
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// ЗАДАНИЕ 1: Минимальный четный элемент (цикл for)
int task1(int arr[], int size) {
    printf("В массиве целого типа найти минимальный четный элемент\n");
    
    int min_even = -1;
    int found = 0;
    
    // Цикл for для перебора всех элементов
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {  // проверка на четность
            if (!found || arr[i] < min_even) {
                min_even = arr[i];
                found = 1;
            }
        }
    }
    
    return found ? min_even : -1;
}

// ЗАДАНИЕ 2: Индекс последнего нечетного элемента, некратного первому (цикл while)
int task2(int arr[], int size) {
    printf("В массиве целого типа найти индекс последнего нечетного элемента, некратного первому элементу массива\n");
    
    if (size == 0) return -1;  // массив пустой
    
    int first_element = arr[0];
    int last_index = -1;
    int i = size - 1;
    
    // Цикл while для поиска с конца массива
    while (i >= 0) {
        // Проверяем условия: нечетный И некратный первому элементу
        if (arr[i] % 2 != 0 && arr[i] % first_element != 0) {
            last_index = i;
            break;  // нашли последний подходящий элемент
        }
        i--;
    }
    
    return last_index;
}
