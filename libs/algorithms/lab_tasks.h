//
// Created by ivanu on 29.03.2024.
//

#ifndef LAB_16_LAB_TASKS_H
#define LAB_16_LAB_TASKS_H

#include "../data_structures/matrix/matrix.h"

//task 1
// меняет местами строки с максимальным и минимальным элементом
void swap_max_min_row_element(matrix *m);

//task 2
//возвращает максимальный элемент массива
int getMax(int *a, int n);

//упорядочивает строки матрицы по неубыванию наибольших элементов строк
void sortRowsByMinElement(matrix m);

//task 3
//выводит минимальный элемент матрицы
int getMin(int *a, int n);

//упорядочивает столбцы матрицы по неубыванию минимальных элементов столбцов
void sortColsByMinElement(matrix m);

//task 4
//умножает матрицы друг на друга
matrix  mulMatrices(matrix  m1,  matrix  m2);

//если матрица симметрична, то заменяет ее квадратом этой матрицы
void  getSquareOfMatrixIfSymmetric(matrix  *m);

#endif //LAB_16_LAB_TASKS_H
